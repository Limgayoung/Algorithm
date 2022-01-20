#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>

int A[5][5];
int t[5][5];


//행렬 출력
void printMatrix(int x[5][5], int N) {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}


//행렬곱
void matrix(int x[5][5], int y[5][5], int N) {
	int i, j, k;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			t[i][j] = 0;
			for (k = 0; k < N; k++) {
				t[i][j] += (x[i][k] * y[k][j]);
			}
			t[i][j] %= 1000;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			x[i][j] = t[i][j];
		}
	}
}



int main() {
	long long B; //1 ≤ B ≤ 100,000,000,000
	int N; // 2 ≤ N ≤  5
	int i, j;
	int answer[5][5] = { 0 };

	scanf("%d %lld", &N, &B);

	//행렬 입력
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			answer[i][i] = 1; //단위행렬로 해줘야 처음에 A를 곱했을 때 자기 자신이 나옴
		}
	}
	
	//분할정복 이용하기
	while (B > 0) {
		if (B % 2 == 1) { //홀수면 한번 더 곱하기
			matrix(answer, A, N);
		}
		matrix(A, A, N);
		B /= 2;
	}

	printMatrix(answer, N);

	return 0;
}

