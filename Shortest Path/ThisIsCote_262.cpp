#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_INT 2000000000

vector<pair<int, int>> g[30001]; //연결된 정보 : node, time
int dist[30001]; //각 노드마다 가는데 걸리는 시간 (최단경로)
int isVisit[30002] = { 0 }; //방문 안한 곳이면 0
int maxTime = 0; //총 걸리는 시간
int cnt = 0; //방문한 도시 개수

void dijk(int start) {

	//시간이 오래 걸리는 순서대로 방문해야 함
	priority_queue<pair<int, int>> pq; //time, node

	pq.push(make_pair(0, start));

	int nowNode;
	int nowTime;
	int i;

	while (!pq.empty()) {
		nowNode = pq.top().second;
		nowTime = pq.top().first; //지금까지 걸린 시간		
		pq.pop();
		if (nowTime > dist[nowNode]) { //dist[nowNode]의 값이 지금까지 걸린 시간보다 작으면 이미 처리된 것
			continue;
		}
		
		for (i = 0; i < g[nowNode].size(); i++) {
			//들어가는 비용 = 현재 노드에서 다음 노드까지 가는데 걸리는 시간 + 현재까지 걸린 시간
			int cost = g[nowNode][i].second + nowTime;
			if (cost < dist[g[nowNode][i].first]) { //start에서 다음 노드로 바로 가는것보다 현재 노드를 거쳐서 가는게 더 빠를 경우 dist 변경해주기
				dist[g[nowNode][i].first] = cost;
				//printf("push cost: %d node: %d\n", cost, g[nowNode][i].first);
				pq.push(make_pair(cost, g[nowNode][i].first));

			}
		}

	}

}

int main() {

	int N, M, C;
	int i;
	int a, b, w;	

	scanf("%d %d %d", &N, &M, &C);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &w);
		g[a].push_back(make_pair(b, w));
	}

	fill(dist, dist + 30001, MAX_INT);

	dijk(C);

	for (i = 1; i <= N; i++) {
		if (dist[i] != MAX_INT) {
			cnt++;
			if (maxTime < dist[i]) maxTime = dist[i];
		}
	}

	printf("%d %d", cnt, maxTime);
	

}

/*
3 2 1 
1 2 4 
1 3 2
*/
