#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//북동남서
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[51][51];
int visit[51][51] = { 0 };
int cnt = 1; //맨 처음 자리도 세야 함
int N, M;

int turn(int dir) { //북동남서 0123 //문제에서 반시계 방향으로 90도 회전하라고 함
	dir -= 1; 
	if (dir == -1) dir = 3;
	return dir;
}

int main() {
	int i, j;
	int x, y, dir;
	int nx, ny;
	int turnCnt=0;


	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &x, &y, &dir);

	for (i = 0; i < N; i++) { //맵 초기화
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);			
		}
	}	

	while (1) {
		//1. 왼쪽으로 회전
		dir = turn(dir);
		turnCnt++;

		//2. 확인
		nx = dx[dir] + x;
		ny = dx[dir] + y;


		//printf("dir: %d  nx,ny: (%d, %d)\n", dir, nx, ny);
		if (visit[nx][ny]==0 && map[nx][ny]==0) { //방문하지 않은 곳, 육지
			x = nx;
			y = ny;
			cnt++;
			turnCnt = 0;
			visit[nx][ny] = 1;
			continue;
		}
		else if(turnCnt == 4) {
			nx = dx[dir] + x;
			ny = dx[dir] + y;
			if (map[nx][ny]==1) break; //바다면 끝
			x = nx;
			y = ny;
			turnCnt = 0;
		}		
		
	}
	printf("%d", cnt);
	
}

/*
4 4 
1 1 0 
1 1 1 1 
1 0 0 1 
1 1 0 1 
1 1 1 1
*/
