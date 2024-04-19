#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
가장자리 정점을 '동시에' 없애는 행동 반복 -> 일직선 모양 만들기
가장자리 정점이 2개 이하로 남았을 때 일직선이 됨
이때부터는 더이상 가장자리 정점 없애지 않는다.

1. in, out 만들기	
2. 초기 가장자리 정점 queue 생성
	in, out이 모두 1인 정점 -> 가장자리 정점
3. 가장자리 정점 제거
	1) 가장자리 정점을 queue에 담기
	2) queue에 담긴 정점을 제거, 제거 후 연결된 정점의 in/out이 1이 된다면 queue에 담기
		제거 - 간선의 visit를 true로
	3) 반복하다가 해당 level의 queue size가 2 이하가 되면 끝
*/

typedef struct Node {
	int a; //삭제할 정점
	int b; //연결된 정점
	int level; //레벨
}node;

int N;
vector<vector<int>> G;
vector<int> in, out;
queue<node> leaf;
vector<bool> visit;

void initLeaf() {
	for (int i = 0; i < N; i++) {
		if (in[i] == 1 && out[i] == 1) {
			leaf.push({ i,G[i][0], 0 });
			//printf("%d ", i);
		}
	}
}

void deleteLeaf() {
	//2) queue에 담긴 정점을 제거, 제거 후 연결된 정점의 in/out이 1이 된다면 queue에 담기
	//제거 - 간선의 visit를 true로
	//3) 반복하다가 해당 level의 queue size가 2 이하가 되면 끝
	int beforeLevel = -1;
	bool isDone = false;
	while (!leaf.empty()) {
		node nowNode = leaf.front();

		int a = nowNode.a;
		int b = nowNode.b;
		int level = nowNode.level;

		if (beforeLevel != level) { //다음 레벨로 넘어감
			if (leaf.size() <= 2) { //끝!
				isDone = true;
				break;
			}			
			beforeLevel = level;
		}

		//printf("%d %d %d\n", a, b, level);

		leaf.pop();

		visit[a] = true;

		in[a]--;
		out[a]--;
		in[b]--;
		out[b]--;
		if (in[b] == 1 && out[b] == 1) { //연결된 노드도 leaf 됨
			//b와 연결된 노드 찾기
			int connectB;
			int i;
			for (i = 0; i < G[b].size(); i++) {
				if (!visit[G[b][i]]) {
					connectB = G[b][i];
					break;
				}
			}
			leaf.push({ b,connectB, level + 1 });
		}
	}
}

int main() {

	scanf("%d", &N);

	G = vector<vector<int>>(N, vector<int>());
	visit = vector<bool>(N, false);
	in = vector<int>(N, 0);
	out = vector<int>(N, 0);

	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);

		in[b]++;
		out[b]++;
		in[a]++;
		out[a]++;
	}

	//2. 초기 가장자리 정점 queue 생성
	initLeaf();

	//3. 가장자리 정점 제거
	deleteLeaf();

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			printf("%d ", i);
		}
	}

	return 0;
}

/*

*/
