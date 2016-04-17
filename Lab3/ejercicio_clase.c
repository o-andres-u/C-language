#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
  int a;
  int b;
  int i;
  int suma = 0;
  int numeroOperaciones = 4;
  int resta;
  int multiplicacion;
  int division;
  int retorno;
  pid_t procesoSuma, procesoResta, procesoMultiplicacion, procesoDivision;

  printf("Por favor ingrese dos números\n");
  scanf("%d", &a);
  scanf("%d", &b);

  procesoSuma = fork();
  if (procesoSuma == 0) {
    suma = a + b;
    exit(suma);
  } else {
    procesoResta = fork();
    if (procesoResta == 0) {
      resta = a - b;
      exit(resta);
    } else {
      procesoMultiplicacion = fork();
      if (procesoMultiplicacion == 0) {
        multiplicacion = a * b;
        exit(multiplicacion);
      } else {
        procesoDivision = fork();
        if (procesoDivision == 0) {
          division = a / b;
          exit(division);
        } else {
          for (i = 0; i < numeroOperaciones; i++) {
            int process = wait(&retorno);
            if (process == procesoSuma) {
              printf("Suma terminada: %d\n", WEXITSTATUS(retorno));
            } else if (process == procesoResta ) {
              printf("Resta terminada: %d\n", WEXITSTATUS(retorno));
            } else if (process == procesoMultiplicacion) {
              printf("Multiplicación terminada: %d\n", WEXITSTATUS(retorno));
            } else if (process == procesoDivision) {
              printf("División terminada: %d\n", WEXITSTATUS(retorno));
            }
          }
        }
      }
    }
  }

  return 0;
}
