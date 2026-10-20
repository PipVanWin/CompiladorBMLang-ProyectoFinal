# CompiladorBMLang-ProyectoFinal
Un compilador para el lenguaje BMLang, genera código de tres direcciones y código assembler NASM con un IDE implementado.


ast. es como se acordó en cómo se vería un nodo del árbol 

Cuando el .y crea un nodo y luego el código de Marcos lo lee para generar el código de 3 direcciones, los dos tienen que saber cómo es un nodo, que campos tiene y de cóomo se lleman.
Se incluye el archivo ast.h para definir la estructura y cómo se va a manejar

enum TipoNodo
Es la lista de clases de nodo. Cada nombre (N_IF, N_NUMERO...) es una constante, y sirve de etiqueta para saber qué es cada nodo

struct Nodo
Es la caja que representa un nodo. Todos los nodos son del mismo tipo de caja, y cada tipo usa solo los campos que necesita
