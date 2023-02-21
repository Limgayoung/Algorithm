#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

#define MAX_INT 101

using namespace std;

int N, M, X, K; //회사 개수, 경로 개수, 목적지1, 목적지2 (1~X + X~K 찾는 문제)
int g[102][102] = { 0 };
int dist[102];


int findMin(int start, int dest) {
	priority_queue<pair<int, int>> pq; //dist, node 저장
	int nowNode, nowDist;
	int i;

	fill(dist, dist + N + 1, MAX_INT); //모든 dist를 MAX로 초기화

	pq.push(make_pair(0, start)); //시작점 넣기, 시작점은 dist가 0
	dist[start] = 0;

	while (!pq.empty()) {

		nowNode = pq.top().second;
		nowDist = pq.top().first; //지금까지 걸린 비용
		
		pq.pop();
		if (nowNode == dest) return dist[dest]; //현재 노드가 목적지 노드면 바로 리턴
		if (nowDist > dist[nowNode]) continue; //지금까지 걸린 비용 > start에서 nowNode로 바로 가는 비용 -> 이미 끝난 node라서 무시

		for (i = 1; i <= N; i++) {			
			if (g[nowNode][i] == 1) {
				int cost = nowDist + 1; //nowNode를 거쳐서 가는 비용
				if (cost < dist[i]) { //nowNode를 거쳐서 가는 비용 < start에서 i(nextNode)로 바로 가는 비용 -> nowNode를 거쳐서 가는 것으로 비용 업데이트 해야함
					dist[i] = cost;
					pq.push(make_pair(dist[i], i));
				}
			}			
		}
	}
	return MAX_INT;
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

	priority_queue<pair<int, int>> pq; //dist, node 저장

	pq.push(make_pair(0, 1)); //1 넣기 
	dist[1] = 0;

	int firstMin, secondMin;

	firstMin = findMin(1, K);

	if (X < K)	secondMin = findMin(X, K);
	else secondMin = findMin(K, X);

	if (firstMin == MAX_INT || secondMin == MAX_INT) printf("-1");
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
