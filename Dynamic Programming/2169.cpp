#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
시간 제한 1초
N,M <= 1000   1000x1000 = 1000000

로봇 : 좌, 우, 하 이동 가능


dp 구해서 해당 위치의 최댓값을 갱신.
dp[N-1][M-1]의 최댓값이 정답이 된다.

1. 맨 윗줄은 좌 -> 우 탐색만 가능 (dp 초기화)
2. dp 갱신
	1. 상 -> 하 탐색했을 때의 경우로 dp 초기화
	2. 좌 -> 우 탐색 dp 갱신 (따로 저장 필요)
	3. 우 -> 좌 탐색 dp 갱신 (따로 저장 필요)
	4. 좌->우 / 우->좌 중 max 값이 dp 값이 된다.
*/

#define MIN_NUM -100000000

int N, M;
vector<vector<int>> arr;
vector<vector<int>> dp;

void printDP() {
	printf("----------dp!!---------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	scanf("%d %d", &N, &M);

	arr = vector<vector<int>>(N, vector<int>(M));
	dp = vector<vector<int>>(N, vector<int>(M, MIN_NUM)); //최소값을 넣어놓기

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	//1. 맨 윗줄 dp 갱신
	dp[0][0] = arr[0][0];
	for (int i = 1; i < M; i++) {
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}

	//dp 갱신
	for (int i = 1; i < N; i++) {
		vector<int> left(M);
		vector<int> right(M);
		
		//1. 상 -> 하 dp 초기화
		for (int j = 0; j < M; j++) {
			dp[i][j] = dp[i - 1][j] + arr[i][j];
			left[j] = dp[i][j];
			right[j] = dp[i][j];
		}

		//printf("dp 갱신 전!!!!\n");
		//printDP();

		//2. 좌->우 / 우->좌 dp 갱신		

		//좌 -> 우
		left[0] = dp[i][0];
		for (int j = 1; j < M; j++) {
			left[j] = max(left[j - 1] + arr[i][j], left[j]);
		}

		//우 -> 좌
		right[M - 1] = dp[i][M - 1];
		for (int j = M - 2; j >= 0; j--) {
			right[j] = max(right[j + 1] + arr[i][j], right[j]);
		}

		//dp 갱신
		for (int j = 0; j < M; j++) {
			dp[i][j] = max(left[j], right[j]);
		}

		//printDP();
	}

	//printDP();


	printf("%d", dp[N-1][M-1]);
}

/*
1
3
0 -1
0 -3
0 -5
3 1 2 3

1
3
0 1
0 3
0 5
3 1 2 3
*/
