#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
D를 이분탐색해 각 D마다 bfs로 채굴할 수 있는 광물 수 구하기
	공기와 맞닿은 모든 곳에서 bfs -> visit 안된 테두리에서만 bfs 하면 됨
	테두리 리스트 저장 (테두리는 항상 같음)
*/

typedef struct stone {
	int x;
	int y;
	int s; //강도
}stone;

int N, M, K;
vector<vector<int>> arr;
vector<vector<bool>> visit;
vector<pair<int, int>> border;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int cnt;

bool isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

void bfs(int x, int y, int d) {
	queue<stone> q;

	q.push({ x,y,arr[x][y] });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().s;
		q.pop();

		//채굴 불가능
		if (s > d) continue;
		cnt++;
		//상하좌우 광물 채굴 가능해짐
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ nx,ny,arr[nx][ny] });
			}
		}
	}
}

int main() {

	int l = 0;
	int r = 0;

	scanf("%d %d %d", &N, &M, &K);

	arr = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M,false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			//테두리 저장
			if (i == 0 || j==0 || j==M-1) {
				border.push_back({ i,j });
			}
			r = max(r, arr[i][j]);
		}
	}

	//이분탐색 시작

	int answer = 1000000;

	while (l <= r) {
		int mid = (l + r) / 2;
		//printf("l: %d r: %d mid: %d\n", l, r, mid);
		//bfs로 캘 수 있는 광물 개수 구하기
		cnt = 0;
		visit = vector<vector<bool>>(N, vector<bool>(M, false));
		for (int i = 0; i < border.size(); i++) {
			int x = border[i].first;
			int y = border[i].second;
			if (!visit[x][y]) {
				visit[x][y] = true;
				bfs(x, y, mid);
			}
		}
		//printf("cnt: %d\n=================\n", cnt);
		if (cnt >= K) { //해당 강도 가능, 줄이기
			answer = min(answer, mid);
			r = mid - 1;
		}
		else l = mid + 1; //해당 강도 불가능, 늘리기
	}
	printf("%d", answer);

	return 0;
}

/*

*/
