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
N <= 200
200 * 200 * 200 = 8000000
만들어진 dist를 이용해 도시 구하기 -> 200 * 200 * 200 = 8000000

*/
#define INF 987654321

int N, M, K;
vector<vector<int>> dist;
vector<int> answer;
vector<int> friends;

int main()
{
	scanf("%d %d", &N, &M);

	dist = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));
	answer = vector<int>(N + 1, INF);

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}

	//dist 구하기
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	//친구 입력
	scanf("%d", &K);
	friends = vector<int>(K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &friends[i]);
	}

	//최소 왕복시간 구하기
	//dist[i][k] + dist[k][i]
	int minDist = INF;
	for (int k = 1; k <= N; k++) {
		int maxDist = 0;
		for (int i = 0; i < K; i++) {
			int n = friends[i];
			maxDist = max(maxDist, dist[n][k] + dist[k][n]);
		}
		answer[k] = min(answer[k], maxDist);
		minDist = min(answer[k], minDist);
	}

	for (int i = 1; i <= N; i++) {
		if (answer[i] == minDist) {
			printf("%d ", i);
		}
	}

}

/*
10
0 2 3 4 5 6 7 8 9 10
*/
