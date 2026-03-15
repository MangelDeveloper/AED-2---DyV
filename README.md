# AED2 - Divide y Vencerás  
**Samuel Espín Santos y Miguel Ángel Tornel Martínez**

Dada una cadena **A** con *n* caracteres y un conjunto **S** de 5 caracteres distintos, devolver todas las subcadenas de **A** formadas por los 5 elementos de **S** sin repetir (permutaciones sin repetición). Además, se debe obtener el número de subcadenas y la posición en la que empiezan dentro de la cadena **A**.

## Descripción del problema

- **Entrada:**  
  - `A` → Cadena de caracteres  
  - `S` → Conjunto de 5 caracteres distintos

- **Salida:**  
  - Número de subcadenas válidas  
  - Posiciones donde comienzan dichas subcadenas
- **Ejemplo**
  - Entrada:
        - A = acbfabcedfcbcbadec
        - S = {a, b, c, d, e}
  - Salida:
        - 3 subcadenas válidas en las posiciones 5, 13 y 14 (empezando desde 1)


## Implementación
El proyecto contiene los siguientes archivos:

- **Algoritmo.h**, **Algoritmo.cpp**  
  Contienen las cabeceras y la implementación de los algoritmos propuestos.
- **Controlador.cpp**, **Controlador.h**  
  Se encargan de generar datos aleatorios, como cadenas y conjuntos de caracteres, además de realizar test oráculo y medir tiempos de ejecución.
- **inputTest.txt**  
  Contiene las entradas utilizadas en los tests unitarios.
- **outputTest.txt**  
  Almacena las salidas generadas por cada test unitario.
- **EstudioAlgoritmo.R**  
  Script en R que genera gráficas a partir de los tiempos obtenidos y realiza los ajustes de regresión.
- **tiempoMejor.txt**  
  Contiene los tiempos de ejecución del algoritmo en el mejor caso.
- **tiempoPeor.txt**  
  Contiene los tiempos de ejecución del algoritmo en el peor caso.
- **Makefile**  
  Define cómo compilar el proyecto.