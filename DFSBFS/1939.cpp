#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <set>

using namespace std;

typedef struct info {
    int n;
    int weight;
}info;

int N, M;
int start, dest;
vector<vector<info>> G;
vector<bool> visit;

bool bfs(int minWeight) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //오름차순 정렬

    pq.push({ 0,start });

    bool result = false;

    while (!pq.empty()) {
        int nowNode = pq.top().second;
        int nowCnt = pq.top().first;
        pq.pop();
        //printf("nowNode: %d nowCnt: %d\n", nowNode, nowCnt);
        if (nowNode == dest) {
            result = true;
            break;
        }

        for (int i = 0; i < G[nowNode].size(); i++) {
            int nextNode = G[nowNode][i].n;
            int nextWeight = G[nowNode][i].weight;
            if (nextWeight < minWeight) continue; //다른 경로로 가야 함
            if (!visit[nextNode]) {
                visit[nextNode] = true;
                pq.push({ nowCnt + 1, nextNode });
            }
        }
    }
    return result;
}

int main() {
    int A, B, C;

    scanf("%d %d", &N, &M);

    G = vector<vector<info>>(N + 1, vector<info>());
    visit = vector<bool>(N + 1, false);
    int maxWeight = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        G[A].push_back({ B,C });
        G[B].push_back({ A,C });

        maxWeight = max(maxWeight, C);
    }

    //printf("maxWeight: %d\n", maxWeight);

    scanf("%d %d", &start, &dest);

    int l = 1;
    int r = maxWeight;
    int mid = (l + r) / 2;
    int answer = 1;

    while (l <= r) {
        fill(visit.begin(), visit.end(), false);
        int mid = (l + r) / 2;
        //printf("l: %d r: %d mid: %d\n", l, r, mid);
        if (bfs(mid)) { //해당 중량 가능함 -> 더 키우기
            l = mid + 1;
            answer = max(answer, mid);
        }
        else {
            r = mid - 1;
        }
    }

    printf("%d", answer);

    return 0;
}
