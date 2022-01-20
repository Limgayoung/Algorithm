#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

vector<int> divide(int v[][128], int N, int i, int j, vector<int> count) {
	int flag = 1;
	int a, b;
	int color;

	color = v[i][j];

	if (N == 1) { //종료 조건 1
		if (color == 1) { //blue
			count[1]++;
			return count;
		}
		else {
			count[0]++;
			return count;
		}
	}
	else {
		for (a = 0; a < N; a++) {
			if (flag == 0) {
				break;
			}
			for (b = 0; b < N; b++) {
				if (color != v[a + i][b + j]) {
					flag = 0;
					break;
				}
			}
		}

		if (flag == 0) { //나눠야 함
			count = divide(v, N / 2, i, j, count); //1번째
			count = divide(v, N / 2, i + (N / 2), j, count); //2번째
			count = divide(v, N / 2, i, j + (N / 2), count); //3번째
			count = divide(v, N / 2, i + (N / 2), j + (N / 2), count); //4번째
		}
		else { //종료조건 2
			if (color == 1) { //blue
				count[1]++;
				return count;
			}
			else {
				count[0]++;
				return count;
			}
		}
	}
	return count;
}


int main() {
	int N;
	int i, j;
	int x;

	vector<int> count(2); //white, blue

	scanf("%d", &N);

	int v[128][128];


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &x);
			v[i][j] = x;
		}
	}
	count = divide(v, N, 0, 0, count);

	printf("%d\n%d", count[0], count[1]);
	return 0;
}
