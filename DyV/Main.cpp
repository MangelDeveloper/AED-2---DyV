
#include <iostream>
#include "Controlador.h"
#include <cmath>

using namespace std;

int main() {
        int opcion = 0;
        cout << "1. Generador Inputs Aleatorios. " << endl;
        cout << "2. Test Oráculo. " << endl;
        cout << "3. Test Peor Caso." << endl;
        cout << "4. Test Mejor Caso." << endl;

        cout << "Escoge opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "Gerando Inputs en " << Controlador::INPUT_FILE << endl;
                Controlador::generar_datos_aleatorios();
                break;
            }
            case 2: {
                cout << "Haciendo Test Oráculo..." << endl;
                Controlador::test_oraculo();
                break;
            }
            case 3: {
                cout << "Generando Datos Peor Caso..." << endl << endl;
                Controlador::test_tiempo(true);
                break;
            }
            case 4: {
                cout << "Generando Datos Mejor Caso..." << endl  << endl;
                Controlador::test_tiempo(false);
                break;
            }
            default:
                cout << "Opcion no valida!" << endl;
        }
    return 0;
}
