#include <stdio.h>

main() {
  char primerNombre;
  float notaObtenida;
  printf("Por favor ingrese su primer nombre\n");
  scanf("%s", &primerNombre);
  printf("Por favor ingrese la nota obtenida\n");
  scanf("%f", &notaObtenida);

  printf("Nombre: %-5s\n", &primerNombre);
  printf("Nota: %f\n", &notaObtenida);
}
