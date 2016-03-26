#include <stdio.h>

void main() {
	int A[6] = {2, 3, 1, 0, 9, 6};
	int *ptr1;
	int *ptr2 = &A[5];
	int i;
	ptr1 = A;
	ptr1 += 2;
	*ptr1 = 5;
	ptr2--;
	*(ptr2) = *ptr1 + *(ptr2-1) + *(ptr2+1);

	for (i = 0; i < 6; i++) {
		printf("%d\n", A[i]);
	}
}
