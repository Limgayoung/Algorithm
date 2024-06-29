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
1초
불은 계속 확장됨(상하좌우)
미로의 가장자리에 가면 탈출 가능!
bfs 돌리기, cnt가 이전과 달라질 때 불 확산
*/

typedef struct info {
	int x;
	int y;
	int cnt;
}info;

int R, C;
vector<vector<char>> arr;
vector<vector<bool>> visit;
pair<int, int> start;
queue<pair<int, int>> fires;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer = -1;

void printArr() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool isInside(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

void spreadFire() {
	int fireSize = fires.size();
	for (int i = 0; i < fireSize; i++) {
		int fx = fires.front().first;
		int fy = fires.front().second;
		fires.pop();

		for (int j = 0; j < 4; j++) {
			int nx = fx + dx[j];
			int ny = fy + dy[j];
			if (isInside(nx, ny) && arr[nx][ny] != '#' && arr[nx][ny] != 'F') {
				arr[nx][ny] = 'F';
				fires.push({ nx,ny });
			}
		}
	}
}

void bfs() {
	queue<info> q;

	q.push({ start.first,start.second,0 });	
	spreadFire();
	int beforeCnt = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		//printf("------------------------------\n");
		//printf("x: %d y: %d cnt: %d\n", x, y, cnt);
		//printArr();
		//printf("------------------------------\n");
		if (x == 0 || y == 0 || x == R - 1 || y == C - 1) { //가장자리 탈출 가능
			answer = cnt;
			break;
		}

		//불 확산
		if (cnt != beforeCnt) {			
			spreadFire();
			beforeCnt = cnt;
		}

		//J 이동
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && !visit[nx][ny] && arr[nx][ny] != '#' && arr[nx][ny] != 'F') {
				visit[nx][ny] = true;
				q.push({ nx,ny,cnt + 1 });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);

	arr = vector<vector<char>>(R, vector<char>(C));
	visit = vector<vector<bool>>(R, vector<bool>(C, false));

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			
			arr[i][j] = str[j];
			//scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'J') {
				start = { i,j };
				//printf("start: %d %d\n", i, j);
			}
			else if (arr[i][j] == 'F') {
				fires.push({ i,j });
			}
		}
		getchar();
	}
	bfs();

	if (answer == -1) printf("IMPOSSIBLE");
	else printf("%d", answer+1);
}

/*

*/
