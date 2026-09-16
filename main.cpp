#include <iostream>
#include "funciones.h"
using namespace std;

#include <iostream>
using namespace std;



int contarEstrellas(int *matriz, int filas, int columnas) {
    int estrellas = 0;

    // No se revisan los bordes
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {

            int posicion = i * columnas + j;

            int suma = *(matriz + posicion)
                       + *(matriz + posicion - 1)
                       + *(matriz + posicion + 1)
                       + *(matriz + posicion - columnas)
                       + *(matriz + posicion + columnas);

            if (suma > 30) {
                estrellas++;
            }
        }
    }

    return estrellas;
}

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
                {2, 6, 2, 7, 3, 0, 10, 0},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {5, 17, 7, 12, 6, 9, 10, 4},
                {5, 2, 6, 10, 6, 4, 8, 0}
            };

            int resultado = contarEstrellas(*matriz, 6, 8);

            cout << "Numero de estrellas: " << resultado << endl;
            return 0;
        }

    default:
        cout << "Usted metio un ejercicio que no se ha hecho, nospi arrivederci"<< endl;

    }
    return 0;
}


