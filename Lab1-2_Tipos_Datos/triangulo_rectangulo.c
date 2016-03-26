#include <stdio.h>

double base;
double altura;

main() {
  printf("Ingrese la base del triangulo rectangulo: ");
  scanf("%d", &base);
  printf("Ingrese la altura del triangulo rectangulo: ");
  scanf("%d", &altura);

  double area = (base * altura) / 2;
  printf("El area del triangulo de base %d cm y altura %d cm es de %d cm2\n", base, altura, area);

  double perimetro = sqrt((base * base) + (altura * altura));
  printf("El perimetro del triangulo de base %d cm y altura %d cm es de %d cm2\n", base, altura, perimetro);
}
