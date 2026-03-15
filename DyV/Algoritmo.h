
#ifndef INC_02_P1_ALGORITMO_H
#define INC_02_P1_ALGORITMO_H

#include <iostream>
#include <vector>
#include <unordered_set>



class Algoritmo {
public:
    struct Resultado {
        int num_subcadenas = 0;
        std::vector<int> arr_posiciones;
    };

    static Resultado divide_y_venceras(const std::unordered_set<char> conjunto, const std::string & cadena, int inicio, int final);
    static Resultado iterativo(const std::unordered_set<char> conjunto, const std::string & cadena, int inicio, int final);

private:
    static Resultado merge(Resultado izq, Resultado der,const std::unordered_set<char> & conjunto, const std::string & cadena, int indexMitad);


};


#endif //INC_02_P1_ALGORITMO_H