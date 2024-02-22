#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
1. root, giga 노드 구하기
	- 연결된 노드가 2 이상인 것 : root (tree 아닌 그래프는 입력 아님)
2. dfs로 돌면서 length 구하기
	- 마지막 노드일 경우에 maxLength 갱신
*/

typedef struct Node {
	int n;
	int weight;
}Node;

int N, R; //노드 개수, 루트 번호
vector<vector<Node>> G;
vector<bool> visit;
int rootLength = 0, gigaLenght = 0;

int findGiga(int nowNode, int length, int cnt) { //root에서부터 탐색 시작

	//printf("nowNode: %d\n", nowNode);
	if (G[nowNode].size() > 2 || cnt >= N-1) { //giga node
		rootLength = length;
		return nowNode;
	}

	visit[nowNode] = true;
	
	if (nowNode == R) { //맨 앞이 루트면서 기가인 경우
		int nodeCnt = 0;
		for (int i = 0; i < G[nowNode].size(); i++) {
			if (nodeCnt > 0) {
				visit[nowNode] = false;
				return nowNode;
			}
			if (!visit[G[nowNode][i].n]) {
				nodeCnt++;
			}
		}
	}

	for (int i = 0; i < G[nowNode].size(); i++) {
		int nextNode = G[nowNode][i].n;
		int nextWeight = G[nowNode][i].weight;
		if (!visit[nextNode]) {
			return findGiga(nextNode, length + nextWeight, cnt+1);
		}
	}
}

void dfs(int nowNode, int length) {
	if (G[nowNode].size() < 2) { //마지막 노드
		gigaLenght = max(length, gigaLenght);
		return;
	}

	visit[nowNode] = true;

	for (int i = 0; i < G[nowNode].size(); i++) {
		int nextNode = G[nowNode][i].n;
		int nextWeight = G[nowNode][i].weight;
		if (!visit[nextNode]) {
			dfs(nextNode, length + nextWeight);
		}
	}
}

int main()
{

	scanf("%d %d", &N, &R);

	G = vector<vector<Node>>(N + 1, vector<Node>());
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);

		G[a].push_back({ b,d });
		G[b].push_back({ a,d });
	}

	int giga = findGiga(R, 0, 0);
	//printf("giga: %d\n", giga);

	dfs(giga, 0);

	printf("%d %d", rootLength, gigaLenght);

	return 0;
}

/*
5 1
1 2 100
2 3 10
3 4 1
1 5 7
*/
