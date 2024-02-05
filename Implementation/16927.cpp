#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, R;
int map[305][305];
//하우상좌
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int startx;
int endx;
int starty;
int endy;

vector<int> rotation(vector<int> v) { //항상 반시계 방향으로 돌려야 함
	//v.size() 를 r로 나눈 나머지만큼 옮기기
	vector<int> resultV(v.size());

	for (int i = 0; i < v.size(); i++) {
		//i자리에 있는 원소를 (i+r)%r 위치로 옮기기
		resultV[(i + R) % v.size()] = v[i];
	}
	return resultV;
}

void printVector(vector<vector<int>> vec) {
	for (vector<int> v : vec) {
		for (int n : v) {
			printf("%d ", n);
		}
		printf("\n");
	}
	printf("\n");
}

bool isInside(int x, int y) {
	if (x >= startx && x <= endx && y >= starty && y <= endy) return true;
	return false;
}

int main(int argc, char** argv)
{
	scanf("%d %d %d", &N, &M, &R);

	int vectorSize = min(N / 2, M / 2);

	if (N % 2 == 1 && M % 2 == 1) vectorSize++;
	vector<vector<int>> arr(vectorSize);

	//입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int size = 2 * N + 2 * M - 4;
	//arr에서 네모들을 각각 하나의 vector 한 줄로 저장하기
	for (int k = 1; k <= vectorSize; k++) {
		startx = k - 1;
		endx = N - k;
		starty = k - 1;
		endy = M - k;

		int dir = 0;
		int x = startx;
		int y = starty;
		for (int i = 0; i < size; i++) {
			arr[k - 1].push_back(map[x][y]);
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!isInside(nx, ny)) { //방향 바꿔줘야함
				dir++;
				dir %= 4;

				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			x = nx;
			y = ny;
		}
		size = (N - (k * 2)) * 2 + (M - (k * 2)) * 2 - 4;
	}

	//printVector(arr);

	for (int i = 0; i < vectorSize; i++) {
		arr[i] = rotation(arr[i]);
	}

	//printVector(arr);

	//map의 요소를 arr 요소대로 채우기
	size = 2 * N + 2 * M - 4;
	for (int k = 1; k <= vectorSize; k++) {
		startx = k - 1;
		endx = N - k;
		starty = k - 1;
		endy = M - k;

		int dir = 0;
		int x = startx;
		int y = starty;
		for (int i = 0; i < size; i++) {
			map[x][y] = arr[k - 1][i];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!isInside(nx, ny)) { //방향 바꿔줘야함
				dir++;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			x = nx;
			y = ny;
		}
		size = (N - (k * 2)) * 2 + (M - (k * 2)) * 2 - 4;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
