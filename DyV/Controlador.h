//
// Created by samuel on 13/3/26.
//

#ifndef INC_02_P1_CONTROLADOR_H
#define INC_02_P1_CONTROLADOR_H

#include "Algoritmo.h"
#include <unordered_set>
#include <fstream>

class Controlador {
private:
    static std::unordered_set<char> generar_conjunto_aleatorio();
    static std::string generar_permutacion(std::unordered_set<char> conjuntoReferencia);
    static std::string generar_cadena_aleatoria(int n, std::unordered_set<char> conjuntoReferencia);
    static std::unordered_set<char> leer_conjunto(std::ifstream & inFichero);
    static void mostrar_resultado(Algoritmo::Resultado & resultado, std::ofstream & outFichero);


public:
    static const std::string INPUT_FILE;
    static const std::string OUTPUT_FILE;

    static void generar_datos_aleatorios();
    static void test_oraculo();
    static void test_tiempo(bool peor);
};


#endif //INC_02_P1_CONTROLADOR_H