#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int parent[100001] = { 0 };

int find_parent(int a, int b) { //항상 a<b 인 값이 들어온다
	if (parent[b] != b) { //한 집합 안에 있을수도 있음
		parent[b] = find_parent(a, parent[b]);
	}
	return parent[b];
}

void make_union(int a,int b) {

	a = find_parent(parent[a], a);
	b = find_parent(parent[b], b);

	if (a < b) {
		parent[b] = a;
	}
	else parent[a] = b;
}

int main() {
	int N, M;
	int i;
	int oper, a, b;
	int compareP, p;

	scanf("%d %d", &N, &M);

	for (i = 0; i <= M; i++) { //처음에 parent를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &oper, &a, &b);
		if (oper == 0) {
			make_union(a, b);
		}
		else if (oper == 1) {
			if (a < b) {
				p = find_parent(a, b); //b의 parent가 p
				compareP = a;
			}
			else {
				p = find_parent(b, a); //a의 parent가 p
				compareP = b;
			}
			if (p == compareP) printf("YES\n");
			else printf("NO\n");

		}
	}

}

/*
7 8 
0 1 3 
1 1 7 
0 7 6 
1 7 1 
0 3 7 
0 4 2 
0 1 1 
1 1 1
*/
