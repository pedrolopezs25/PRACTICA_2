#include <iostream>
using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void fun_c(double *a, int n, double *promedio, double *suma);

int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *k=array;
    cout << *(k+3) << " " <<sizeof(array[0])<< endl;
    fun_b(array, 10);
}
void fun_a(int *px, int *py){
    int tmp=*px;
    *py=tmp;
    cout << *py <<" "<< py<< endl;
}
void fun_b(int a[], int tam){
    int f, l;
    int *b=a;
    for(f=0,l=tam -1; f<1; f++, l-- ){
        fun_a(&b[f], &b[l]);

    }
    cout << *b <<" "<< b<<" "<<&b[l]<< endl;
}

