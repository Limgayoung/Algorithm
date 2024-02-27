#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
1초 동안 일어나는 일
1. 미세먼지 확산 -> 사방으로 A/5 만큼 확산, 원래 자리에 남은 양은 원래 양 - 확산된 양
2. 공기청정기 작동 -> 바람대로 미세먼지가 한 칸씩 이동, 공기청정기에 들어가면 정화됨
*/

int R, C, T;

typedef struct dust {
	int x;
	int y;
	int n;
}dust;

vector<vector<int>> map;
//우상좌하
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int,int>> air = vector<pair<int, int>>();

void printMap() {
	printf("\n");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool isInside(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

void dustExpansion() {
	queue<dust> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) { //확산해야함
				q.push({ i,j,map[i][j] });
			}
		}
	}

	//q에 든 좌표 4방향으로 1칸씩 확산 필요
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int n = q.front().n;
		q.pop();
		//printf("now: %d %d %d\n", x, y, n);
		int expansionSum = 0;
		int expansionNum = n / 5;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isInside(nx, ny) && map[nx][ny] != -1) { //맵 안이고 공기청정기 있는 곳이 아니면 확산 가능
				map[nx][ny] += expansionNum;
				expansionSum += expansionNum;
				//printf("1");
			}
		}
		map[x][y] -= expansionSum;
		//printMap();
	}
}

void airCirculation() {
	//0번 공기청정기는 우상좌하 순서, dxdy 그대로 사용 가능
	//1번 공기청정기는 우하좌상 순서, dx 값 변경 필요 (dx+2)%4

	int dir = 0;
	int x = air[0].first;
	int y = air[0].second;
	int beforeDust = 0;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx == air[0].first && ny == air[0].second) {
			//다시 처음 위치로 돌아옴, beforeDust
			break;
		}
		if (!isInside(nx, ny)) { //방향 바꾸기
			dir++;
			continue;
		}
		int t = map[nx][ny];
		map[nx][ny] = beforeDust;
		beforeDust = t;
		x = nx;
		y = ny;
	}

	dir = 0;
	x = air[1].first;
	y = air[1].second;
	beforeDust = 0;
	dx[1] = 1;
	dx[3] = -1;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx == air[1].first && ny == air[1].second) {
			//다시 처음 위치로 돌아옴, beforeDust			
			break;
		}
		if (!isInside(nx, ny)) { //방향 바꾸기			
			dir++;
			continue;
		}
		int t = map[nx][ny];
		map[nx][ny] = beforeDust;
		beforeDust = t;
		x = nx;
		y = ny;
	}
	dx[1] = -1;
	dx[3] = 1;
}

int calDustSum() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) {
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int main()
{
	scanf("%d %d %d", &R, &C, &T);

	map = vector<vector<int>>(R, vector<int>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) { //공기청정기 위치 저장
				air.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < T; i++) { //1초마다 미세먼지 확산, 공기청정기 작동 하기
		dustExpansion();
		//printMap();
		airCirculation();
		//printMap();
	}

	int answer = calDustSum();

	printf("%d", answer);

	return 0;
}

/*
3 3 1
0 30 7
-1 10 0
-1 0 20
*/
