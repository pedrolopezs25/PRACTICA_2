#ifndef FUNCIONES_H
#define FUNCIONES_H

void P1(int cantidad);

bool compararCadenas(const char *cadena1, const char *cadena2);

void P5(int numero, char (&cadena)[20]);

void P7(char cadena[]);

void P9();
void P11();

int P13(int *matriz, int filas, int columnas);
bool seCruzan(int *A, int *B);
void calcularC(int *A, int *B, int *C);

int sumaDivisores(int numero);
bool sonAmigables(int a, int b);
int P17(int limite);

#endif // FUNCIONES_H
