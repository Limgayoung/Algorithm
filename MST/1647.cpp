#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
1. union-find로 최소신장트리로 만들기
2. 가장 비싼 간선 없애서 2개로 나누기
*/

typedef struct edge {
	int a;
	int b;
	int c;
}edge;

bool compareEdge(edge o1, edge o2) {
	return o1.c < o2.c;
}

int N, M;
vector<int> parent;
vector<edge> edges;
vector<int> cost;

int findParent(int a) {
	if (parent[a] == a) return a;

	return parent[a] = findParent(parent[a]);
}

bool makeUnion(int a, int b) {
	int pa = findParent(a);
	int pb = findParent(b);

	if (pa != pb) {
		parent[pb] = pa;
		return true;
	}
	else return false;
}

int main() {
	scanf("%d %d", &N, &M);
	parent = vector<int>(N + 1);
	edges = vector<edge>(M);

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[i] = { a,b,c };
	}

	sort(edges.begin(), edges.end(), compareEdge);

	for (int i = 0; i < M; i++) {
		if (makeUnion(edges[i].a, edges[i].b)) {
			cost.push_back(edges[i].c);
		}
	}

	int maxCost = 0;
	int sumCost = 0;
	for (int i = 0; i < cost.size(); i++) {
		sumCost += cost[i];
		maxCost = max(maxCost, cost[i]);
	}

	printf("%d", sumCost - maxCost);
	return 0;
}

/*

*/
