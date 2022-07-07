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
#define TRUE 1
#define FALSE 0

int main() {
	int N;
	int i, j, cunt = 0,check;
	int a[100];//주어지는 수
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		check = TRUE;
		scanf("%d", &a[i]);
		if (a[i] == 1)
			check = FALSE;
		for (j = 2; j < a[i]; j++) {
			if (a[i] % j == 0) {
				check = FALSE;
				break;
			}
		}
		if (check == TRUE)
			cunt++;
	}
	printf("%d", cunt);
	return 0;

}

