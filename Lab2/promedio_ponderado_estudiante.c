#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Máximo de caracteres que puede tener una línea y el nombre de la materia
#define MAX_CARACT_LINEA 20
#define MAX_CARACT_NOMBRE 20

//Estructura para la materia
typedef struct {
  char materia[MAX_CARACT_NOMBRE];
  float nota;
  int creditos;
} materia;

//Definición de funciones
int obtenerTotalMaterias(FILE *);
void leerMaterias(FILE *, materia *);
void imprimirMateriasFormato(materia *, FILE *);

//Variables globales
FILE *archivo = NULL;
FILE *archivoDestino = NULL;
int totalMaterias = 0;

int main() {
  materia *materias;

  archivo = fopen("materias.txt", "r");
  if (archivo == NULL) {
    perror("No se pudo abrir el archivo\n");
  }
  archivoDestino = fopen("salida.txt", "w");
  if (archivoDestino == NULL) {
    perror("No se pudo abrir el archivo destino");
  }

  totalMaterias = obtenerTotalMaterias(archivo);
  if (totalMaterias <= 0) {
    printf("No hay materias en el archivo\n");
    exit(0);
  }
  printf("Total materias %d\n", totalMaterias);
  // Se solicita memoria
  materias = (materia *) malloc(sizeof(materia) * totalMaterias);
  leerMaterias(archivo, materias);
  imprimirMateriasFormato(materias, archivoDestino);

  fclose(archivo);
  fclose(archivoDestino);
  free(materias);
  return 0;
}

// Obtiene el número total de materias en el archivo
int obtenerTotalMaterias(FILE *archivo) {
  int totalMaterias = 0;
  char buffer[MAX_CARACT_LINEA];
  while (!feof(archivo)) {
    fgets(buffer, MAX_CARACT_LINEA, archivo);
    totalMaterias++;
  }
  rewind(archivo);
  return totalMaterias / 3;
}

// Lee las materias del archivo y las almacena en la estructura
void leerMaterias(FILE *archivo, materia *materias) {
  int i;
  char buffer[MAX_CARACT_LINEA];
  char *token;
  for (i = 0; i < totalMaterias; i++) {
    fgets(buffer, MAX_CARACT_LINEA, archivo);
    token = strtok(buffer, "\n");
    strcpy(materias->materia, token);
    fgets(buffer, MAX_CARACT_LINEA, archivo);
    materias->nota = atof(buffer);
    fgets(buffer, MAX_CARACT_LINEA, archivo);
    materias->creditos = atoi(buffer);
    materias++;
  }
}

// Imprime las materias ganadas, perdidas y el promedio ponderado
void imprimirMateriasFormato(materia *materias, FILE *archivoDestino) {
  int i;
  int materiasGanadas = 0;
  float sumatoriaNota = 0;
  int sumatoriaCreditos = 0;
  fprintf(archivoDestino, "|%-20s|%-12s|%-13s|\n", "Materia", "Nota", "Créditos");
  for (i = 0; i < totalMaterias; i++) {
    fprintf(archivoDestino, "|%-20s|%-12.2f|%-12d|\n", materias->materia, materias->nota, materias->creditos);
    if (materias->nota >= 3.0) {
      materiasGanadas++;
    }
    sumatoriaNota += materias->nota * materias->creditos;
    sumatoriaCreditos += materias->creditos;
    materias++;
  }

  fprintf(archivoDestino, "Total de materias: %d\n", totalMaterias);
  fprintf(archivoDestino, "Materias ganadas: %d\n", materiasGanadas);
  fprintf(archivoDestino, "Materias perdidas: %d\n", totalMaterias - materiasGanadas);
  fprintf(archivoDestino, "Promedio ponderado: %f\n", sumatoriaNota / sumatoriaCreditos);
}
