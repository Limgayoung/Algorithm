#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>


using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M;
	int answer;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> m(27, vector<int>(10,0)); //0~8: 가로 9~17: 세로 18~26: 칸
		vector<vector<int>> sudoku(9, vector<int>(9));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}

		int flag = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int num = sudoku[i][j];
				if (m[i][num] == 0) m[i][num] = 1; //가로
				else flag = 0;
				if (m[9+j][num] == 0) m[9+j][num] = 1; //세로
				else flag = 0;
				int boardNum = 3 * (i / 3) + (j / 3);
				if (m[18+boardNum][num] == 0) m[18+boardNum][num] = 1; //칸
				else flag = 0;

				if (flag == 0) {			
					//printf("sudoku[%d][%d]: %d\n", i, j, sudoku[i][j]);
					break;
				}
			}
			if (flag == 0) break;
		}

		printf("#%d %d\n" , test_case, flag);
	}
	return 0;
}
