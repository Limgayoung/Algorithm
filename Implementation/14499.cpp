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

int N, M, x, y, K;
int map[21][21] = { 0 };
vector<int> dice(7, 0);

//동서북남
int dx[5] = { 0, 1, -1, 0,0 };
int dy[5] = { 0, 0, 0, -1, 1 };

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void rollDice(int dir) { //동서북남 1234	
	int diceResult[7];

	if (dir == 1) { // 동쪽
		dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
	}
	else if (dir == 2) { //서쪽
		dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
	}
	else if (dir == 3) { //북쪽
		dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };

	}
	else { //남쪽
		dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
		
	}
}

void printDice() {
	for (int i = 1; i < 7; i++) {
		printf("%d ", dice[i]);
	}
	printf("\n");
}

bool isInside(int x, int y) {
	if (x >= 0 && x < M && y >= 0 && y < N) return true;	
	return false;
}

void moveDice(int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (!isInside(nx, ny)) return; //범위 벗어남

	rollDice(dir);
	printf("%d\n",dice[1]); //윗면 출력
	//주사위 바닥 확인
	if (map[ny][nx] == 0) {
		map[ny][nx] = dice[6];
	}
	else {
		dice[6] = map[ny][nx];
		map[ny][nx] = 0;
	}
	x = nx;
	y = ny;	
}

int main() {
	
	int dir;

	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//printMap();

	for (int i = 0; i < K; i++) {
		scanf("%d", &dir);
		//printf("이동 전: %d %d, dir: %d\n", x, y, dir);
		moveDice(dir);
		//printf("이동 후: %d %d, dir: %d\n", x, y, dir);
		//printDice();
		//printf("map\n");
		//printMap();
	}
}

/*
4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

2 2 1 0 1
0 0
0 1
1

*/
