#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int copyMap[8][8];
int map[8][8];
int visit[8][8];
int result;
int maxResult = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void initVisit() { //방문기록 초기화
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

void copyMapToDFS() { //map 복사
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

void printMap() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%d ", copyMap[i][j]);
		}
		printf("\n");
	}
}

void dfsVirus(int x,int y) { //바이러스 퍼뜨리기
	int i;

	for (i = 0; i < 4; i++) { //4방향 검사
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) { //범위 확인
			if (visit[nx][ny] == 0 && copyMap[nx][ny] == 0) { //방문 전, 빈칸일 때
				copyMap[nx][ny] = 2; //바이러스
				dfsVirus(nx, ny);
			}

		}
	}
}

int checkSafe() {
	int i, j;
	int count = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (copyMap[i][j] == 0) count++;
		}
	}
	return count;
}

int dfs(int cnt) {
	int i, j;	

	if (cnt == 3) { //3개의 벽 세우면 바이러스, 빈칸 확인
		//바이러스 퍼뜨리기		
		//map, visit 초기화
		copyMapToDFS();
		initVisit();
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (copyMap[i][j] == 2) {
					dfsVirus(i,j);
				}
			}
		}

		//printMap();
		return checkSafe();
	}


	//벽 세우기
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 0) { //빈칸일 경우에만 벽 세울 수 있음
				map[i][j] = 1;
				cnt++;
				result = dfs(cnt);
				maxResult = max(result, maxResult);
				map[i][j] = 0;
				cnt--;
			}
		}
	}
	return maxResult;
}


int main() {
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0);

	printf("%d", maxResult);

}


/*
4 4 2 1 
1 2 
1 3 
2 3 
2 4
*/
