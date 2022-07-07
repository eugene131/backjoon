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
int c[10002] = { 0 };
int* plusLazeInt(int a[],int b[],int n) {
	
	for (int i = 1; i < n; i++) {
		c[i] =c[i] + a[i] + b[i];
		if (c[i] >= 10) {
			c[i + 1]++;
			c[i] = c[i] % 10;
		}
	}
	return c;
}
void reversInt(int a[],int n) {
	int temp[10001];
	
	for (int i = 0; i < n; i++) {
		temp[i] = a[i];
	}
	for (int i = 1; i < n; i++) {
		a[i] = temp[n - i];
	}
}
int main() {
	int i, A[10001] = { 0 }, C[10001] = { 0 }, * dab;
	char B[10001],D[10001];
	int cuntA,cuntC;//자릿수 확인

	scanf("%s %s", B,D);
		for (i = 1; i < 10001; i++) {
			if (B[i-1] == '\0')
				break;
			
			A[i] = B[i-1] - '0';
		}
		cuntA = i;
		reversInt(A, cuntA);
		for (i = 1; i < 10001; i++) {
			if (D[i - 1] == '\0')
				break;
			C[i] = D[i-1] - '0';
		}
		cuntC = i;

		reversInt(C, cuntC);
		if (cuntA > cuntC) {

			dab = plusLazeInt(A, C, cuntA);
			if (dab[cuntA] != 0) {
				printf("%d", dab[cuntA]);
			}
			for (int j = cuntA-1; j >= 1; j--) {

				printf("%d", dab[j]);
			}
		}
		else {
			dab = plusLazeInt(A, C, cuntC);
			if (dab[cuntC] != 0) {
				printf("%d", dab[cuntC]);
			}
			for (int j = cuntC-1; j >= 1; j--) {
					printf("%d", dab[j]);
			}
			
		}
	return 0;

}

