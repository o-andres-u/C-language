/*
  Mi primer programa en C
  holamundo.c
*/

#include <stdio.h>

//variable global
char nombre[50];

int main() {
  printf("Ingrese su nombre por favor: ");
  scanf("%s", nombre);
  printf("Hola: %s\n", nombre);

  return 0;
}
