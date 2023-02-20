#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int dp[30001];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	
	int X;
	int i;
	int small;

	scanf("%d", &X);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[5] = 1;

	for (i = 4; i <= X; i++) {
		small = 30001;
		if (i % 5 == 0) {
			small = min(small, dp[i / 5] + 1);
		}
		if (i % 3 == 0) {
			small = min(small, dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			small = min(small, dp[i / 2] + 1);
		}
		small = min(small, dp[i - 1] + 1);
		dp[i] = small;		
	}
	printf("%d", dp[X]);
}

/*
26
*/
