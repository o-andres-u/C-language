#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100

float calcularPromedio(int, int[]);

int main(void) {

  int arreglo[MAX_NUMEROS];
  int numero = 0;
  int i;
  float promedio;

  for (i = 0; i < MAX_NUMEROS; i++) {
    numero = rand() % 100;
    arreglo[i] = numero;
  }

  promedio = calcularPromedio(MAX_NUMEROS, arreglo);
  printf("El promedio es %f\n", promedio);

  return 0;
}

float calcularPromedio(int total, int numeros[]) {
  int i;
  int suma = 0;
  for(i = 0; i < total; i++) {
    suma += numeros[i];
    printf("%d\n", suma);
  }
  return suma / total;
}
