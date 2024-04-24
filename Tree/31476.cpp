#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
양갈래 블롭
레벨순회

포니테일 블롭
중위순회

1. 연결 끊어진 곳은 모두 visit true로 바꾸기
	end에서부터 거슬러 올라가면서 start까지 true로 변경
2. 모든 visit가 true가 될 때까지 순회
*/

int D, N, U, T;
vector<vector<int>> G;
vector<int> parent;
int lastNum;
int ponyCnt, twinCnt;
int ponyLast=1;

void printParent() {
	for (int i = 1; i < lastNum; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n------------------\n");
}

void makeTree() {
	queue<int> q;
	q.push(1);

	int n = 2;
	parent[1] = 1;
	while (n<lastNum) {
		int nowNum = q.front();
		q.pop();

		G[nowNum].push_back(n);
		G[nowNum].push_back(n+1);
		parent[n] = nowNum;
		parent[n + 1] = nowNum;
		
		q.push(n);
		q.push(n + 1);

		n += 2;
	}
}

void makeDisconnect(int s, int e) {

	int n = e;
	while (true) {		

		if (n % 2 == 0)
			G[parent[n]][0] = -1;
		else G[parent[n]][1] = -1;

		n = parent[n];
		
		if (n == s)
			break;
	}
}

void ponySearch(int n) {
	ponyLast = n;

	if(G[n].size()>0) {
		if (G[n][0] != -1) {
			ponyCnt += U;
			ponySearch(G[n][0]);
		}

		if (G[n][1] != -1) {
			ponyCnt += U;
			ponySearch(G[n][1]);
		}
	}

	
	ponyCnt += U;
}

void twinSearch(int start) {
	queue<pair<int,int>> q; //node, level
	q.push({ start,0});

	int beforeLevel = 0;
	bool isSeperate = false;
	int seperateCnt = 0;
	while (!q.empty()) {
		int n = q.front().first;
		int nowLevel = q.front().second;
		q.pop();

		if (beforeLevel != nowLevel) {			
			if (isSeperate) seperateCnt++;
			twinCnt += (U + T * seperateCnt);			
			beforeLevel = nowLevel;			
			isSeperate = false;
		}
		
		int cnt = 0;
		for (int i = 0; i < G[n].size(); i++) {			
			int nextNode = G[n][i];
			if (nextNode != -1) {
				q.push({ nextNode,nowLevel + 1 });
				cnt++;
			}
		}
		if (cnt == 2) {		
			isSeperate = true;
		}
	}
}

int calDoubleSum(int n) {
	int result = 0;

	while (true) {
		if (n == 1) break;
		result += U;
		n = parent[n];
	}

	//1도 두번 체크됨
	result += U;

	return result;
}

int main() {

	scanf("%d %d %d %d", &D, &N, &U, &T);
	lastNum = pow(2, D);
	G = vector<vector<int>>(lastNum, vector<int>());
	parent = vector<int>(lastNum, false);

	makeTree();
	//printParent();

	//끊어진 구간
	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		makeDisconnect(s, e);
	}
	ponyCnt = 0;
	twinCnt = 0;

	//포니테일 순회
	ponySearch(1);

	ponyCnt -= calDoubleSum(ponyLast);

	twinSearch(1);

	if (ponyCnt > twinCnt)
		printf(":blob_twintail_aww:");
	else if (ponyCnt < twinCnt)
		printf(":blob_twintail_sad:");
	else
		printf(":blob_twintail_thinking:");
	return 0;
}

/*
4 3 1 4
2 5
3 7
3 6
*/
