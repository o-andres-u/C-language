#include <stdio.h>

/* Declaracion de funciones (prototipos). */
void swap(int *d1, int *d2); // Referencias con apuntadores.

int main(void) {
	int x = 1;
	int y = 2;
	int *p = &y;

	printf("Valor de x: %d\n", x);
	printf("Valor de y: %d\n", *p);

	swap(&x, p);	// Paso por referencia con '&'

	printf("Valor de x: %d\n", x);
	printf("Valor de y: %d\n", *p);

	return 0;
}

/* Definicion de funciones. */
void swap(int *d1, int *d2) { // Referencias con apuntadores.
	int temporal;
	temporal = *d1;
	*d1 = *d2;
	*d2 = temporal;
}
