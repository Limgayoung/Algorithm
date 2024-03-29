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

int N, M;

vector<vector<int>> friendG;
vector<vector<int>> enemyG;
vector<int> parent;
set<int> team;

int findParent(int a) {
	if (parent[a] == a) return a;

	return parent[a] = findParent(parent[a]);
}

void makeUnion(int a, int b) {
	int pa = findParent(a);
	int pb = findParent(b);

	parent[pb] = pa;
}

int main() {

	scanf("%d", &N);
	scanf("%d", &M);

	friendG = vector<vector<int>>(N+1, vector<int>());
	enemyG = vector<vector<int>>(N+1, vector<int>());
	parent = vector<int>(N + 1);

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		char r;
		int a, b;
		getchar();
		scanf("%c", &r);
		scanf("%d %d", &a, &b);

		if (r == 'E') {
			enemyG[a].push_back(b);
			enemyG[b].push_back(a);
		}
		else {
			friendG[a].push_back(b);
			friendG[b].push_back(a);
		}
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 0; j < friendG[i].size(); j++) { //친구 -> 한 팀
			makeUnion(i, friendG[i][j]);
		}
		for (int j = 0; j < enemyG[i].size(); j++) { //원수 -> 원수의 원수와 한 팀
			int e = enemyG[i][j];
			for (int k = 0; k < enemyG[e].size(); k++) {
				makeUnion(i, enemyG[e][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		team.insert(findParent(i));
	}

	printf("%d", team.size());
	
	return 0;
}
