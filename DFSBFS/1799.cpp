#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <set>

using namespace std;

/*
제한시간 10초
N: 10x10 최대 100칸 * 20번 검사?
1. 비숍이 놓일 수 있는 곳 저장 -> canBishop
2. 완탐... 100!?ㅋ -> map 대각선을 2로 칠하기 -> 해당 부분은 검사는 ㄱㄴ하지만 비숍 못놓음
	해당 부분에 놓는 경우, 안 놓는 경우
3. 2가지 경우로 나눠서 dfs
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0

*/

int N;
vector<vector<int>> arr;
vector<pair<int, int>> canBishop;
vector<vector<int>> numArr;
int dx[4] = { -1,-1,1,1 };
int dy[4] = { 1,-1,1,-1 };
int maxCnt = 0;

void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void initNumArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					numArr[i][j] = 0;
				}
				else numArr[i][j] = 1;
			}
			else {
				if (j % 2 == 0) {
					numArr[i][j] = 1;
				}
				else numArr[i][j] = 0;
			}
		}
	}
}

//비숍 놓은 곳 : 5
//0이었던 곳 바꿀 때 : 0 -> 2
//1이었던 곳 바꿀 때 : 1 -> 3
void changeMap(int ox, int oy, pair<int, int> n) {
	int zero = n.first;
	int one = n.second;

	//비숍 놓기
	if (one == 3) arr[ox][oy] = 5;
	else arr[ox][oy] = one;

	for (int i = 0; i < 4; i++) {
		int x = ox;
		int y = oy;

		while (true) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//0 -> 2  혹은 2 -> 0
				if (arr[nx][ny] == zero + 2 || arr[nx][ny] == zero - 2) {
					arr[nx][ny] = zero;
				}
				else {
					arr[nx][ny] = one;
				}
			}
			else break;

			x = nx;
			y = ny;
		}
	}
}

bool canSet(int ox, int oy) {
	bool flag = true;
	if (arr[ox][oy] != 1 && arr[ox][oy] != 3) return false;

	for (int i = 0; i < 4; i++) {
		int x = ox;
		int y = oy;

		while (true) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//1인 부분에 비숍이 있어야 잡을 수 있음
				if (arr[nx][ny] == 5) {
					flag = false;
					break;
				}
			}
			else break;

			x = nx;
			y = ny;
		}
		if (!flag)break;
	}
	return flag;
}

void dfs(int index, int cnt, int num) { //num 0: 0인 곳만 가능, num 1: 1인 곳만 가능
	
	if (index == canBishop.size()) {
		//printf("cnt: %d\n", cnt);
		//printMap();
		maxCnt = max(cnt, maxCnt);
		return;
	}

	//최대값보다 작은 경우
	if (cnt + (canBishop.size() - index - 1) < maxCnt) return;

	int x = canBishop[index].first;
	int y = canBishop[index].second;

	

	//index 위치에 안 놓는 경우
	dfs(index + 1, cnt,num);


	//index 위치에 놓을 경우	
	//num이 아님, 못 놓는 경우
	if (numArr[x][y] == num) {
		if (canSet(x, y)) {
			//printf("set!\n");
			//arr 변경
			changeMap(x, y, { 2,3 });
			dfs(index + 1, cnt + 1, num);
			//arr 원복
			changeMap(x, y, { 0,1 });
		}
	}



}

int main() {

	scanf("%d", &N);

	arr = vector<vector<int>>(N, vector<int>(N));
	numArr = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				canBishop.push_back({ i,j });
			}
		}
	}

	initNumArr();

	dfs(0, 0,0);
	int answer = maxCnt;
	maxCnt = 0;
	dfs(0, 0,1);
	answer += maxCnt;
	printf("%d", answer);

	return 0;
}

/*
*/
