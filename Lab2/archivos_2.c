#include <stdio.h>
#include <stdlib.h>

int main() {
  char nombre[] = "My Name\n";
  char escaneo[50];
  char getS[1000];
  char put[12] = "Hello baby\n";

  FILE *in_file;

  in_file = fopen("input.txt", "a+");
  fprintf(in_file, "%s", nombre);

  rewind(in_file);
  fscanf(in_file, "%s", escaneo);
  printf("Lo que se leyó: %s\n", escaneo);

  rewind(in_file);
  fgets(getS, 50, in_file);
  printf("Con fgets: %s\n", getS);

  rewind(in_file);
  fputs(put, in_file);

  rewind(in_file);
  fputc('x', in_file);

  rewind(in_file);
  int charac= fgetc(in_file);
  printf("%c\n", charac);

  fclose(in_file);

  return 0;
}
