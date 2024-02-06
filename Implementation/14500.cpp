#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
500x500 x 19(회전, 대칭 포함) -> 5000000 * 4(내부인지 확인) -> 20000000
1. 회전/대칭한 모양까지 모두 저장
2. 각각의 모양으로 맵의 처음부터 끝까지 탐색

맨 끝 위가 i,j라고 할 때 (0,0부터 시작)

하늘색 -> i,j  i,j+1  i,j+2  i,j+3 -> 0,0  0,1  0,2  0,3
노란색 -> i,j  i,j+1  i+1,j  i+1,j+1
...
*/

vector<vector<pair<int,int>>> tetrominos; //dx, dy
int N, M;
int map[500][500];


vector<pair<int, int>> symmetrlyTetromino(vector<pair<int, int>> tetromino) { //아래로 대칭
	int maxHeight = 0;
	for (int i = 0; i < 4; i++) {			
		maxHeight = max(maxHeight, tetromino[i].first);
		tetromino[i].first = -tetromino[i].first;
	}

	for (int i = 0; i < 4; i++) {
		tetromino[i].first += maxHeight;
	}

	return tetromino;
}

void initTetromino() { //이렇게 하나씩 넣는게 맞나..?
	//하늘색
	tetrominos.push_back({ {0,0},{0,1},{0,2},{0,3} });
	tetrominos.push_back({ {0,0},{1,0},{2,0},{3,0} });

	//노란색
	tetrominos.push_back({ {0,0},{0,1},{1,0},{1,1} });

	//주황색
	tetrominos.push_back({ {0,0},{2,0},{2,1},{1,0} });
	tetrominos.push_back({ {0,2},{0,1},{0,0},{1,0} });
	tetrominos.push_back({ {2,1},{1,1},{0,1},{0,0} });
	tetrominos.push_back({ {1,0},{1,1},{1,2},{0,2} });
	for (int i = 0; i < 4; i++) {
		tetrominos.push_back(symmetrlyTetromino(tetrominos[i + 3]));
	}

	//초록색
	tetrominos.push_back({ {0,0},{1,0},{1,1},{2,1} });
	tetrominos.push_back({ {0,1},{0,2},{1,1},{1,0} });
	tetrominos.push_back(symmetrlyTetromino(tetrominos[11]));
	tetrominos.push_back(symmetrlyTetromino(tetrominos[12]));

	//분홍색
	tetrominos.push_back({ {0,0},{0,1},{0,2},{1,1} });
	tetrominos.push_back({ {0,0},{1,0},{2,0},{1,1} });
	tetrominos.push_back({ {0,1},{1,0},{2,1},{1,1} });
	tetrominos.push_back(symmetrlyTetromino(tetrominos[15]));
	
}

int findMaxSum(vector<pair<int, int>> tetromino) {

	int sum;
	int maxSum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum = 0;
			for (int k = 0; k < 4; k++) { //각각의 칸
				int x = tetromino[k].first + i;
				int y = tetromino[k].second + j;

				//printf("x: %d y: %d\n", x, y);
				if (x >= 0 && x < N && y >= 0 && y < M) {
					sum += map[x][y];
				}
				else {
					sum = -1;
					break;
				}
			}
			maxSum = max(maxSum, sum);
			//printf("sum: %d\n", sum);
		}
	}
	//printf("maxSum: %d\n", maxSum);
	return maxSum;
}

int main(int argc, char** argv)
{
	scanf("%d %d", &N, &M);
	int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//테트로미노 모양 저장
	initTetromino();

	for (int i = 0; i < tetrominos.size(); i++) {
		//printf("tetromino %d\n", i);
		answer = max(answer, findMaxSum(tetrominos[i]));
	}

	printf("%d", answer);
	return 0;
}
