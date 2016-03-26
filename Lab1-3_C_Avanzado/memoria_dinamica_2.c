#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_NOMBRE 10

int main() {
	char (*nombre)[MAX_CHAR_NOMBRE];
	nombre = (char (*)[MAX_CHAR_NOMBRE]) malloc(sizeof(char[MAX_CHAR_NOMBRE]));

	printf("Nombre: ");
	setbuf(stdin, NULL);
	scanf("%s", nombre);

	printf("Hasta luego %s\n", nombre);

	

	return 0;
}
