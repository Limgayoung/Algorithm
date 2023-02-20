  #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, X, K; //회사 개수, 경로 개수, 목적지1, 목적지2 (1~X + X~K 찾는 문제)
int g[102][102] = { 0 };
int dist[102];
int visit[102] = { 0 }; //방문 여부


int findMin(int start, int dest) {
	priority_queue<pair<int, int>> pq; //dist, node 저장
	pair<int, int> nowNode;
	int i;

	for (i = 1; i <= N; i++) {
		dist[i] = 0;
		visit[i] = 0;
	}

	pq.push(make_pair(0, start)); //1 넣기 
	dist[start] = 0;

	while (!pq.empty()) {

		nowNode = pq.top();
		dist[nowNode.second] = nowNode.first;
		pq.pop();
		if (nowNode.second == dest) return dist[dest];

		for (i = nowNode.second; i <= dest; i++) {
			if (visit[i] == 0 && g[nowNode.second][i] == 1) { //방문 전이고 연결되어 있으면
				//printf("push node: %d dist: %d\n",i, nowNode.first + 1);
				pq.push(make_pair(nowNode.first + 1, i));
				visit[i] = 1;
			}
		}
	}
	return 101;
}

int main() {
	int i, j;
	int a, b;

	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
		dist[i + 1] = 101; //최댓값으로 초기화
	}
	scanf("%d %d", &X, &K);

	priority_queue<pair<int,int>> pq; //dist, node 저장

	pq.push(make_pair(0,1)); //1 넣기 
	dist[1] = 0;

	int firstMin, secondMin;

	firstMin = findMin(1, K);
	
	if (X < K)	secondMin = findMin(X, K);
	else secondMin = findMin(K, X);

	if (firstMin == 101 || secondMin == 101) printf("-1");
	else printf("%d", firstMin + secondMin);
	
}

/*
5 7 
1 2 
1 3 
1 4 
2 4 
3 4 
3 5 
4 5 
4 5

4 2 
1 3 
2 4 
3 4
*/
