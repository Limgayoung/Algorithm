#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[202][202];
int visit[202][202] = { 0 };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q; //좌표 저장

void bfs(int x,int y) {	
	pair<int, int> loc;
	q.push(make_pair(x, y));
	visit[x][y] = 1;

	while (!q.empty()) {
		loc = q.front();
		x = loc.first;
		y = loc.second;
		visit[x][y] = 1;		
		q.pop();
		if (loc.first == N && loc.second == M) return; //출구 도착

		for (int i = 0; i < 4; i++) {
			int nx = loc.first + dx[i];
			int ny = loc.second + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= M) { //범위 안
				if (map[nx][ny] == 1 && visit[nx][ny] == 0) { //길이고 방문x
					q.push(make_pair(nx, ny));					
					map[nx][ny] = map[x][y]+1;					
				}
			}			
		}
	}
}

int main() {
	char input[201];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", input);
		for (int j = 1; j <= M; j++) {
			map[i][j] = input[j-1] - '0';
		}
	}

	bfs(1, 1);

	printf("%d", map[N][M]);

}

/*
5 6 
101010 
111111 
000001 
111111 
111111
*/
