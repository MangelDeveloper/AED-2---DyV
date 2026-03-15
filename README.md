# AED2 - Divide y Vencerás - Samuel Espín Santos y Miguel Ángel Tornel Martínez

Dada una cadena A con n caracteres y un conjunto S de 5 caracteres distintos, devolver
todas las subcadenas de A formadas por los 5 elementos de S sin repetir (permutaciones
sin repetición). Habrá que obtener el número de subcadenas y su posición en la cadena A.

 - Entrada: A (Cadena) y S (Conjunto)
 - Salida: Subcadenas válidas y en que posiciones
 - Ejemplo:
    • Entrada:
        ◦ A = acbfabcedfcbcbadec
        ◦ S = {a, b, c, d, e}
    • Salida: 3 subcadenas válidas en las posiciones 5,13,14 (Empezando desde 1)

## Implementación

- `Algoritmo.h`, `Algoritmo.cpp`: Estos ficheros contienen las cabeceras y las implementaciones de los algoritmos propuestos.
- `inputTest.txt`: Contiene las entradas utilizadas en cada test unitario.
- `outputTest.txt`: Almacena las salidas generadas por cada test unitario.
- `Controlador.cpp` y `Controlador.h`: Estos ficheros se encargan de generar datos aleatorios, como cadenas y conjuntos de caracteres, así como de realizar test oráculo y medir tiempos de ejecución.
- `EstudioAlgoritmo.R`: El código de este fichero se encarga de generar gráficas a partir de los tiempos y de hacer los ajustes de regresión.
- `tiempoMejor.txt`: Contiene los tiempos de ejecución del algoritmo en el mejor caso, para que el fichero EstudioAlgoritmo.R pueda generar la gráfica
correspondiente.
- `tiempoPeor.txt`: Contiene los tiempos de ejecución del algoritmo en el peor caso, para que el fichero EstudioAlgoritmo.R pueda generar la gráfica co-
rrespondiente.
- `Makefile`: Este fichero se encarga de como debe compilar el proyecto.