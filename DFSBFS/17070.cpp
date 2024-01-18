#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
int map[20][20];

//가로 세로 대각선
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int answer = 0;

bool isInside(int x, int y) {
    if (x < N && y < N && x >= 0 && y >= 0) return true;
    return false;
}

bool isNotWall(int x, int y, int dir) {
    if (map[x][y] != 0) return false;

    if (dir == 2) { // 대각선 방향, 3곳 체킹 필요
        // 위, 왼쪽
        if (map[x - 1][y] != 0 || map[x][y - 1] != 0) return false;
    }

    return true;
}

void dfs(int x, int y, int dir) {
    if (x == N - 1 && y == N - 1) {
        answer++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (dir == 0 && i == 1) continue;
        if (dir == 1 && i == 0) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && isNotWall(nx, ny, i)) {
            dfs(nx, ny, i);
        }
    }
}

int main(int argc, char** argv)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    dfs(0, 1, 0);

    printf("%d", answer);


    return 0;
}
