#include <stdio.h>
#include <stdlib.h>

int main() {
	int *edad;
	
	edad = (int *) malloc(sizeof(int));

	printf("Edad en anios: ");
	setbuf(stdin, NULL);
	scanf("%d", edad);

	printf("Usted tiene %d meses de vida\n", (*edad) * 12);
	free(edad);

	return 0;
}
