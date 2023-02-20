#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int max(int a, int b) {
	if (a < b) return b;
	return a;
}


int main() {
	
	int N;
	int dp[1001];
	int i;

	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 3;
	//dp[3] = dp[2] + dp[1] * 2;

	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	}
	printf("%d", dp[N]);
}

/*
3
*/
