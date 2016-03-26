#include <stdio.h>
#include <stdlib.h>

#define PARAMETROS 5

// Punto en el plano cartesiano
struct punto {
  int x;
  int y;
};

// Rectángulo que se compone por dos puntos del plano cartesiano
typedef struct {
  struct punto punto1;
  struct punto punto2;
} rectangulo;

//Definición de la función que calcula el área
int calcularAreaRectangulo(rectangulo *);

int main(int cantidadParametros, char *parametros[]) {
  int x;
  int y;
  struct punto primerPunto;
  struct punto segundoPunto;
  rectangulo *figuraRectangulo;
  int  areaRectangulo;
  if (cantidadParametros != PARAMETROS) {
    printf("Error ingresando los parámetros\n");
    exit(-1);
  }

  x = atoi(parametros[1]);
  y = atoi(parametros[2]);
  primerPunto.x = abs(x);
  primerPunto.y = abs(y);

  x = atoi(parametros[3]);
  y = atoi(parametros[4]);
  segundoPunto.x = abs(x);
  segundoPunto.y = abs(y);

  figuraRectangulo->punto1 = primerPunto;
  figuraRectangulo->punto2 = segundoPunto;

  areaRectangulo = calcularAreaRectangulo(figuraRectangulo);
  printf("El área del rectángulo es: %d\n", areaRectangulo);

  return (0);
}

// Calcula el área de un rectángulo basándose en sus puntos del plano cartesiano
int calcularAreaRectangulo(rectangulo *figura) {
  int base = 0;
  int altura = 0;

  struct punto primerPunto = figura->punto1;
  struct punto segundoPunto = figura->punto2;

  base = segundoPunto.x - primerPunto.x;
  altura = segundoPunto.y - primerPunto.y;

  return (base * altura);
}
