#include <stdio.h>

typedef {
  char name[40];
  int numStudent;
  float grade;
} student;

student student1 = {"Fulano", 5, 2.1};
student *ptrStudent;

ptrStudent = &student1;

printf("%s", ptrStudent->name);
printf("%d", ptrStudent->numStudent);
printf("%f", ptrStudent->grade);
