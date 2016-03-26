#include <stdio.h>

char nombres[3][10] = {"Maria", "Daniela", "Carla"};

void main() {
	char i;
	char *a;
	char (*b)[10];

	a = (char *) nombres;
	printf("El nombre es %s \n", a);

	b = (char (*)[10]) nombres[0];

	for (i = 0; i < 3; i++) {
		printf("El nombre[%d] es %s \n", i, (char *)(b + i));
	}
}
