#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;

vector<int> g[300001];
int dist[300001]; //각 노드까지 가는 최단거리


void dijk(int start) {
	queue<int> pq;
	int nowNode, nextNode;	

	fill(dist, dist + N + 1, -1); //-1이면 방문하지 않은 것

	pq.push(start);
	dist[start] = 0;

	while (!pq.empty()) {
		nowNode = pq.front();
			
		pq.pop();

		for (int i = 0; i < g[nowNode].size(); i++) { //연결된 노드 확인			
			nextNode = g[nowNode][i];
			if (dist[nextNode] == -1) {				
				dist[nextNode] = dist[nowNode] + 1;
				pq.push(nextNode);
			}			
		}
	}
}



int main() {
	int i;
	int a, b;
	int f=0;

	scanf("%d %d %d %d", &N, &M, &K, &X);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);		
	}

	dijk(X);

	for (i = 1; i <= N; i++) {
		if (dist[i] == K) {
			printf("%d\n", i);
			f = 1;
		}
	}
	if (f == 0) printf("-1");

}


/*
4 4 2 1 
1 2 
1 3 
2 3 
2 4
*/
