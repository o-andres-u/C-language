#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 10

void obtenerNumeros(int *, int *);
int calcularDiferencia(int, int *);

int main() {
	int totalNumeros, diferencia;
	int *numerosEnMemoria;

	numerosEnMemoria = (int (*)) malloc(sizeof(int) * MAX_NUMEROS);

	obtenerNumeros(&totalNumeros, numerosEnMemoria);
	diferencia = calcularDiferencia(totalNumeros, numerosEnMemoria);

	free(numerosEnMemoria);

	printf("La diferencia de los numeros ingresados con 100 es %d\n", diferencia);
	return 0;
}

void obtenerNumeros(int *totalN, int *numEnMemoria) {
	int i = 0;

	printf("Cantidad de numeros a ingresar: ");
	setbuf(stdin, NULL);
	scanf("%d", totalN);

	for (i = 0; i < *totalN; i++) {
		printf("#%d: ", i+1);
		setbuf(stdin, NULL);
		scanf("%d", numEnMemoria+i);
	}
}

int calcularDiferencia(int totalN, int *numEnMemoria) {
	int i = 0, dif = 100;
	for (i = 0; i < totalN; i++) {
		dif -= *(numEnMemoria+i);
	}
	return dif;
}
