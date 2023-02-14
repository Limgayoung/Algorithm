#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	int min, rowMin;
	int num[101][101];
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &num[i][j]);

			if (j == 0) { //rowMin 초기화
				rowMin = num[i][j];
			}
			if (rowMin > num[i][j]) {
				rowMin = num[i][j];
			}			
		}
		if (i == 0) { //min 초기화
			min = rowMin;
		}
		//printf("min: %d rowMin: %d\n", min, rowMin);
		if (min < rowMin)
			min = rowMin;
	}
	printf("%d", min);
}

/*
3 3 
3 1 2 
4 1 4 
2 2 2

2 4 
7 3 1 8 
3 3 3 4
*/
