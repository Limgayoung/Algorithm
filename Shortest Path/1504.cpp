#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>

using namespace std;

#define MAX_INT 300000000

long long map[801][801]; 

int main()
{
    int N, E;
    int i, j, k;
    int a, b, c;
    int u, v;
    long long minDist;

    scanf("%d %d", &N, &E);

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            if (i == j) {
                map[i][j] = 0;
                continue;
            }
            map[i][j] = MAX_INT;
        }
    }

    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
        map[b][a] = c;
    }
    
    scanf("%d %d", &u, &v);

    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }

    minDist = map[1][u] + map[u][v] + map[v][N];
    minDist = min(minDist, map[1][v] + map[v][u] + map[u][N]);

    if (minDist >= MAX_INT) printf("-1");    
    else printf("%.lld", minDist);

    return 0;
}

/*
4 3
1 2 2
1 3 1
2 4 3
1 3

7
*/
