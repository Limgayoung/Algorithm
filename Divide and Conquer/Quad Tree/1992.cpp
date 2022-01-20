#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

void quad(int **arr, int x, int y, int N) {
	int i, j;
	int color;
	 
	color = arr[x][y];

	for (i = x; i < x + N; i++) {
		for (j = y; j < y + N; j++) {
			if (color != arr[i][j]) { //분할
				printf("(");
				quad(arr, x, y, N / 2);
				quad(arr, x, y + (N / 2), N / 2);

				quad(arr, x + (N / 2), y, N / 2);
				quad(arr, x + (N / 2), y + (N / 2), N / 2);
				printf(")");
				return;
			}
		}
	}
	printf("%d", color);
}

int main() {
	int N;
	int i, j;
	char x[65];
	
	scanf("%d", &N);
	int** arr;
	arr = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
	}

	for (i = 0; i < N; i++) {
		scanf("%s", x);
		for (j = 0; j < N; j++) {
			arr[i][j] = x[j]-'0';
		}
	}

	quad(arr, 0, 0, N);

	return 0;
}
