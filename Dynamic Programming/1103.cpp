#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef struct info {
	int x;
	int y;
	int cnt;
	int dir;
}info;

int N, M;
vector<vector<int>> map;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool isInf = false;

vector<vector<bool>> visit;
vector<vector<int>> dp;
int maxCnt = 0;

bool isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

void dfs(int x, int y) {
	if (isInf) return;

	//printf("%d %d cnt: %d\n", x, y, cnt);
	maxCnt = max(maxCnt, dp[x][y]);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * map[x][y];
		int ny = y + dy[i] * map[x][y];

		if (isInside(nx, ny) && map[nx][ny] != -1) {
			//현재 칸을 이전에 방문했는지 체크		
			if (!visit[nx][ny]) { //방문 전
				if (dp[nx][ny] >= dp[x][y] + 1) continue; //갱신 안되는 상황 -> 탐색 x
				visit[nx][ny] = true;
				dp[nx][ny] = dp[x][y]+1;
				dfs(nx, ny);
				visit[nx][ny] = false;
			}
			else {
				isInf = true;
				return;
			}			
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);

	map = vector<vector<int>>(N, vector<int>(M));
	dp = vector<vector<int>>(N, vector<int>(M, -1));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));			

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {

			if (str[j] >= '0' && str[j] <= '9') map[i][j] = str[j] - '0';
			else map[i][j] = -1;			
		}
	}

	dp[0][0] = 1;
	dfs(0, 0);
	//bfs(0, 0);

	if (isInf) printf("-1");
	else printf("%d", maxCnt);


	return 0;
}

/*

*/
