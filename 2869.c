//2-1번 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(p,s)\
if (!((p) = malloc(s))){\
	printf("error");\
	fprintf(stderr, "Insufficient memory");\
	exit(EXIT_FAILURE);\
}
#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)
#define MAX_SIZE 100



int main() {
	int A, B, V, V1, i, output;
	scanf("%d %d %d", &A, &B, &V);
	
	V1 = V - A;
	output=V1 / (A - B);
	output++;
	if (V1 % (A - B) != 0)
		output++;
	printf("%d", output);
	return 0;

}

