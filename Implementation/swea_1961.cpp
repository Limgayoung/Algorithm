#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>


using namespace std;

vector<vector<int>> rotation(vector<vector<int>> arr, int N) { //90도 회전
	vector<vector<int>> result(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = arr[N-j-1][i];
		}
	}

	return result;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int answer;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		vector<vector<int>> m(N, vector<int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &m[i][j]);
			}
		}

		vector<vector<int>> rotation90 = rotation(m, N);
		vector<vector<int>> rotation180 = rotation(rotation90, N);
		vector<vector<int>> rotation270 = rotation(rotation180, N);

		printf("#%d\n" , test_case);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N * 3; j++) {
				if (j / N == 0) {
					printf("%d", rotation90[i][j%N]);
				}
				else if (j / N == 1) {
					printf("%d", rotation180[i][j%N]);
				}
				else if (j / N == 2) {
					printf("%d", rotation270[i][j%N]);
				}

				if (j % N == N - 1) {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
