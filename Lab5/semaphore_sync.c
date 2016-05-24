#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUMTHREADS 3

sem_t synch_1_2;
sem_t synch_2_3;

void *s1(void *arg);
void *s2(void *arg);
void *s3(void *arg);

int main() {
  int i;
  pthread_t tid[NUMTHREADS];

  sem_init(&synch_1_2, 0, 0);
  sem_init(&synch_2_3, 0, 0);

  pthread_create(&tid[0], NULL, &s3, NULL);
  pthread_create(&tid[1], NULL, &s2, NULL);
  pthread_create(&tid[2], NULL, &s1, NULL);

  for(i = 0; i < NUMTHREADS; i++) {
    pthread_join(tid[i], NULL);
  }

  sem_destroy(&synch_1_2);
  sem_destroy(&synch_2_3);

  printf("\nDone !!\n");
  return 0;
}

void *s1(void *arg) {
  printf("\nS1 Executing...\n");
  sem_post(&synch_1_2); // Aumenta en 1 para que el otro proceso siga

  return 0;
}

void *s2(void *arg) {
  sem_wait(&synch_1_2); // Manda a dormir porque la inicialización está en cero
  printf("\nS2 Executing...\n");
  sem_post(&synch_2_3);

  return 0;
}

void *s3(void *arg) {
  sem_wait(&synch_2_3);
  printf("\nS3 Executing...\n");

  return 0;
}
