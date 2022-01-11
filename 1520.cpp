#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int N, M;
int m[501][501];
int dp[501][501]; //경로 개수 저장
int mx[4] = { 0,0,-1,1 }; //map에서 상,하,좌,우로 이동
int my[4] = { 1,-1,0,0 };

int DFS(int x, int y) { //좌표 입력받기

    if (x == N-1 && y == M-1) {//종료 조건
        return 1;
    }
    if (dp[x][y] != -1) {
        return dp[x][y]; //dp값이 이미 있으면 return
    }

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        //새로운 좌표 nx, ny
        int nx = x + mx[i];
        int ny = y + my[i];
        
        if (nx >= 0 && ny >= 0 && nx <= N && ny <= M) {//좌표값이 범위를 벗어나지 않으면
            if (m[nx][ny] < m[x][y]) { //새로운 좌표가 작을 경우에만 이동하기
                dp[x][y] = dp[x][y] + DFS(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {

    int i, j;
    int answer;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &m[i][j]);
            dp[i][j] = -1; //dp 값을 -1로 초기화
        }
    }
    answer = DFS(0, 0);

    printf("%d", answer);

    return 0;
}
