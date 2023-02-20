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
	int arr[1001], dp[1001];
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = max(dp[0], arr[1]);
	//dp[2] = max(dp[0] + arr[2], dp[1]);

	for (i = 2; i < N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
	}

	printf("%d", dp[N - 1]);
	
}

/*
4 
1 3 1 5
*/
