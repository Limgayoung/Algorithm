#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[21][21];
int dp[21][21];

//왼쪽 위, 왼쪽 아래, 왼쪽 옆
int dx[3] = { 1,-1,0 };
int dy[3] = { -1,-1,-1 };

int main() {
	int T;
	int n, m;
	int i,j,k;
	int sum;
	int result=0;

	scanf("%d", &T);

	while(T--) {
		scanf("%d %d", &n, &m);

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = map[i][j]; //dp 초기화
			}			
		}

		//dp 생성
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {

				for (k = 0; k < 3; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						sum = map[j][i] + dp[nx][ny];
						dp[j][i] = max(sum, dp[j][i]);
					}
				}
			}
		}
		/*
		printf("map\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}

		printf("dp\n");
		for (i = 0; i < n; i++) {			
			for (j = 0; j < m; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
		*/
		for (i = 0; i < n; i++) {
			if (result < dp[i][m-1]) {
				result = dp[i][m - 1];
			}
		}

		printf("%d\n", result);
		result = 0;
	}

}


/*
2 
3 4 
1 3 3 2 2 1 4 1 0 6 4 7 
4 4 
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
*/
