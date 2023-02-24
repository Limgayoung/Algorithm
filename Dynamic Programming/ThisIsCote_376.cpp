#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[501][501] = { 0 };
int dp[501][501] = { 0 };
int n;
int result=0;

void printDP() {
	int i, j;
	printf("dp\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

void makeDP() {
	int i, j;
	int left, right;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
			if (i == n) {
				result = max(result, dp[i][j]);
			}
		}
	}
	//printDP();
}

int main() {
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = arr[i][j]; //dp 초기화
		}
	}

	makeDP();
	printf("%d", result);
}


/*
2 
3 4 
1 3 3 2 2 1 4 1 0 6 4 7 
4 4 
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
*/
