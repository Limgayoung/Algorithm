#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>

using namespace std;

vector<pair<int, int>> T[100001]; //정점, 거리
int visit[100001] = { 0 }; //방문 정보
int sumMax=0;
int maxNode=1;

void dfs(int index, int sum) {
    int i;

    visit[index] = 1;
    if (sumMax < sum) { 
        sumMax = sum; 
        maxNode = index;
    }

    for (i = 0; i < T[index].size(); i++) {
        if (visit[T[index][i].first] == 0) { //방문하지 않았다면 확인
            dfs(T[index][i].first, sum + T[index][i].second);
        }
    }
}

int main()
{
    int V;
    int i;
    int n;
    int a, b; //정점, 거리

    scanf("%d", &V);

    for (i = 0; i < V; i++) {
        scanf("%d", &n);
        while (1) {
            scanf("%d", &a);
            if (a == -1) break;
            scanf("%d", &b);            
            T[n].push_back(make_pair(a, b));
        }
    }

    dfs(1, 0);
    fill(visit, visit + 100001, 0);
    dfs(maxNode, 0);

    printf("%d", sumMax);

    return 0;
}

/*

5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1

11


4
2 1 5 -1
1 2 5 3 9 -1
3 1 9 4 8 -1
4 3 8 -1

22
*/
