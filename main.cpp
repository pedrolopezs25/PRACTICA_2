#include <iostream>
#include "funciones.h"
using namespace std;

#include <iostream>
using namespace std;

void P11() {
    int filas = 15;
    int asientos = 20;
    int opcion = 0;

    // Reservar memoria para 15 x 20 = 300 asientos
    char *sala = new char[filas * asientos];

    // Inicializar todos los asientos como disponibles
    for (int i = 0; i < filas * asientos; i++) {
        *(sala + i) = '-';
    }
    while (opcion != 4) {
        cout << endl;
        cout << "1. Mostrar sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            for (int i = 0; i < filas; i++) {
                cout << char('A' + i) << " ";

                for (int j = 0; j < asientos; j++) {
                    cout << *(sala + i * asientos + j) << " ";
                }

                cout << endl;
            }
            break;

        case 2: {
            char letra;
            int numero;

            cout << "Fila (A-O): ";
            cin >> letra;

            cout << "Asiento (1-20): ";
            cin >> numero;

            int fila = letra - 'A';
            int asiento = numero - 1;

            if (fila < 0 || fila >= filas || asiento < 0 || asiento >= asientos ) {
                cout << "Asiento invalido" << endl;
            }
            else {
                char *pAsiento = sala + fila * asientos + asiento;
                cout << *pAsiento << " " << pAsiento << endl;
                if (*pAsiento == '+') {
                    cout << "El asiento ya esta reservado" << endl;
                }
                else {
                    *pAsiento = '+';
                    cout << "Reserva realizada" << endl;
                }
                break;
            }

            break;
        }

        case 3: {
            char letra;
            int numero;

            cout << "Fila (A-O): ";
            cin >> letra;

            cout << "Asiento (1-20): ";
            cin >> numero;

            int fila = letra - 'A';
            int asiento = numero - 1;

            if (fila < 0 || fila >= filas || asiento < 0 || asiento >= asientos) {
                cout << "Asiento invalido" << endl;
            }
            else {
                char *pAsiento = sala + fila * asientos + asiento;

                if (*pAsiento == '-') {
                    cout << "El asiento ya esta disponible" << endl;
                }
                else {
                    *pAsiento = '-';
                    cout << "Cancelacion realizada" << endl;
                }
            }

            break;
        }

        case 4:
            cout << "Saliendo" << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }

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

    default:
        cout << "Usted metio un ejercicio que no se ha hecho, nospi arrivederci"<< endl;

    }
    return 0;
}


