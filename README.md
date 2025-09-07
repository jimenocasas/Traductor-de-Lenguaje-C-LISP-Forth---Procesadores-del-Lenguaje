# Traductor de Lenguaje C → LISP → Forth

## Descripción
Proyecto desarrollado en la asignatura Procesadores del Lenguaje (UC3M).  
Se implementa un traductor dividido en dos fases:

- Frontend: Traducción de un subconjunto del lenguaje C a código intermedio en LISP.  
- Backend: Conversión del código LISP a notación Postfix (Forth), ejecutable en intérpretes como GForth.

Este proyecto simula el flujo clásico de un compilador, incluyendo análisis léxico, análisis sintáctico/semántico y generación de código.

## Funcionalidades principales
- Traducción de programas en C con:
  - Declaración de variables globales/locales y vectores
  - Funciones (con y sin parámetros)
  - Estructuras de control: if, while, for
  - Expresiones aritméticas, lógicas y comparativas
  - Instrucciones de impresión (puts, printf)
- Generación de código ejecutable en Forth.  
- Manejo de errores léxicos, sintácticos y semánticos, con recuperación de parsing.

## Tecnologías y Herramientas
- Lenguaje de implementación: C  
- Análisis léxico y sintáctico: Flex (Lex) y Bison (Yacc)  
- Representaciones intermedias: Árboles de sintaxis abstracta (AST)  
- Gestión de variables: Tablas de símbolos, ámbitos globales/locales  
- Lenguajes de destino:  
  - LISP (prefijo, funcional, representación intermedia)  
  - Forth (postfijo, basado en pila)

## Estructura del Proyecto
- `trad.y` → Frontend (C → LISP)  
- `back.y` → Backend (LISP → Forth)  
- `tests/` → Conjunto de programas de prueba en C  
- `doc/` → Memoria y documentación técnica  

## Ejecución
Ejemplos de uso:

```bash
# Generar código Lisp desde C
./trad < programa.c

# Traducir C directamente a Forth
./trad < programa.c | ./back

# Ejecutar en intérprete GForth
./trad < programa.c | ./back | gforth
