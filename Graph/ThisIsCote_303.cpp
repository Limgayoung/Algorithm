#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_INT 
using namespace std;

vector<int> g[501]; //연결된 노드
int time[501] = { 0 };
int in[501] = { 0 }; //각 노드의 진입차수
int dist[501]; //결과
int N;

void topology() {
	queue<int> q; //진입차수 가장 낮은 노드
	int i;
	int nowNode;
	int nextNode;
	
	for (i = 1; i <= N; i++) { //처음에 진입차수 0인 노드 넣기
		if (in[i] == 0) {
			q.push(i);
		}
		dist[i] = time[i];
	}

	while (!q.empty()) {
		nowNode = q.front();
		q.pop();

		for (i = 0; i < g[nowNode].size(); i++) {
			nextNode = g[nowNode][i];
			//dist 정정
			dist[nextNode] = max(dist[nextNode], dist[nowNode] + time[nextNode]); 
			in[nextNode]--;
			if (in[nextNode] == 0) { //진입차수 0 되면 q에 push
				q.push(nextNode); 
			}
		}

	}

}

int main() {
	int t, num;
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		while (1) {
			scanf("%d", &num);
			if (num == -1) break;
			g[num].push_back(i);
			in[i]++;
		}
		time[i] = t;
	}

	topology();

	for (i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}

}



/*
5 
10 -1 
10 1 -1 
4 1 -1 
4 3 1 -1 
3 3 -1
*/
