#include <stdio.h>

int main() {
  int numero;
  int contador = 0;
  int suma = 0;
  int numeroPequeno = 1000;
  int numeroMayor = 0;

  do {
    printf("Ingrese número: ");
    scanf("%d", &numero);
    if (numeroPequeno > numero) {
      numeroPequeno = numero;
    }
    if (numeroMayor < numero) {
      numeroMayor = numero;
    }
    suma = suma + numero;
    contador++;
  } while(contador < 5);

  printf("Números ingresados %d\n", contador++);
  printf("Número mas pequeño %d\n", numeroPequeno);
  printf("%21s", "Número más grande ");
  printf("%d\n", numeroMayor);
  printf("%19s", "Promedio ");
  printf("%d\n", suma / 5);
}
