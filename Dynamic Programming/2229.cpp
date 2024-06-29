#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/*
2초
N <= 1000
2 5 7 1 3 4 8 6 9 3
3 6 5 3 0
5 7 0 6
2 5 / 7 1 / 3 4 8 / 6 / 9 3
3 6 5 0 6 -> 20

dp[i] : i까지의 점수 최댓값
dp[0] : 0
dp[1] : minmax = 3
dp[2] : dp[1] vs dp[0] + minmax vsminmax = 5
dp[3] : dp[2] vs dp[1] + minmax vs dp[0] + minmax vs minmax = 5 vs 3+6 vs 0+6 vs 6 = 9

*/



int main()
{
	int N;
	scanf("%d", &N);
	vector<int> arr(N);
	vector<int> dp(N, 0);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	//dp 계산
	dp[0] = 0;	
	for (int i = 1; i < N; i++) {
		int maxNum = arr[i];
		int minNum = arr[i];		
		for (int j = i - 1; j >= 0; j--) {

			//printf("dp[%d]: %d max: %d min: %d\n", j, dp[j], maxNum, minNum);
			dp[i] = max(dp[j] + maxNum - minNum, dp[i]);
			maxNum = max(maxNum, arr[j]);
			minNum = min(minNum, arr[j]);

		}
		dp[i] = max(maxNum - minNum, dp[i]);
		//printf("dp[%d]: %d\n", i, dp[i]);
	}

	printf("%d", dp[N-1]);
}

/*

*/
