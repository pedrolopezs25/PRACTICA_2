#include <iostream>
#include "funciones.h"
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

    default:
        cout << "Usted metio un ejercicio que no se ha hecho, nospi arrivederci"<< endl;

    }
    return 0;
}


