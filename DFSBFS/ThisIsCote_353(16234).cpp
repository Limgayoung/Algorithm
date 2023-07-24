#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>

using namespace std;

int N, L, R;
int map[51][51];
int visit[51][51];
int flag;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sumPeople;
stack<pair<int, int>> s;

void printMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int x,int y) {
    visit[x][y] = 1;
    s.push({ x,y });
    sumPeople += map[x][y];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == 0) {
            int diff = abs(map[x][y] - map[nx][ny]);
            if (diff >= L && diff <= R) {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{

    int i, j;
    int changeNum;
    int answer = 0;

    scanf("%d %d %d", &N, &L, &R);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    flag = 1;
    while (flag == 1) {
        flag = 0;
        fill(&visit[0][0], &visit[N][N], 0);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (visit[i][j] != 1) {
                    sumPeople = 0;
                    dfs(i, j);
                    if (s.size() == 1) {
                        s.pop();
                        continue;
                    }
                    else {
                        changeNum = sumPeople / s.size();
                        while (!s.empty()) {
                            map[s.top().first][s.top().second] = changeNum;
                            s.pop();
                            flag = 1;
                        }
                    }
                }
            }
        }
        if (flag == 0) break;
        answer++;
        //printMap();
    }

    printf("%d", answer);

    return 0;
}

/*
2 20 50
50 30
20 40
*/
