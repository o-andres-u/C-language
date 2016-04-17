#include <stdio.h>

typedef struct {
  int parteReal;
  int parteImaginaria;
} numeroComplejo;

numeroComplejo sumarComplejos(numeroComplejo, numeroComplejo);
numeroComplejo restarComplejos(numeroComplejo, numeroComplejo);
numeroComplejo multiplicarComplejos(numeroComplejo, numeroComplejo);

int main() {
  numeroComplejo a, b, c;

  printf("Ingrese el primer número complejo\n");
  printf("Parte real: ");
  setbuf(stdin, NULL);
  scanf("%d", &a.parteReal);
  printf("Parte imaginaria: ");
  setbuf(stdin, NULL);
  scanf("%d", &a.parteImaginaria);

  printf("Ingrese el segundo número complejo\n");
  printf("Parte real: ");
  setbuf(stdin, NULL);
  scanf("%d", &b.parteReal);
  printf("Parte imaginaria: ");
  setbuf(stdin, NULL);
  scanf("%d", &b.parteImaginaria);

  c = sumarComplejos(a, b);
  printf("Suma: %d + (%di)\n", c.parteReal, c.parteImaginaria);

  c = restarComplejos(a, b);
  printf("Resta: %d + (%di)\n", c.parteReal, c.parteImaginaria);

  c = multiplicarComplejos(a, b);
  printf("Multiplicación: %d + (%di)\n", c.parteReal, c.parteImaginaria);

  return 0;
}

numeroComplejo sumarComplejos(numeroComplejo complejo1, numeroComplejo complejo2) {
  numeroComplejo suma;
  suma.parteReal = complejo1.parteReal + complejo2.parteReal;
  suma.parteImaginaria = complejo1.parteImaginaria + complejo2.parteImaginaria;

  return suma;
}

numeroComplejo restarComplejos(numeroComplejo complejo1, numeroComplejo complejo2) {
  numeroComplejo resta;
  resta.parteReal = complejo1.parteReal - complejo2.parteReal;
  resta.parteImaginaria = complejo1.parteImaginaria - complejo2.parteImaginaria;

  return resta;
}

numeroComplejo multiplicarComplejos(numeroComplejo complejo1, numeroComplejo complejo2) {
  numeroComplejo resultado;
  resultado.parteReal = (complejo1.parteReal * complejo2.parteReal) - (complejo1.parteImaginaria * complejo2.parteImaginaria);
  resultado.parteImaginaria = (complejo1.parteReal * complejo2.parteImaginaria) + (complejo1.parteImaginaria * complejo2.parteReal);

  return resultado;
}
