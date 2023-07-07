#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>

using namespace std;

#define MAX_INT 300000000

int map[1001][1001];

int main()
{
    int N, M, X;
    int a, b, t;
    int i, j, k;
    int maxDist = 0;

    scanf("%d %d %d", &N, &M, &X);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (i == j) {
                map[i][j] = 0;
                continue;
            }
            map[i][j] = MAX_INT;
        }
    }

    for (i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &t);
        map[a][b] = t;
    }

    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }

    for (i = 1; i <= N; i++) {
        maxDist = max(maxDist, map[i][X] + map[X][i]);
    }

    printf("%d", maxDist);

    return 0;
}

/*

*/
