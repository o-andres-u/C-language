#include <stdio.h>

int numeroAleatorio;

int main() {
  printf("Ingrese un numero: ");
  scanf("%d", &numeroAleatorio);
  if (numeroAleatorio % 2 == 0) {
    printf("El numero %d es par\n", numeroAleatorio);
  } else {
    printf("El numero %d es impar\n", numeroAleatorio);
  }
}
