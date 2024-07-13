#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/*
1. 그래프 만들기
2. 생성한 그래프에서 정점부터 이어진 노드를 트리로 만들기
3. 각 노드의 서브트리 크기 구하기
*/

int N, R, Q;
vector<vector<int>> G;
vector<bool> visit;
vector<vector<int>> T;
vector<int> subTreeSize;

void makeTree() {
	//root 부터 탐색하면서 연결된 노드 넣기
	queue<int> q; //node, level
	q.push(R);
	visit[R] = true;

	while (!q.empty()) {
		int nowNode = q.front();
		q.pop();

		for (int i = 0; i < G[nowNode].size(); i++) {
			int nextNode = G[nowNode][i];
			if (visit[nextNode]) continue;

			q.push(nextNode);
			visit[nextNode] = true;
			T[nowNode].push_back(nextNode);
		}
	}
}

int calSubTree(int n) {

	if (T[n].size() == 0) return 1;
	
	int sum=subTreeSize[n];
	for (int i = 0; i < T[n].size(); i++) {
		sum += calSubTree(T[n][i]);
	}

	subTreeSize[n] = sum;
	return sum;
}

int main()
{
	scanf("%d %d %d", &N, &R, &Q);

	G = vector<vector<int>>(N + 1);
	T = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1, false);
	subTreeSize = vector<int>(N + 1, 1);

	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	makeTree();
	calSubTree(R);
	
	for (int i = 0; i < Q; i++) {
		//printf("=========================\n");
		int n;
		scanf("%d", &n);
		printf("%d\n", subTreeSize[n]);
	}

	//printf("===========전체 subTreeSize 출력============\n");
	//for (int i = 1; i <= N; i++) {
	//	printf("%d ", subTreeSize[i]);
	//}
}

/*

*/
