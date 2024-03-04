#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	int parent;
	int left;
	int right;
}node;

vector<node> T;
vector<int> nodePosition;
vector<pair<int, int>> levelPosition;
int N;
int cnt = 1;
int maxWidth = 0;
int minLevel = 987654321;
int rootNode;

void findRootNode(int node) {	
	if (T[node].parent != -1) {
		findRootNode(T[node].parent);
	}
	else {
		rootNode = node;
		return;
	}
}

void traversal(int node) {
	if (node == -1) return;
	traversal(T[node].left);
	nodePosition[node] = cnt;
	cnt++;
	traversal(T[node].right);
}


void printNodePosition() {
	for (int i = 1; i <= N; i++) {
		printf("%d ", nodePosition[i]);
	}
	printf("\n");
}

void findLevelWidth(int root) {
	queue<pair<int,int>> q;
	int level = 1;
	q.push({ root, level });
	levelPosition = vector<pair<int, int>>(2, { 987654321, -1 }); //0, 1레벨은 하지 않음

	while (!q.empty()) {
		int nowNode = q.front().first;
		int nowLevel = q.front().second;
		q.pop();

		if (levelPosition.size() <= nowLevel) levelPosition.push_back({ 987654321, -1 });
		if (levelPosition[nowLevel].first > nodePosition[nowNode]) {
			levelPosition[nowLevel].first = nodePosition[nowNode];
		}
		if (levelPosition[nowLevel].second < nodePosition[nowNode]) {
			levelPosition[nowLevel].second = nodePosition[nowNode];
		}

		if (T[nowNode].left != -1) q.push({ T[nowNode].left, nowLevel + 1 });
		if (T[nowNode].right != -1) q.push({ T[nowNode].right, nowLevel + 1 });		
	}

	for (int i = 1; i < levelPosition.size(); i++) {	
		int nowWidth = levelPosition[i].second - levelPosition[i].first+1;
		//printf("%d level nowLevel width: %d\n", i, nowWidth);
		if (maxWidth < nowWidth) {
			maxWidth = nowWidth;
			minLevel = i;
		}		
	}
}

int main() {

	scanf("%d", &N);

	T = vector<node>(N + 1, { -1,0,0 });
	nodePosition = vector<int>(N + 1);

	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		T[a].left = b;
		T[a].right = c;
		if(b!=-1) T[b].parent = a;
		if(c!=-1) T[c].parent = a;
	}

	findRootNode(1);

	traversal(rootNode);
	//printNodePosition();
	findLevelWidth(rootNode);

	printf("%d %d", minLevel, maxWidth);

	return 0;
}
