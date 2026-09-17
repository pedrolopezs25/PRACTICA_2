#include <iostream>
using namespace std;
#include "funciones.h"

void P1(int cantidad){
    if (cantidad < 0){
        cout << "Error: La cantidad debe ser positiva." << endl;
        return;
    }
    int den[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int numden = 10;
    int restante = cantidad;

    const int *pden = den; //apunta a la primera direccion del arreglo


    for (int i = 0; i < numden; i++){
        int cantidadDenominacion = restante / *pden ;
        restante = restante % *pden;

        cout << *pden << " : " << cantidadDenominacion << endl;
        *pden++;
    }
    if (restante > 0){
        cout << "Faltante: " << restante << endl;
    }
}

bool compararCadenas(const char *cadena1, const char *cadena2) {

    while (*cadena1 != '\0' && *cadena2 != '\0') {
        if (*cadena1 != *cadena2) {
            return false;
        }
        cadena1++;
        cadena2++;
    }

    if (*cadena1 == '\0' && *cadena2 == '\0') {
        return true;
    }

    return false;
}

void P5(int numero, char (&cadena)[20])   {
    int copia = numero;
    int digitos = 0;

    while (copia > 0) {
        digitos++;
        copia = copia / 10;
    }

    //char *pCadena = cadena + digitos - 1;
    int posicion = digitos - 1;

    while (numero > 0) {
        cadena[posicion] = (numero % 10) + '0';
        numero = numero / 10;
        posicion--;
    }

    cadena[digitos] = '\0';
}

void P7(char cadena[]) {
    char *pLeer = cadena;
    char *pEscribir = cadena;

    while (*pLeer != '\0') {
        bool repetido = false;

        for (char *pRevisar = cadena; pRevisar < pEscribir; pRevisar++) {
            if (*pRevisar == *pLeer) {
                repetido = true;
                break;
            }
        }

        // Si no estaba repetido, se guarda en la nueva cadena
        if (repetido == false) {
            *pEscribir = *pLeer;
            pEscribir++;
        }

        pLeer++;
    }
    *pEscribir = '\0';
}

void P9() {
    int n;
    char cadena[100];

    cout << "Ingrese n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n debe ser mayor que cero" << endl;
        return;
    }

    cout << "Ingrese la cadena de numeros: ";
    cin >> cadena;

    char *pCadena = cadena;
    int longitud = 0;

    while (*pCadena != '\0') {
        longitud++;
        pCadena++;
    }
    pCadena = cadena + longitud - 1;
    int suma = 0;
    int numeroGrupo = 0;
    int posicion = 1;
    int contador = 0;

    while (pCadena >= cadena) {
        int digito = *pCadena - '0';

        numeroGrupo = numeroGrupo + digito * posicion;

        posicion = posicion * 10;
        contador++;

        if (contador == n) {
            suma = suma + numeroGrupo;
            cout << numeroGrupo << " + " ;
            numeroGrupo = 0;
            posicion = 1;
            contador = 0;
        }

        pCadena--;
    }
    //no ha llegado a cero la cantidad de n pero necesito sumar
    if (contador > 0) {
        suma = suma + numeroGrupo;
        cout << numeroGrupo ;
    }
    cout <<" = " << suma <<endl;
    cout << "Original: " << cadena << endl;
    cout << "Suma: " << suma << endl;
}

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

int P13(int *matriz, int filas, int columnas) {
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
                cout << "estrella en: " << posicion << endl;
                estrellas++;
            }
        }
    }

    return estrellas;
}
bool seCruzan(int *A, int *B) {
    int izquierdaA = A[0];
    int arribaA = A[1];
    int derechaA = A[0] + A[2];
    int abajoA = A[1] + A[3];

    int izquierdaB = B[0];
    int arribaB = B[1];
    int derechaB = B[0] + B[2];
    int abajoB = B[1] + B[3];

    if (derechaA <= izquierdaB) {
        return false;
    }
    if (derechaB <= izquierdaA) {
        return false;
    }
    if (abajoA <= arribaB) {
        return false;
    }
    if (abajoB <= arribaA) {
        return false;
    }

    return true;
}
void calcularC(int *A, int *B, int *C) {
    if (A[0] > B[0]) {
        C[0] = A[0];
    }
    else {
        C[0] = B[0];
    }

    if (A[1] > B[1]) {
        C[1] = A[1];
    }
    else {
        C[1] = B[1];
    }

    int derechaA = A[0] + A[2];
    int derechaB = B[0] + B[2];
    int derechaC;

    if (derechaA < derechaB) {
        derechaC = derechaA;
    }
    else {
        derechaC = derechaB;
    }

    int abajoA = A[1] + A[3];
    int abajoB = B[1] + B[3];
    int abajoC;

    if (abajoA < abajoB) {
        abajoC = abajoA;
    }
    else {
        abajoC = abajoB;
    }
    C[2] = derechaC - C[0];
    C[3] = abajoC - C[1];
}

int sumaDivisores(int numero) {
    int suma = 0;

    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            suma = suma + i;
        }
    }

    return suma;
}
bool sonAmigables(int a, int b) {
    if (a == b) {
        cout << " a debe ser diferente de b" << endl;
        return false;
    }

    if (sumaDivisores(a) == b && sumaDivisores(b) == a) {
        return true;
    }
    else {
        return false;
    }
}
int P17(int limite) {
    int sumaTotal = 0;
    bool encontroPareja = false;

    cout << "Parejas amigables menores que "
         << limite << ":" << endl;

    for (int a = 2; a < limite; a++) {
        int b = sumaDivisores(a);

        if (a < b && b < limite && sonAmigables(a, b)) {
            cout << a << " y " << b
                 << " son amigables." << endl;

            cout << "Suma de divisores de " << a
                 << ": " << sumaDivisores(a) << endl;

            cout << "Suma de divisores de " << b
                 << ": " << sumaDivisores(b) << endl;

            cout << endl;

            sumaTotal = sumaTotal + a + b;
            encontroPareja = true;
        }
    }

    if (!encontroPareja) {
        cout << "No se encontraron parejas amigables." << endl;
    }
    return sumaTotal;
}
