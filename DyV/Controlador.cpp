

#include "Controlador.h"
#include <cmath>
#include <chrono>
#include <ctime>

#define TAM_CONJUNTO 5

using namespace std;
using namespace std::chrono;

const string Controlador::INPUT_FILE = "./inputTest.txt";;
const string Controlador::OUTPUT_FILE = "./outputTest.txt";

unordered_set<char> Controlador::leer_conjunto(ifstream & inFichero) {
    unordered_set<char> char_set;
    char c;
    for (int i = 0; i < TAM_CONJUNTO-1; i++)
    {
        inFichero >> c;
        char_set.insert(c);
    }
    inFichero >> c;
    char_set.insert(c);

    inFichero.ignore();
    return char_set;
}

void Controlador::mostrar_resultado(Algoritmo::Resultado & resultado, ofstream & outFichero) {
    outFichero << "   Num subcadenas: " << resultado.num_subcadenas << endl;
    outFichero << "   Posiciones: ";
    for (int pos : resultado.arr_posiciones)
        outFichero << pos << " ";
    outFichero << endl;
}

unordered_set<char> Controlador::generar_conjunto_aleatorio() {
    srand(time(nullptr)); // semilla con la hora actual
    unordered_set<char> conjunto;

    int i = 0;
    while (i < TAM_CONJUNTO) {
        char letra = rand()%('z'-'a' + 1) + 'a'; // generar entre 'a' y 'z'
        if (!conjunto.contains(letra)) {
            conjunto.insert(letra);
            i++;
        }
    }

    return conjunto;
}

string Controlador::generar_permutacion(unordered_set<char> conjunto) {
    unordered_set<int> posiciones;
    char conjunto_aleatorio [] = {0,0,0,0,0};

    for (char letra : conjunto) {
        int posicion = rand()%TAM_CONJUNTO;
        while (posiciones.contains(posicion)) {
            posicion = rand()%TAM_CONJUNTO;
        }
        conjunto_aleatorio[posicion] = letra;
        posiciones.insert(posicion);
    }


    string permutacion(conjunto_aleatorio, 5);
    return permutacion;
}

string Controlador::generar_cadena_aleatoria(int n, unordered_set<char> referencia) {
     // semilla con la hora actual
    string cadena = "";
    int i = 0;
    while (i < n) {
        string sumar = "";
        if (rand()%3 == 1 && (n-i)>TAM_CONJUNTO) {
            sumar = generar_permutacion(referencia);
            i += 5;
        }else {
            sumar = rand()%('z'-'a' + 1) + 'a'; // generar entre 'a' y 'z'
            i++;
        }
        cadena+=sumar;
    }
    return cadena;
}

void Controlador::generar_datos_aleatorios() {
    srand(time(nullptr));
    ofstream outFichero (INPUT_FILE);

    unordered_set<char> conjunto = generar_conjunto_aleatorio();

    int longitudes [] = {5, 10, 20, 50, 100, 1000};
    for (int longitud : longitudes) {
        string cadena = generar_cadena_aleatoria(longitud,conjunto);
        outFichero << cadena << endl;

        for (char c : conjunto) {
            outFichero << c;
        }
        outFichero << endl;
    }
    outFichero.close();
}

void Controlador::test_oraculo() {
    ifstream inFichero (INPUT_FILE);
    ofstream outFichero (OUTPUT_FILE);

    string cadena;
    while (inFichero >> cadena) {
        outFichero << "Entrada: '" << cadena << "'" << endl;
        outFichero << "Tamaño entrada: '" << cadena.size() << "'" << endl;
        unordered_set<char> conjunto = leer_conjunto(inFichero);
        outFichero << "Conjunto: { ";
        for (char c : conjunto) {
            outFichero << c << " ";
        }
        outFichero << "}" << endl;

        Algoritmo::Resultado oraculo = Algoritmo::iterativo(conjunto,cadena,0,cadena.size()-1);
        Algoritmo::Resultado resultado = Algoritmo::divide_y_venceras(conjunto,cadena,0,cadena.size()-1);

        outFichero << "Salida esperada (Iterativo):" << endl;
        mostrar_resultado(oraculo,outFichero);

        outFichero << "Resultado (DyV):" << endl;
        mostrar_resultado(resultado,outFichero);

        outFichero << endl;
    }
    inFichero.close();
    outFichero.close();
}

void Controlador::test_tiempo(bool peor) {
    ofstream outFichero (OUTPUT_FILE);
    outFichero << "i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10" << endl;
    cout << "Terminado encabecado." << endl;

    unordered_set<char> conjunto;
    const char conjuntoReferencia [] = {'a','b','c','d','e'};
    for (int i = 0; i < TAM_CONJUNTO; i++) {
        conjunto.insert(conjuntoReferencia[i]);
    }

    for (int fila = 0; fila < 11; fila++) {
        for (int col = 0; col < 11; col++) {
            string cadena = "";
            int tamEntrada  = 1000*pow(2,col);
            if (peor) {
                //El peor caso es que la cadena n-4 subcadenas que
                //cumplan la condicion de tener todas las letras del
                //conjunto. Ya que tiene que ir realizando el merge de los resultados.
                int letraConjunto = 0;
                for (int z = 0; z < tamEntrada; z++) {
                    cadena += conjuntoReferencia[letraConjunto];
                    letraConjunto = (letraConjunto+1)%TAM_CONJUNTO;
                }
                
            }else {
                //El mejor caso es que la cadena nunca cumpla la condición.
                //Ya que al hacer el merge de los resultados no tiene que hacer nada.
                for (int z = 0; z < tamEntrada; z++) {
                    cadena += 'z';
                }
            }

            //Simulamos y medimos los tiempos de ejecución.
            auto empezar = steady_clock::now();
            Algoritmo::Resultado resultado = Algoritmo::divide_y_venceras(conjunto,cadena,0,cadena.size()-1);
            auto terminar = steady_clock::now();
            auto duracion = duration_cast<microseconds>(terminar - empezar);

            //Obtenemos los datos en microsegundos.
            outFichero << duracion.count();

            //Cerramos fila.
            if (col != 10) {
                outFichero  << ",";
            }else {
                outFichero << endl;
            }
        }
        cout << "Terminado fila " << fila << "." << endl;
    }
        outFichero.close();
}

