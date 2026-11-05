
const express = require('express');
const cors = require('cors');
const path = require('path');
const os = require('os');
const fs = require('fs/promises');
const { execFile } = require('child_process');
const { promisify } = require('util');

const ejecutarArchivo = promisify(execFile);

const app = express();
const PORT = 3000;


app.use(cors());
app.use(express.json({ limit: '1mb' }));


const COMPILADOR = path.resolve(__dirname, '..', 'compilador');
const NASM = 'nasm';
const LINKER = 'ld';

async function generarEjecutable(codigo) {
    let directorioTemporal;

    try {

        directorioTemporal = await fs.mkdtemp(
            path.join(os.tmpdir(), 'bmlang-build-')
        );

        const archivoFuente = path.join(
            directorioTemporal,
            'programa.bml'
        );

        const archivoASM = path.join(
            directorioTemporal,
            'programa.asm'
        );

        const archivoObjeto = path.join(
            directorioTemporal,
            'programa.o'
        );

        const archivoEjecutable = path.join(
            directorioTemporal,
            'programa'
        );

       
        await fs.writeFile(archivoFuente, codigo, 'utf8');

        
        const resultadoNASM = await ejecutarArchivo(
            COMPILADOR,
            [archivoFuente, '--nasm'],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024,
                encoding: 'utf8'
            }
        );

        await fs.writeFile(
            archivoASM,
            resultadoNASM.stdout,
            'utf8'
        );

       
        await ejecutarArchivo(
            NASM,
            [
                '-f',
                'elf32',
                archivoASM,
                '-o',
                archivoObjeto
            ],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024
            }
        );

        
        await ejecutarArchivo(
            LINKER,
            [
                '-m',
                'elf_i386',
                archivoObjeto,
                '-o',
                archivoEjecutable
            ],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024
            }
        );

        
        return {
            success: true,
            message: 'Ejecutable generado correctamente.',
            nasm: resultadoNASM.stdout,
            directorioTemporal,
            archivoEjecutable
        };

    } catch (error) {

       
        if (directorioTemporal) {
            await fs.rm(directorioTemporal, {
                recursive: true,
                force: true
            });
        }

        throw error;
    }
}



app.get('/', (req, res) => {
    res.json({
        mensaje: 'Backend de BMLang funcionando correctamente'
    });
});


app.post('/api/compile', async (req, res) => {
    const { code, mode = 'tac' } = req.body;

    if (typeof code !== 'string' || code.trim() === '') {
        return res.status(400).json({
            success: false,
            message: 'No se recibió código BMLang'
        });
    }

    if (!['tac', 'ast','nasm'].includes(mode)) {
        return res.status(400).json({
            success: false,
            message: 'Modo de compilación no válido'
        });
    }

    let directorioTemporal;

    try {
        directorioTemporal = await fs.mkdtemp(
            path.join(os.tmpdir(), 'bmlang-')
        );

        const archivoFuente = path.join(
            directorioTemporal,
            'programa.bml'
        );

        await fs.writeFile(archivoFuente, code, 'utf8');

        const { stdout, stderr } = await ejecutarArchivo(
            COMPILADOR,
            [archivoFuente, `--${mode}`],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024,
                encoding: 'utf8'
            }
        );

        res.json({
            success: true,
            output: stdout,
            errors: stderr
        });

    } catch (error) {
        res.status(422).json({
            success: false,
            output: error.stdout || '',
            errors: error.stderr || '',
            message: error.message
        });

    } finally {
        if (directorioTemporal) {
            await fs.rm(directorioTemporal, {
                recursive: true,
                force: true
            });
        }
    }
});



app.post('/api/build', async (req, res) => {

    const { code } = req.body;

    if (typeof code !== 'string' || code.trim() === '') {

        return res.status(400).json({
            success: false,
            message: 'No se recibió código BMLang.'
        });

    }

    try {

        const resultado = await generarEjecutable(code);

        res.json(resultado);

    } catch (error) {

        res.status(422).json({
            success: false,
            message: error.message,
            errors: error.stderr || ''
        });

    }

});

app.post('/api/run', async (req, res) => {

    const { code } = req.body;

    if (typeof code !== 'string' || code.trim() === '') {
        return res.status(400).json({
            success: false,
            message: 'No se recibió código BMLang.'
        });
    }

    let resultado;

    try {

       
        resultado = await generarEjecutable(code);

console.log("Resultado de generarEjecutable:", resultado);

if (
    !resultado ||
    typeof resultado.archivoEjecutable !== 'string'
) {
    throw new Error(
        'No se recibió una ruta válida del ejecutable.'
    );
}

const ejecucion = await ejecutarArchivo(
    resultado.archivoEjecutable,
    [],
    {
        timeout: 5000,
        maxBuffer: 1024 * 1024,
        encoding: 'utf8'
    }
);
        

        res.json({
            success: true,
            output: ejecucion.stdout,
            errors: ejecucion.stderr
        });

    } catch (error) {

        res.status(422).json({
            success: false,
            output: error.stdout || '',
            errors: error.stderr || '',
            message: error.killed
                ? 'El programa superó el tiempo máximo de ejecución.'
                : error.message
        });

    } finally {

       
        if (resultado?.directorioTemporal) {
            await fs.rm(resultado.directorioTemporal, {
                recursive: true,
                force: true
            });
        }
    }
});


app.listen(PORT, () => {
    console.log(`Servidor BMLang ejecutándose en http://localhost:${PORT}`);
});

