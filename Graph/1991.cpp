#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

pair<int, int> G[27];//최대 노드 수 26
int N;

int ischar(char a) {
	if (a >= 'A' && a <= 'Z') return 1;
	else return 0;
}

void printTree(){
	for (int i = 0; i < N; i++) {
		printf("%c %c %c\n", i + 'A', G[i].first + 'A', G[i].second + 'A');
	}
	printf("\n");
}

void printFrontTree(int index) {

	if (index > N) return;
	
	printf("%c", index + 'A');
	if (G[index].first != -1) { //왼쪽
		printFrontTree(G[index].first);
	}
	if (G[index].second != -1) {
		printFrontTree(G[index].second);
	}

}
void printMidTree(int index) {
	if (index > N) return;

	if (G[index].first != -1) { //왼쪽
		printMidTree(G[index].first);
	}
	printf("%c", index + 'A');
	if (G[index].second != -1) {
		printMidTree(G[index].second);
	}
}
void printBackTree(int index) {
	if (index > N) return;

	if (G[index].first != -1) { //왼쪽
		printBackTree(G[index].first);
	}

	if (G[index].second != -1) {
		printBackTree(G[index].second);
	}
	printf("%c", index + 'A');
}

int main() {
	scanf("%d", &N);
	int left, right;
	getchar();
	//입력
	for (int i = 0; i < N; i++) {
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar();
		left = right = -1; //아무것도 없으면 -1		
		if (ischar(b) == 1) { //왼쪽
			left = b - 'A';			
		}
		if (ischar(c) == 1) { //오른쪽
			right = c - 'A';
		}
		G[a-'A'].first = left;
		G[a-'A'].second = right;
	}
	//printTree();

	printFrontTree(0);
	printf("\n");
	printMidTree(0);
	printf("\n");
	printBackTree(0);

}

/*
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
*/
