#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int pid;
  int numHijos = 5;
  int numProceso;

  for (numProceso = 0; numProceso < numHijos; numProceso++) {
    pid = fork();
    if (pid == -1) {
      printf("Algún mensaje de error\n");
    } else if (pid == 0) {
      break;
    }
  }

  if (pid == 0) {
    // Lógica del hilo
    printf("Soy el hijo #%d\n", numProceso);
  } else {
    printf("Soy un padre perezoso\n");
  }

  return 0;

}
