#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

int dp[16] = { 0 };
int N;

bool isSafe(int day, int t) {
	if ((day + t) > N+1) return false;
	return true;
}

int main() {
	int T[16], P[16];

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	for (int i = N; i > 0; i--) {
		if (isSafe(i, T[i])) { //기한 안넘김
			dp[i] = max(dp[i + T[i]] + P[i], dp[i+1]); //i일 상담 하기 vs i일 상담 안하기(dp[현재날짜 + 걸리는 기간])
			//printf("day: %d dp[%d]: %d\n", i, i, dp[i]);
			//dp[5] = max(dp[5+2] + P[5], dp[6]) -> max(0, 15)
			//dp[4] = max(dp[4+1]+ P[4], P[5])
		}
		else {
			dp[i] = dp[i + 1];
		}
	}

	printf("%d", dp[1]);
	
	return 0;
}

/*
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200

3
3 100
1 99
1 2

4
3 1
1 100
2 100
1 1000
*/
