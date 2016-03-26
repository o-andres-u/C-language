#include <stdio.h>
#include <stdlib.h>

//#define SIZE 3

void getData(float data[], int size);
void getDataPtr(float *data, int size);
void printData(float data[], int size);
void printDataPtr(float *data, int size);
float average(float *data, int size);
float averagePtr();

int main(int argc, char *argv[]){

	int size;
	//float numbers[SIZE];			//Static
	float *numbers;

  float avg;

	size = atoi(argv[1]);
	numbers = malloc(sizeof(float)*size);

	printf("%d", size);


	getDataPtr(numbers, size);
	printDataPtr(numbers, size);
  avg = averagePtr(numbers, size);

  printf("El promedio es: %f\n", avg);

	free(numbers);
	return 0;
}

void getData(float data[], int size){

	int i;
	printf("ingrese %d datos\n", size);
	for(i=0; i<size; i++){
		scanf("%f", &data[i]);
	}
}

void getDataPtr(float *data, int size){

	int i;
	printf("\ningrese %d datos\n", size);
	for(i=0; i<size; i++){
		scanf("%f", data+i);
	}
}


void printData(float data[], int size){

	int i;
	printf("Los datos son: \n");
	for(i=0; i<size; i++){
		printf("%.1f\n", data[i]);
	}
}

void printDataPtr(float *data, int size){

	int i;
	printf("Los datos son: \n");
	for(i=0; i<size; i++){
		printf("%.1f\n", *(data+i));
	}
}

float averagePtr(float *data, int size) {
  int i;
  float suma = 0;
  int counter = 0;
  for(i=0; i<size; i+=2) {
    counter++;
    suma += *(data+i);
  }
  return suma / counter;
}
