#include <stdio.h>
#include <stdlib.h>

#define PARAMETROS 3

FILE *archivoOrigen = NULL;
FILE *archivoDestino = NULL;

int main(int totalParametros, char *parametros[]) {
  int caracter;
  if (totalParametros != PARAMETROS) {
    printf("Error ingresando los parámetros\n");
    exit(-1);
  }

  archivoOrigen = fopen(parametros[1], "r");
  if (archivoOrigen == NULL) {
    printf("No se pudo abrir el archivo origen %s\n", parametros[1]);
    exit(0);
  }
  archivoDestino = fopen(parametros[2], "w");

  caracter = fgetc(archivoOrigen);
  while(caracter != EOF) {
    fputc(caracter, archivoDestino);
    caracter = fgetc(archivoOrigen);
  }

  fclose(archivoOrigen);
  fclose(archivoDestino);

  return 0;
}
