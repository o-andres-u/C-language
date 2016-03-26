#include <stdio.h>
#include <string.h>

struct estudiante {
  char nombre[40];
  int numEstudiante;
  int agnoMatricula;
  float nota;
};

// Imprime los datos de la estructura por medio de sí misma y de un puntero
void imprimirEstructura(struct estudiante, struct estudiante *);

// Actualiza la estructura con datos diferentes utilizando el puntero
void actualizarEstructura(struct estudiante *);

// Define los datos de la estructura y los imprime
int main() {
  int caracter;
  struct estudiante student1 = {"Pablo", 4, 2002, 4.8};
  struct estudiante *ptrStudent1 = &student1;
  imprimirEstructura(student1, ptrStudent1);

  caracter = getchar();
  if (caracter == 'r') {
    actualizarEstructura(ptrStudent1);
    imprimirEstructura(student1, ptrStudent1);
  }
  return 0;
}

void imprimirEstructura(struct estudiante student1, struct estudiante *ptrStudent1) {
  printf("Nombre del estudiante: %s (con apuntador)\n", ptrStudent1->nombre);
  printf("Número del estudiante: %d (con apuntador)\n", ptrStudent1->numEstudiante);
  printf("Año de su matrícula: %d (con apuntador)\n", ptrStudent1->agnoMatricula);
  printf("Nota del estudiante: %f (con apuntador)\n", ptrStudent1->nota);
  printf("******************************************\n");
  printf("Nombre del estudiante: %s (sin apuntador)\n", student1.nombre);
  printf("Número del estudiante: %d (sin apuntador)\n", student1.numEstudiante);
  printf("Año de su matrícula: %d (sin apuntador)\n", student1.agnoMatricula);
  printf("Nota del estudiante: %f (sin apuntador)\n", student1.nota);
}

void actualizarEstructura(struct estudiante *ptrStudent1) {
  strcpy(ptrStudent1->nombre, "Pedro");
  ptrStudent1->numEstudiante = 19;
  ptrStudent1->agnoMatricula = 2010;
  ptrStudent1->nota = 3.1;
}
