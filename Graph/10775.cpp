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
4
3
4 1 1
가장 큰 번호에 도킹해야 한다.
4 -> 4에 도킹
1 -> 1에 도킹

2 2 3 3 4 4
2 -> 2에 도킹
2 -> 1에 도킹
3 -> 3에 도킹
3 -> 할 곳이 없음

이미 도킹한 곳은 할 수 없음 (-1한 곳부터 가능하다)
-1한 숫자를 저장 (계속 갱신)
*/

int G, P;
vector<int> parent;

int findParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = findParent(parent[a]);
}

void makeUnion(int a, int b) { //a가 b로 3이면 2로
	int pa = findParent(a);
	int pb = findParent(b);
	if (pa == pb) return;

	parent[pa] = pb;
}

int main()
{
	int answer = 0;

	scanf("%d", &G);
	scanf("%d", &P);

	parent = vector<int>(G+1);

	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < P; i++) {
		int n;
		scanf("%d", &n);

		int num = findParent(n);
		//printf("n: %d num: %d\n", n, num);

		if (num == 0) {
			break;
		}

		makeUnion(n, num - 1);
		answer++;
	}

	printf("%d", answer);
}

/*

*/
