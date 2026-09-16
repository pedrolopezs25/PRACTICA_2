#include <iostream>
#include "funciones.h"
using namespace std;

#include <iostream>
using namespace std;

int main(){
    int x,a,b,c=0;

    cout <<"ingrese el numero del problema x:"<< endl;
    cin >> x;

    switch(x){
    case 1:
        while(true){
            cout << "ingrese la cantindad" << endl;
            cin >> a;
            P1(a);
        }
        break;

    case 3:
        while(true){
            char cadena1[100];
            char cadena2[100];

            cout << "Ingrese la primera cadena: " << endl;
            cin >> cadena1; //getline me reserva una posicion para añadir final de trama(error: preguntar)

            cout << "Ingrese la segunda cadena: " << endl;
            cin >> cadena2;

            if (compararCadenas(cadena1, cadena2)) {
                cout << "Las cadenas son iguales" << endl;
            }
            else {
                cout << "Las cadenas son diferentes" << endl;
            }
        }

    case 5:
        while(true){
            int numero;
            char cadena[12]; //int 2147483647 maximo 10 bits

            cout << "Ingrese un numero mayor que cero: ";
            cin >> numero;

            if (numero <= 0) {
                cout << "El numero debe ser mayor que cero" << endl;
            }
            else {
                P5(numero, cadena);

                cout << "La cadena es: " << cadena << endl;
            }
        }

    case 7:
        while(true){
            char cadena[100];
            cout << "Ingrese una cadena: ";
            cin >> cadena;
            cout << "Original: " << cadena << endl;
            P7(cadena);
            cout << "Sin repetidos: " << cadena << endl;
        }

    case 9:
        while(true){
            P9();
        }

    case 11:
        while(true){
            P11();
            return 0;
        }
    case 13:
        while(true){
            int matriz[6][8] = {
                {0, 3, 4, 0, 0, 0, 6, 8},
                {5, 13, 6, 0, 0, 2, 3, 0},
                {2, 6, 2, 7, 3, 3, 10, 9},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {5, 0, 7, 2, 6, 9, 10, 4},
                {5, 2, 6, 10, 6, 4, 8, 0}
            };

            int resultado = P13(*matriz, 6, 8);

            cout << "Numero de estrellas: " << resultado << endl;
            return 0;
        }
    case 15:
        while(true){
            int A[4];
            int B[4];
            int C[4];

            cout << "RECTANGULO A" << endl;
            cout << "Ingrese x: ";
            cin >> A[0];

            cout << "Ingrese y: ";
            cin >> A[1];

            cout << "Ingrese ancho: ";
            cin >> A[2];

            cout << "Ingrese alto: ";
            cin >> A[3];

            cout << endl;

            cout << "RECTANGULO B" << endl;
            cout << "Ingrese x: ";
            cin >> B[0];

            cout << "Ingrese y: ";
            cin >> B[1];

            cout << "Ingrese ancho: ";
            cin >> B[2];

            cout << "Ingrese alto: ";
            cin >> B[3];

            if (seCruzan(A, B)) {
                calcularC(A, B, C);

                cout << endl;
                cout << "Los rectangulos si se cruzan." << endl;
                cout << "Rectangulo C = { ";

                for (int i = 0; i < 4; i++) {
                    cout << C[i];
                    if (i < 3) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;
            }
            else {
                cout << endl;
                cout << "Los rectangulos no se cruzan." << endl;
            }
        }

    default:
        cout << "Usted metio un ejercicio que no se ha hecho, nospi arrivederci"<< endl;

    }
    return 0;
}


