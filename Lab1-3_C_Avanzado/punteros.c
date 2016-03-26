#include <stdio.h>

int main(void) {

	int i;
	int num1;
	int num2;
	int num3;
	int *ptr;

	printf("Ingrese primer número: ");
	setbuf(stdin, NULL);
	scanf("%d", &num1);

	printf("Ingrese segundo número: ");
	setbuf(stdin, NULL);
	scanf("%d", &num2);

	printf("Ingrese tercer número: ");
	setbuf(stdin, NULL);
	scanf("%d", &num3);

	ptr = &num1;
	printf("Primer número: %d\n", *ptr);
	printf("Segundo número: %d\n", *(ptr-1));
	printf("Tercer número: %d\n", *(ptr-2));

	return 0;

}
