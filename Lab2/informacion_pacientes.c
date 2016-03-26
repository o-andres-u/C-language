#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARACT_LINEA 50
#define MAX_CARACT_NOMBRE 20

typedef struct {
  char nombre[MAX_CARACT_NOMBRE];
  int edad;
  float estatura;
} paciente;

//Definición de funciones
int obtenerTotalPacientes(FILE *);
void leerPacientes(FILE *, paciente *);
void imprimirPacientesPorEdad(paciente *, FILE *);
void imprimirPacientesPorEstatura(paciente *, FILE *);
int compararEdades(const void *, const void *);
int compararEstatura(const void *, const void *);

//Variables globales
int totalPacientes = 0;

int main() {
  FILE *archivoOrigen;
  FILE *archivoPacientesEdad;
  FILE *archivoPacientesEstatura;
  paciente *pacientes;

  archivoOrigen = fopen("pacientes.txt", "r");
  if (archivoOrigen == NULL) {
    perror("No se pudo abrir el archivo de origen\n");
  }

  archivoPacientesEdad = fopen("pacientesPorEdad.txt", "a");
  archivoPacientesEstatura = fopen("pacientesPorEstatura.txt", "a");

  totalPacientes = obtenerTotalPacientes(archivoOrigen);
  if (totalPacientes <= 0) {
    printf("No hay pacientes en el archivo\n");
    exit(0);
  }
  printf("Hay %d pacientes\n", totalPacientes);

  pacientes = (paciente *) malloc(sizeof(paciente) * totalPacientes);
  leerPacientes(archivoOrigen, pacientes);
  imprimirPacientesPorEstatura(pacientes, archivoPacientesEstatura);
  imprimirPacientesPorEdad(pacientes, archivoPacientesEdad);

  fclose(archivoOrigen);
  fclose(archivoPacientesEdad);
  fclose(archivoPacientesEstatura);

  free(pacientes);
  return 0;
}

// Obtiene el total de los pacientes en el archivo
int obtenerTotalPacientes(FILE *archivo) {
  int totalPacientes = 0;
  char buffer[MAX_CARACT_LINEA];
  while (!feof(archivo)) {
    fgets(buffer, MAX_CARACT_LINEA, archivo);
    totalPacientes++;
  }
  rewind(archivo);

  return totalPacientes - 1;
}

// Lee los pacientes que están en el archivo
void leerPacientes(FILE *archivoOrigen, paciente *pacientes) {
  int i;
  char buffer[MAX_CARACT_LINEA];
  char *token;
  for (i = 0; i < totalPacientes; i++) {
    fgets(buffer, MAX_CARACT_LINEA, archivoOrigen);
    token = strtok(buffer, ";");
    while (token != NULL) {
      strcpy(pacientes->nombre, token);
      token = strtok(NULL, ";");
      pacientes->edad = atoi(token);
      token = strtok(NULL, ";");
      pacientes->estatura = atof(token);
      token = strtok(NULL, ";");
    }
    pacientes++;
  }
}

void imprimirPacientesPorEdad(paciente *pacientes, FILE *archivoPacientesEdad) {
  int i;
  qsort(pacientes, totalPacientes, sizeof(paciente), compararEdades);
  for (i = 0; i < totalPacientes; i++) {
    fprintf(archivoPacientesEdad, "%s; %d; %f\n", pacientes->nombre, pacientes->edad, pacientes->estatura);
    pacientes++;
  }
}

void imprimirPacientesPorEstatura(paciente *pacientes, FILE *archivoPacientesEstatura) {
  int i;
  qsort(pacientes, totalPacientes, sizeof(paciente), compararEstatura);
  for (i = 0; i < totalPacientes; i++) {
    fprintf(archivoPacientesEstatura, "%s; %d; %f\n", pacientes->nombre, pacientes->edad, pacientes->estatura);
    pacientes++;
  }
}

int compararEdades(const void *s1, const void *s2) {
  paciente *paciente1 = (paciente *) s1;
  paciente *paciente2 = (paciente *) s2;
  return paciente2->edad - paciente1->edad;
}

int compararEstatura(const void *s1, const void *s2) {
  paciente *paciente1 = (paciente *) s1;
  paciente *paciente2 = (paciente *) s2;
  if (paciente1->estatura < paciente2->estatura) {
    return -1;
  } else if (paciente1->estatura == paciente2->estatura) {
    return 0;
  } else {
    return 1;
  }
}
