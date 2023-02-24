#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int map[201][201];
int isVisit[201][201] = { 0, };
priority_queue<pair<int,pair<int,int>>> pq; //바이러스 종류, 좌표

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void printMap() {
	int i, j;
	printf("\n");

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void pushPQ() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] != 0 && isVisit[i][j] == 0) {
				pq.push(make_pair(-map[i][j], make_pair(i, j)));
			}
		}
	}
}

void bfs() {
	int x = pq.top().second.first;
	int y = pq.top().second.second;
	int num = -pq.top().first;

	pq.pop();
	isVisit[x][y] = 1;

	for (int i = 0; i < 4; i++) { //4방향으로 퍼트리기
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) { //범위 안이면
			if (isVisit[nx][ny] == 0 && map[nx][ny] == 0) { //방문 전이고 비어있으면
				map[nx][ny] = num;
			}
		}
	}
}


int main() {
	int i, j;
	int S, X, Y;
	int n;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0) {
				pq.push(make_pair(-map[i][j], make_pair(i, j)));
			}
		}
	}	

	scanf("%d %d %d", &S, &X, &Y);

	for (i = 0; i < S; i++) { //S초 동안 증식
		n = pq.size();
		for (j = 0; j < n; j++) {
			bfs();
		}
		//printMap();
		pushPQ();
	}

	printf("%d", map[X-1][Y-1]);
}


/*
4 4 2 1 
1 2 
1 3 
2 3 
2 4
*/
