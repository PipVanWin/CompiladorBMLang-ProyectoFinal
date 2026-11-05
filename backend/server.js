
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

// Middlewares
app.use(cors());
app.use(express.json({ limit: '1mb' }));

// Ubicación del compilador en C
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

        // 1. Guardar código fuente
        await fs.writeFile(archivoFuente, codigo, 'utf8');

        // 2. Generar NASM
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

        // 3. Ensamblar
        await ejecutarArchivo(
            NASM,
            ['-f', 'elf32', archivoASM, '-o', archivoObjeto],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024
            }
        );

        // 4. Generar ejecutable
        await ejecutarArchivo(
            LINKER,
            ['-m', 'elf_i386', archivoObjeto, '-o', archivoEjecutable],
            {
                timeout: 10000,
                maxBuffer: 1024 * 1024
            }
        );

        return {
            success: true,
            message: 'Ejecutable generado correctamente.',
            nasm: resultadoNASM.stdout
        };

    } finally {

        if (directorioTemporal) {

            await fs.rm(directorioTemporal, {
                recursive: true,
                force: true
            });

        }

    }

}


// Ruta principal
app.get('/', (req, res) => {
    res.json({
        mensaje: 'Backend de BMLang funcionando correctamente'
    });
});

// Endpoint para compilar código
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

// Iniciar servidor
app.listen(PORT, () => {
    console.log(`Servidor BMLang ejecutándose en http://localhost:${PORT}`);
});

