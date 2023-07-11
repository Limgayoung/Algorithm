//사전문제
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_INT 2000000000

vector<pair<int,int>> g[401]; //노드, 비용
long long minSum = MAX_INT;
int status[401]; //0이면 방문 전, 1이면 탐색중, 2면 탐색 완료
int dist[401]; 
int startNode = -1;

void dfs(int nowNode, int nowCost) {
    status[nowNode] = 1;

    for (int i = 0; i < g[nowNode].size(); i++) {
        int nextNode = g[nowNode][i].first;
        int nextCost = g[nowNode][i].second;

        if ((nowCost + nextCost - dist[nextNode]) >= minSum) {
            continue;
        }

        //printf("nowNode: %d nextNode: %d\n", nowNode, nextNode);

        if (nextNode == nowNode) { //x->x
            if (minSum > nextCost) {
                minSum = nextCost;
                continue;
            }
        }

        if (status[nextNode] == 1) { //탐색 중인 노드 방문
            //cycle의 end: nowNode  start: nextNode
            int cycleCost = nowCost + nextCost - dist[nextNode];
            //printf("cycle! start: %d end: %d cycleCost: %d\n", nextNode, nowNode, cycleCost);
            if (minSum > cycleCost) {
                minSum = cycleCost;
                continue;
            }
        }
        else {
            dist[nextNode] = nowCost + nextCost;
            dfs(nextNode, dist[nextNode]);
        }
    }
    
    status[nowNode] = 2;
}

int main()
{
    int T;
    int N, M;
    int x, y, c;
    int i, j;

    scanf("%d", &T);

    for (i = 1; i <= T; i++) {  
        fill(&g[0], &g[400], vector<pair<int, int>>());        
        minSum = MAX_INT;
        fill(status, status + 401, 0);
        fill(dist, dist + 401, 0);

        scanf("%d %d", &N, &M);
        for (j = 0; j < M; j++) {
            scanf("%d %d %d", &x, &y, &c);
            g[x].push_back({ y,c });
        }

        for (j = 1; j <= N; j++) {
            startNode = -1;
            
            if (status[j] == 0) {
                //printf("-----dfs start!-----\n");
                dfs(j, 0);
            }
        }

        printf("#%d ", i);
        if (minSum >= MAX_INT) printf("-1\n");
        else printf("%lld\n", minSum);
        
    }    
    
    return 0;
}

/*
1
3 4
1 2 1
3 2 1
1 3 5
2 3 2

4 4
1 2 1
2 3 2
2 4 3
1 4 4
(-1)

4 4
1 2 1
2 3 2
2 4 3
4 1 4
(8)

3 4
1 1 2
1 2 1
2 3 1
3 1 1
(2)

6 8
1 2 1
2 3 1
3 4 1
4 6 1
3 5 1
5 4 1
6 5 1
4 3 2
(3)

6 8
1 2 1
2 3 1
3 4 1
4 6 1
3 5 1
5 4 1
6 5 1
5 2 2

8 12
1 2 1
2 3 5
3 6 1
6 7 1
7 8 2
8 6 3
8 4 5
3 4 1
4 3 7
4 2 5
3 7 1
8 3 1
(4)

3
3 4
1 2 1
3 2 1
1 3 5
2 3 2
4 4
1 2 1
2 3 2
2 4 3
1 4 4
4 4
1 2 1
2 3 2
2 4 3
4 1 4
*/
