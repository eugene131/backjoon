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
	int A, B, C, X, i, cunt = 0;
		scanf("%d", &X);
		for (i = 1; X > 0; i++) {
			X = X - i;
			cunt++;//몇 번째 줄인지 확인 
		}//x는 몇번째 만큼 밀렸는지 확인 가능
		if (i % 2 != 0)
			printf("%d/%d\n", cunt + X, 1 - X);
		else
			printf("%d/%d\n", 1 - X, cunt + X);
	
	return 0;

}

