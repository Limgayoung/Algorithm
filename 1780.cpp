#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

int cnt[3] = { 0 };

void nine(int** arr, int x, int y, int N) {
	int i, j;
	int color;

	color = arr[x][y];

	for (i = x; i < x + N; i++) {
		for (j = y; j < y + N; j++) {
			if (color != arr[i][j]) { //분할
				nine(arr, x, y, N / 3);
				nine(arr, x + (N / 3), y, N / 3);
				nine(arr, x + ((N / 3) * 2), y, N / 3);

				nine(arr, x, y + (N / 3), N / 3);
				nine(arr, x + (N / 3), y + (N / 3), N / 3);
				nine(arr, x + ((N / 3) * 2), y + (N / 3), N / 3);

				nine(arr, x, y + ((N / 3) * 2), N / 3);
				nine(arr, x + (N / 3), y + ((N / 3) * 2), N / 3);
				nine(arr, x + ((N / 3) * 2), y + ((N / 3) * 2), N / 3);

				return;
			}
		}
	}

	if (color == -1) cnt[0]++;
	else if (color == 0) cnt[1]++;
	else if (color == 1) cnt[2]++;

}

int main() {
	int N;
	int i, j;
	int n;

	scanf("%d", &N);
	int** arr;
	arr = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &n);
			arr[i][j] = n;
		}
	}

	nine(arr, 0, 0, N);
	printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);

	return 0;
}
