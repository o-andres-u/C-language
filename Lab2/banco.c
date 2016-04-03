#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *nombre;
  int numeroCuenta;
  float montoApertura;
} cuentaAhorro;

void obtenerInformacion(cuentaAhorro *);
void determinarTipo(float);
void mostrarInformacion(cuentaAhorro *);

void main() {
  cuentaAhorro *ahorrador;
  ahorrador = (cuentaAhorro *) malloc(sizeof(cuentaAhorro) * 10);
  obtenerInformacion(ahorrador);
  mostrarInformacion(ahorrador);

  free(ahorrador);
}

void obtenerInformacion(cuentaAhorro *ahorrador) {
  printf("Ingrese nombre del ahorrador: ");
  setbuf(stdin, NULL);
  scanf(" %s", &ahorrador->nombre);

  printf("Ingrese número de la cuenta: ");
  setbuf(stdin, NULL);
  scanf(" %d", &ahorrador->numeroCuenta);

  printf("Ingrese monto para abrir la cuenta: ");
  setbuf(stdin, NULL);
  scanf(" %f", &ahorrador->montoApertura);
}

void determinarTipo(float monto) {
  printf("El cliente es tipo: ");
  if (monto < 100000) {
    printf("MiniAhorrador\n");
  } else if (monto > 200000) {
    printf("PreferencialProX\n");
  } else {
    printf("Ahorregular\n");
  }
}

void mostrarInformacion(cuentaAhorro *cuenta) {
  printf("|%10s|%10s|%10s|\n", "Nombre", "Cuenta", "Apertura");
  printf("|%10s|%10d|%10.2f|\n", &cuenta->nombre, cuenta->numeroCuenta, cuenta->montoApertura);
  determinarTipo(cuenta->montoApertura);
}
