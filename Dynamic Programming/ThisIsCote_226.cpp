#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX 10001

int coin[101];
int dp[101];
int N, M;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int findMin(int num) {
	int i;
	int small=dp[num];

	for (i = 0; i < N; i++) {
		if (num - coin[i] > 0) {
			small = min(dp[num - coin[i]]+1, small);
		}
	}
	return small;
}

int main() {
	int i;


	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++) {
		dp[i] = MAX;
	}

	//3원 종류가 있으면 dp[3]은 1개로 만들 수 있음
	for (i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
		dp[coin[i]] = 1;
	}

	sort(coin, coin + N);

	for (i = coin[0]; i <= M; i++) {
		dp[i] = findMin(i);
		//printf("dp[%d]: %d\n", i, dp[i]);
	}

	if (dp[M] == MAX) printf("-1");
	else printf("%d", dp[M]);
}

/*
2 15 
2 
3

3 4 
3 
5 
7
*/
