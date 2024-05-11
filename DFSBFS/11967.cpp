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
불 켜진 곳만 들어갈수 있음
-> 1,1 위치에서 계속 반복하면서 확인하기 (나중에 킨 불로 처음에 못갔던 곳도 갈 수 있게됨)

bfs 돌기
불 킬 수 있는 곳 모두 켜기, 4방향 방 갈 수 있는 곳 지정 (canGo)
canGo, light queue에 push

*/

int N, M;
vector<vector<vector<pair<int,int>>>> arr; //n*n 방마다 있는 스위치들
vector<vector<bool>> visit; //방문 여부
vector<vector<bool>> isLight; //불 켜짐 여부
vector<vector<bool>> canGo; //갈 수 있는지 여부
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


bool isInside(int x, int y) {
	if (x >= 1 && x <= N && y >= 1 && y <= N) return true;
	return false;
}

void bfs() {
	//불 킬 수 있는 곳 모두 켜기, 4방향 방 갈 수 있는 곳 지정 (canGo)
	//canGo, light queue에 push

	queue<pair<int, int>> q;
	visit[1][1] = true;
	canGo[1][1] = true;
	isLight[1][1] = true;
	q.push({ 1,1 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//printf("x: %d y: %d\n", x, y);

		for (int i = 0; i < arr[x][y].size(); i++) { //해당 방과 연결된 방 불 켜기
			int nx = arr[x][y][i].first;
			int ny = arr[x][y][i].second;

			isLight[nx][ny] = true;
		}

		//4방향 탐색 - 불 켜져 있으면 갈 수 있음
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && !visit[nx][ny]) {
				canGo[nx][ny] = true;
			}
		}

		//불 켜져 있고 갈 수 있으면 방문 가능
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (isLight[i][j] && canGo[i][j] && !visit[i][j]) {
					visit[i][j] = true;
					q.push({ i,j });
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	arr = vector<vector<vector<pair<int, int>>>>(N+1, vector<vector<pair<int, int>>>(N+1, vector<pair<int, int>>()));
	visit = vector<vector<bool>>(N+1, vector<bool>(N+1, false));
	isLight = vector<vector<bool>>(N+1, vector<bool>(N+1, false));
	canGo = vector<vector<bool>>(N+1, vector<bool>(N+1, false));

	int x, y, a, b;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		arr[x][y].push_back({ a,b });
	}

	isLight[1][1] = true;
	bfs();

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (isLight[i][j]) answer++;
		}
	}
	printf("%d", answer);

}

/*
10
0 2 3 4 5 6 7 8 9 10
*/
