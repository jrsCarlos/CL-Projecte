# CL - Compilador ASL

## Descripción general

El objetivo es construir un compilador para un lenguaje imperativo simplificado llamado **ASL** (A Simple Language) que produzca código intermedio de tres direcciones (3-address code) para luego ejecutarlo sobre una máquina virtual personalizada llamada **tVM**.

Las etapas principales del compilador son:

1. **Definición de la gramática de ASL** usando ANTLR4.
2. **Análisis semántico / comprobaciones de tipos** sobre el AST generado.
3. **Generación de código** en un lenguaje de bajo nivel (t-code) compatible con tVM.
4. **Ejecución en la máquina virtual tVM** que interpreta el código generado.
5. Se trabaja incrementalmente, añadiendo características gradualmente conforme se superan pruebas intermedias.

## Ficheros clave:

* `Asl.g4` — la gramática ANTLR para ASL
* `CodeGenVisitor.cpp` — parte del generador de código
* `SymbolsVisitor.cpp` — gestión de tablas de símbolos
* `TypeCheckVisitor.cpp` — verificación de tipos

## Estructura del proyecto

Aquí una vista general de los componentes importantes:

```
CL-Projecte/
├── asl/
│   ├── Asl.g4
│   ├── CodeGenVisitor.cpp
│   ├── SymbolsVisitor.cpp
│   ├── TypeCheckVisitor.cpp
│   └── … otros auxiliares
├── tvm/  ← simulador / interpretador de t-code
├── modules/  ← módulos auxiliares suministrados (administración de errores, tipo, tablas, etc.)
├── steps/  ← ejemplos progresivos / casos de prueba en ASL
├── Makefile / scripts de compilación
└── README.md
```

## Características implementadas y pendientes

Este proyecto se organiza de forma incremental. La versión base suele venir con soporte mínimo (por ejemplo, sólo asignaciones simples y sumas), y la tarea es expandir el compilador con más funcionalidades.

Algunas de las extensiones añadidas son:

* Operaciones aritméticas adicionales (multiplicación, división, resta)
* Estructuras de control (if, while, for)
* Bloques de sentencias / alcance léxico
* Funciones (declaración, llamada, manejo de parámetros)
* Gestión de arrays / vectores
* Conversión automática / coerción de tipos
* Control de errores semánticos (variables no declaradas, incompatibilidad de tipos, redeclaraciones)
* Optimización sencilla del código generado
* Soporte avanzado en tVM para nuevas instrucciones

## Módulos clave en el repositorio `asl/`

Estos archivos son de especial importancia:

* **Asl.g4**: definición de la gramática del lenguaje ASL.
* **TypeCheckVisitor.cpp**: recorre el árbol sintáctico para verificar tipos, detectar errores semánticos.
* **SymbolsVisitor.cpp**: construcción de la tabla de símbolos, control de declaraciones, ámbitos.
* **CodeGenVisitor.cpp**: generación de código (instrucciones de tres direcciones) para el backend tVM.



