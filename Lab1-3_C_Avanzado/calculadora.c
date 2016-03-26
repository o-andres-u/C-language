#include <stdio.h>
#include <stdlib.h>

void obtenerOpcionSeleccionada(char *);
void solicitarOperandos(float *, float *);
float procesarOperacion(char *, float, float);
void registrarHistorial(float, char, float, float);

int main(void) {
  char opcionSeleccionada;
  float num1;
  float num2;
  float resultado;
  char (*historialOperaciones)[12];
  do {
    obtenerOpcionSeleccionada(&opcionSeleccionada);
    solicitarOperandos(&num1, &num2);
    resultado = procesarOperacion(&opcionSeleccionada, num1, num2);
    registrarHistorial(num1, opcionSeleccionada, num2, resultado);
  } while (1);

}

void obtenerOpcionSeleccionada(char *opcion) {
  printf("MENU\n");
  printf("1. Suma\n");
  printf("2. Resta\n");
  printf("3. Multiplicación\n");
  printf("4. División\n");
  printf("Seleccione una opción: ");
  setbuf(stdin, NULL);
  scanf("%s", opcion);

  if (*opcion == 'q') {
    exit(EXIT_SUCCESS);
  }
}

void solicitarOperandos(float *num1, float *num2) {
  printf("Ingrese el primer operando: ");
  setbuf(stdin, NULL);
  scanf("%f", num1);

  printf("Ingrese el segundo operando: ");
  setbuf(stdin, NULL);
  scanf("%f", num2);
}

float procesarOperacion(char *operacion, float num1, float num2) {
  float resultado = 0;
  if (*operacion == '1') {
    resultado = num1 + num2;
    *operacion = '+';
  } else if (*operacion == '2') {
    resultado = num1 - num2;
    *operacion = '-';
  } else if (*operacion == '3') {
    resultado = num1 * num2;
    *operacion = '*';
  } else if (*operacion == '4') {
    resultado = num1 / num2;
    *operacion = '/';
  } else {
    printf("Operación inválida\n");
  }

  return resultado;
}

void registrarHistorial(float num1, char operacion, float num2, float resultado) {

}
