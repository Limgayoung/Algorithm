#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

int N, M;
int map[51][51]; //0: 빈칸  1: 벽  2: 청소한 곳
//북동남서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt = 0;

bool isInside(int x, int y) {
	if (x >= N || x < 0 || y >= M || y < 0) return false;
	return true;
}

void cleanRoom(int x, int y, int dir) {
	if (map[x][y] == 0) {
		map[x][y] = 2;
		cnt++;
	}
	
	 //4칸 확인
	for (int i = 0; i < 4; i++) {
		int ndir = (dir + 3 -i) % 4;
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];
			
		if (isInside(nx,ny) && map[nx][ny] == 0) {
			cleanRoom(nx, ny, ndir);
		}
	}	
	//청소 가능한 칸 없을 경우
	
	//후진
	int backDir = (dir + 2) % 4;
	int nx = x + dx[backDir];
	int ny = y + dy[backDir];
	if (!isInside(nx,ny) || map[nx][ny] == 1) {
		printf("%d\n", cnt);
		exit(0);
	}

	//벽이 아니면 후진
	cleanRoom(nx, ny, dir);
}

int main() {

	scanf("%d %d", &N, &M);
	int a, b, dir;
	scanf("%d %d %d", &a, &b, &dir);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++ ) {
			scanf("%d", &map[i][j]);
		}
	}	

	cleanRoom(a,b,dir);

	printf("%d", cnt);

	return 0;
}

/*
3 3
1 1 0
1 1 1
1 0 1
1 1 1


11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
*/
