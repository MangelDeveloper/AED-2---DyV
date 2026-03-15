
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
    //A cada caracter le asociamos una frecuencia
    unordered_map<char,int> letra_contador;
    //Historial de 5 últimos caracteres
    queue<char> historial;
    //Contador de cuantos caracteres que pertenecen al conjunto tienen frecuencia 1
    int coincidencias = 0;
    Resultado resultado;


    for (int i = inicio; i <= final; i++) {
        //Obtenemos la letra de la posición i
        char letra = cadena.at(i);
        historial.push(letra);

        //Si la letra está en el conjunto
        if (conjunto.contains(letra)) {
            //Incrementamos su contador
            letra_contador[letra] += 1;

            //Si tenía frecuencia 1 incrementamos coincidencias
            if (letra_contador [letra] == 1)
                coincidencias++;
        }

        //Si el historial es más grande que el tamaño del conjunto
        //debemos sacar el caracter más antigui
        if (historial.size() > TAM_CONJUNTO) {
            //Sacamos el caracter más antiguo
            char letraSale = historial.front();
            historial.pop();

            //Si estaba en el conjunto decrementamos
            if (conjunto.contains(letraSale)) {
                letra_contador [letraSale] -= 1;

                //Si pasa a tener frecuencia 0 decrementamos coincidencias
                if (letra_contador [letraSale]==0)
                    coincidencias--;
            }
        }

        //Si coincidencias es igual que el tamaño del conjunto significa
        //que tenemos 1 caracter del conjunto de cada en el historial
        if (coincidencias == TAM_CONJUNTO) {
            //Se ha detectado una nueva subcadena válida
            resultado.num_subcadenas++;
            //Guardamos su posición inicial
            resultado.arr_posiciones.push_back(i-TAM_CONJUNTO+2);
        }
    }
    return resultado;
}

//Suma el número de subcadenas de izquierda,centro y derecha, además inserta las posiciones iniciales de manera ordenada
Algoritmo::Resultado Algoritmo::merge(Resultado izq, Resultado der,const unordered_set<char> & conjunto, const string & cadena, int indexMitad) {
    Resultado centro = iterativo(conjunto,cadena,indexMitad-4,indexMitad+3);

    izq.num_subcadenas += der.num_subcadenas + centro.num_subcadenas;
    izq.arr_posiciones.insert(izq.arr_posiciones.end(), centro.arr_posiciones.begin(), centro.arr_posiciones.end());
    izq.arr_posiciones.insert(izq.arr_posiciones.end(), der.arr_posiciones.begin(), der.arr_posiciones.end());

    return izq;
}

//DYV
Algoritmo::Resultado Algoritmo::divide_y_venceras(const std::unordered_set<char> conjunto, const string & cadena, int inicio, int final) {
    int longitud = final-inicio+1;
    //Caso base 1
    if (longitud < 5)
        return {0,vector<int>()};
    //Caso base 2
    if (longitud <= 8)
        return iterativo(conjunto, cadena,inicio,final);

    //Dividir
    int indexMitad = inicio + (longitud / 2);

    //Vencer
    Resultado resIzq = divide_y_venceras(conjunto,cadena, inicio,indexMitad-1);
    Resultado resDer = divide_y_venceras(conjunto,cadena,indexMitad,final);

    //Combinar
    return merge(resIzq,resDer,conjunto,cadena,indexMitad);
}
