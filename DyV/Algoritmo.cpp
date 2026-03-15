
#include "Algoritmo.h"
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;



Algoritmo::Resultado Algoritmo::iterativo(const unordered_set<char> conjunto, const string & cadena, int inicio, int final) {
    const int TAM_CONJUNTO = conjunto.size();
    int longitud = final-inicio+1;

    //Caso base.
    if (longitud < TAM_CONJUNTO) return {};

    //------ Resto de casos.
    unordered_map<char,int> letra_contador; //{'a','b','c','d','e'}
    queue<char> historial;
    int coincidencias = 0;
    Resultado resultado;

    for (int i = inicio; i <= final; i++) {
        char letra = cadena.at(i);
        historial.push(letra);

        if (conjunto.contains(letra)) {
            letra_contador[letra] += 1;

            if (letra_contador [letra] == 1)
                coincidencias++;
        }

        if (historial.size() > TAM_CONJUNTO) {
            char letraSale = historial.front();
            historial.pop();

            if (conjunto.contains(letraSale)) {
                letra_contador [letraSale] -= 1;

                if (letra_contador [letraSale]==0)
                    coincidencias--;
            }
        }

        if (coincidencias == TAM_CONJUNTO) {
            resultado.num_subcadenas++;
            resultado.arr_posiciones.push_back(i-TAM_CONJUNTO+2);
        }
    }
    return resultado;
}

Algoritmo::Resultado Algoritmo::merge(Resultado izq, Resultado der, Resultado centro) {
    izq.num_subcadenas += der.num_subcadenas + centro.num_subcadenas;
    izq.arr_posiciones.insert(izq.arr_posiciones.end(), centro.arr_posiciones.begin(), centro.arr_posiciones.end());
    izq.arr_posiciones.insert(izq.arr_posiciones.end(), der.arr_posiciones.begin(), der.arr_posiciones.end());

    return izq;
}


Algoritmo::Resultado Algoritmo::divide_y_venceras(const std::unordered_set<char> conjunto, const string & cadena, int inicio, int final) {
    int longitud = final-inicio+1;
    if (longitud < 5)
        return {0,vector<int>()};

    if (longitud <= 8)
        return iterativo(conjunto, cadena,inicio,final);

    int indexMitad = inicio + (longitud / 2);
    Resultado resIzq = divide_y_venceras(conjunto,cadena, inicio,indexMitad-1);
    Resultado resDer = divide_y_venceras(conjunto,cadena,indexMitad,final);
    Resultado resCentro = iterativo(conjunto,cadena,indexMitad-4,indexMitad+3);

    Resultado d = merge(resIzq,resDer,resCentro);
    return d;
}
