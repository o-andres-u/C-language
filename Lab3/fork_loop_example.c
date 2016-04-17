#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
  int i;
  int numHijos = 3;
  pid_t pid;

  for (i = 0; i < numHijos; i++) {
    pid = fork();
    if (pid == -1) {
      /* Error */
      printf("No fue posible crear un hijo\n");
      return -1;
    } else if (pid == 0) {
      printf("Soy el hijo #%d con PID: %d\n", i+1, getpid());
      printf("Saliending...\n");
      exit(0);
    }
  }

  while(wait(NULL) > 0);

  return 0;
}
