#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>

long long A[2][2] = { {1,1},{1,0 } };
long long t[2][2];
long long mod = 1000000007;

//행렬 출력
void printMatrix(long long x[2][2]) {
	int i, j;
	int N = 2;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%lld ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}


//행렬곱
void matrix(long long x[2][2], long long y[2][2]) {
	int i, j, k;
	int N = 2;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			t[i][j] = 0;
			for (k = 0; k < N; k++) {
				t[i][j] += (x[i][k] * y[k][j]);
			}
			t[i][j] %= mod;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			x[i][j] = t[i][j];
		}
	}
}



int main() {
	long long n; //1 ≤ n ≤ 1,000,000,000,000,000,000
	int i, j;
	long long answer[2][2] = { {1,0},{0,1 } };

	scanf("%lld", &n);

	//분할정복 이용하기
	while (n > 0) {
		if (n % 2 == 1) { //홀수면 한번 더 곱하기

			matrix(answer, A);
		}
		matrix(A, A);
		n = n/2;
	}

	//printMatrix(answer, n);
	printf("%lld", answer[0][1]);

	return 0;
}

