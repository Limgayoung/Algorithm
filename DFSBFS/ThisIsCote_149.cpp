#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>

using namespace std;

int g[1001][1001];
int N, M;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[1001][1001] = { 0 };

void dfs(int x, int y) {
	int i;
	int nx, ny;

	visit[x][y] = 1;	

	for (i = 0; i < 4; i++) { //4방향
		nx = x + dx[i];
		ny = y + dy[i];		
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {			
			if (visit[nx][ny] == 0 && g[nx][ny]==0) {				
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int i, j;
	char input[1001];
	int cnt = 0;

	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++) {
		scanf("%s", input);
		for (j = 0; j < M; j++) {
			g[i][j] = input[j] - '0';
		}
	}

	//dfs
	stack<int> s;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (visit[i][j] == 0 && g[i][j] == 0) {
				dfs(i,j);
				cnt++;
			}
		}
	}

	printf("%d", cnt);
}

/*
4 5 
00110
00011
11111
00000

15 14 
00000111100000 
11111101111110 
11011101101110 
11011101100000 
11011111111111 
11011111111100 
11000000011111 
01111111111111 
00000000011111 
01111111111000 
00011111111000 
00000001111000 
11111111110011 
11100011111111 
11100011111111
*/
