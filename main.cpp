#include <iostream>
using namespace std;

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

        }

    case 5:
        while(true){

        }

    case 7:
        while(true){

        }

    case 9:
        while(true){

        }

    default:
        cout << "Usted metio un ejercicio que no se ha hecho, nospi arrivederci"<< endl;

    }
    return 0;
}


