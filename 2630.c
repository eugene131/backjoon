/*
*[2018111711] [배유진] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다.
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int white = 0;
int blue = 0;

void sack(int a[128][128],int strI,int strJ,int In,int Jn) {
	int checkNum = -1;
	int checkCol = -1;
	for (int i = strI; i < In; i++) {
		for (int j = strJ; j < Jn; j++) {
			if (a[i][j] != a[strI][strJ]) {
				checkNum = 0;
				break;
			}
			if (i == In - 1 && j == Jn - 1) {
				checkCol = a[strI][strJ];
			}
			
		}	
		if (checkNum == 0) {
			break;
		}
	}
	if (checkNum != 0 && checkCol == 1) {
		blue++;
	}if (checkNum != 0 && checkCol == 0) {
		white++;
	}
	if (checkNum == 0) {
		sack(a, strI, strJ, (strI+In) / 2, (strJ+Jn) / 2);//1번
		sack(a, strI, (strJ+Jn) / 2, (strI+In) / 2, Jn);//2번
		sack(a, (strI+In) / 2, strJ, In, (strJ+Jn) / 2);//3번
		sack(a, (strI+In) / 2, (strJ+Jn) / 2, In, Jn);//4번
	}


}




int main(void) {
	
	int a[128][128];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	sack(a,0, 0, n, n);
	printf("%d\n%d\n", white, blue);

	
	return 0;
}