#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_INT 2000000000

int N, M, C;
vector<pair<int, int>> g[30001]; //연결된 node의 node 번호와 걸리는 time
int dist[30002]; //C부터 n까지 도달하는 데 걸리는 시간 -> MAX로 초기화 해줘야 함

void dijk(int start) {//각 n까지의 최소 시간을 다익스트라를 통해 저장
	priority_queue<pair<int, int>> pq; //time, node -> time을 기준으로 정렬돼야 해서	
	int nowNode, nowTime;
	int i;

	pq.push(make_pair(0, start));
	dist[start] = 0; //시작점에서 시작점까지 걸리는 시간은 0

	while (!pq.empty()) {
		nowNode = pq.top().second; //현재 노드
		nowTime = pq.top().first; //지금까지 걸린 시간
		pq.pop();

		//printf("nowNode: %d nowTime: %d nowDist: %d\n", nowNode, nowTime, dist[nowNode]);
		if (nowTime > dist[nowNode]) continue; //이미 보장된 노드 //이 조건이 없다면 양방향일 경우 영원히 탐색함

		for (i = 0; i < g[nowNode].size(); i++) { //연결된 모든 노드 탐색
			int nextNode = g[nowNode][i].first;
			int cost = g[nowNode][i].second + nowTime; //다음 노드까지 걸리는 시간은 nowNode에서 다음 노드까지 걸리는 시간 + nowNode까지 걸린 시간
			if (cost < dist[nextNode]) dist[nextNode] = cost; //nowNode를 거쳐서 nextNode로 가는 시간 < C에서 바로 nextNode로 가는 시간 인 경우 dist값 수정
			//printf("nowNode: %d nextNode: %d cost: %d dist[nextNode]: %d\n", nowNode, nextNode, cost, dist[nextNode]);

			pq.push(make_pair(dist[nextNode], nextNode));
		}
	}

} 

int main() {
	int X, Y, Z;
	int i;
	int cnt = 0, time=0;

	scanf("%d %d %d", &N, &M, &C); //도시 개수, 통로 개수, 시작점

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &X, &Y, &Z);
		g[X].push_back(make_pair(Y, Z));
	}
	
	fill(dist, dist + N+1, MAX_INT);

	dijk(C);

	for (i = 1; i <= N; i++) {
		if (dist[i] != MAX_INT) {
			cnt++;
			if (dist[i] > time) {
				time = dist[i];
			}
		}
	}

	printf("%d %d", cnt-1, time); //start는 제외하고 세야 함
}

/*
3 2 1 
1 2 4 
1 3 2
*/
