[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/GnhO2tyV)
[![Work in MakeCode](https://classroom.github.com/assets/work-in-make-code-8824cc13a1a3f34ffcd245c82f0ae96fdae6b7d554b6539aec3a03a70825519c.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23936404&assignment_repo_type=AssignmentRepo)
# Proyecto — Conversión de Expresiones Infijas a Postfijas

## Descripción

En este proyecto se implementará un sistema capaz de:

- Leer expresiones algebraicas desde un archivo.
- Convertir expresiones de notación infija a notación postfija.
- Evaluar expresiones postfijas.

El objetivo principal es aplicar estructuras de datos dinámicas utilizando:

- Pilas
- Colas

además de trabajar con:

- precedencia de operadores
- análisis de expresiones
- lectura de archivos
- evaluación algebraica

## Objetivos

El sistema deberá:

- Leer variables desde un archivo.
- Leer una expresión infija.
- Convertir la expresión a notación postfija.
- Evaluar la expresión postfija.
- Mostrar el resultado final.

## Estructura del proyecto
```
.
├── include/
│   ├── pila.h
│   ├── cola.h
│   ├── parser.h
│   └── evaluator.h
│
├── student/
│   ├── pila.c
│   ├── cola.c
│   ├── parser.c
│   ├── evaluator.c
│   └── main.c
│
├── input/
│   └── caso1.txt
│
├── docs/
│   └── reporte.pdf
│
├── tests/
│   └── test_runner.c
│
├── .github/
│   └── workflows/
│       └── autograding.yml
│
└── README.md

```

## Archivos que debe modificar el estudiante

El estudiante debe trabajar únicamente dentro de:

```
src/
```
y agregar su reporte dentro de 
```
docs/
```

Archivos que NO deben modificarse

No deben modificarse:

```
include/
tests/
.github/
```

Modificar dichos archivos puede provocar:

- errores de compilación
- fallos en la autocalificación
- pérdida de puntos


## Formato del archivo de entrada

Ejemplo:
```
a = 5
b = 3
c = 2

(a+b)*c
```

## Reglas del archivo
- Cada variable ocupa una línea.
- Las variables son de un solo carácter.
- La expresión aparece al final.
- El archivo puede contener espacios.

## Operadores soportados

El sistema debe soportar:
```
+
-
*
/
^
()
```

## Ejemplo de salida
Expresion infija:
```
(a+b)*c
```
Expresion postfija:
```
a b + c *
```

Resultado:
```
16
```

## Restricciones importantes
### Uso obligatorio de pila

La pila debe utilizarse para:

- conversión infija → postfija
- evaluación postfija

### Uso obligatorio de cola

La cola debe utilizarse para:

- almacenar la expresión postfija


## Restricciones técnicas
### NO permitido
- usar arreglos para simular pilas
- usar arreglos para simular colas
- usar eval
- usar bibliotecas externas de parsing

## Permitido

Se permite utilizar:

```
strtok()
```

únicamente para:

- separar variables
- separar valores del archivo

No debe utilizarse para resolver la conversión infija a postfija.

## Trabajo escrito obligatorio

Además de la implementación, cada estudiante deberá entregar un reporte escrito en formato PDF.

El archivo deberá colocarse en:

```
docs/reporte.pdf
```
## Contenido mínimo del reporte

El reporte debe incluir:

### Introducción

Descripción general del problema(No del programa) y objetivo del proyecto.

### Explicación de estructuras utilizadas

Explicar:

- implementación de pila
- implementación de cola
- uso de memoria dinámica

### Algoritmo de conversión

Explicar:

- precedencia
- asociatividad
- funcionamiento del algoritmo infija → postfija

### Evaluación postfija

Explicar cómo se evalúa la expresión usando pilas.

### Casos de prueba

Incluir ejemplos utilizados para validar el programa.

### Conclusiones

Reflexión sobre:

- dificultades encontradas
- decisiones de diseño
- aprendizaje obtenido

## Compilación

```
gcc \
src/*.c \
-Iinclude \
-lm \
-o programa
```

## Ejecución
```
./programa
```

## Casos importantes que debe soportar
### Precedencia

Entrada:
```
a+b*c
```
Salida postfija:
```
a b c * +
```
### Paréntesis

Entrada:
```
(a+b)*c
```

Salida:
```
a b + c *
```

### Potencia

Entrada:
```
a^b^c
```
Salida esperada:
```
a b c ^ ^
```

## Evaluación automática

El proyecto será evaluado automáticamente mediante GitHub Actions.

Cada push ejecutará:

- compilación automática
- pruebas automáticas
- validación de resultados

## Recomendaciones
- Implementar primero la pila.
- Implementar después la cola.
- Verificar precedencia cuidadosamente.
- Probar expresiones simples antes de casos complejos.
- Validar memoria dinámica.

## Entrega

La entrega se realiza mediante commits y pushes al repositorio asignado en GitHub Classroom.
