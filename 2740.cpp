#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

int ** matrix(int** A, int** B, int **C, int N, int M, int K) {
	int i, j, k;
	int sum;

	//행렬곱을 하면 N*K 크기의 행렬이 됨
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++) {
			sum = 0;
			for (k = 0; k < M; k++) {
				sum += (A[i][k] * B[k][j]);
			}
			C[i][j] = sum;
		}
	}

	return C;
}

int main() {
	int N, M, K;
	int** A, ** B, **C;
	int i, j;

	scanf("%d %d", &N, &M);

	//행렬 A 할당
	A = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		A[i] = (int*)malloc(sizeof(int) * M);		
	}

	//행렬 A 입력
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}


	scanf("%d %d", &M, &K);

	//행렬 B 할당
	B = (int**)malloc(sizeof(int*) * M);

	for (i = 0; i < M; i++) {
		B[i] = (int*)malloc(sizeof(int) * K);
	}

	//행렬 B 입력
	for (i = 0; i < M; i++) {
		for (j = 0; j < K; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	//행렬곱의 결과 C행렬 할당
	C = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		C[i] = (int*)malloc(sizeof(int) * K);
	}

	C = matrix(A, B, C, N, M, K);

	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}
