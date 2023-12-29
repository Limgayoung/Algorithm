#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dxx[4] = { -1,1,-1,1 };
int dyx[4] = { 1,1,-1,-1 };


int calFly(vector<vector<int>> arr, int N, int M, int x, int y) {
	int maxResult = 0;
	int nowResult = 0;
	int nx, ny;

	//+ 형태 계산
	nowResult = arr[x][y];
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			nx = x + i * dx[j];
			ny = y + i * dy[j];

			if (nx < N && ny < N && nx >= 0 && ny >= 0) {
				nowResult += arr[nx][ny];
			}
		}
	}
	maxResult = nowResult;

	//x 형태 계산
	nowResult = arr[x][y];
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			nx = x + i * dxx[j];
			ny = y + i * dyx[j];

			if (nx < N && ny < N && nx >= 0 && ny >= 0) {
				nowResult += arr[nx][ny];
			}
		}
	}
	if (maxResult < nowResult) return nowResult;
	else return maxResult;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M;
	int maxNum, nowNum;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		maxNum = 0;		

		vector<vector<int>> arr(N, vector<int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				nowNum = calFly(arr, N, M, i, j);
				if (maxNum < nowNum) maxNum = nowNum;
			}
		}


		printf("#%d %d\n" , test_case, maxNum);
	}
	return 0;
}
