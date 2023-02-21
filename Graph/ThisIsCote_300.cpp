#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> edge; //w, a,b -> 간선을 가중치 기준으로 정렬해야 하기 때문
//최소신장트리의 간선이 가중치 순서대로 들어 있고, 가중치를 저장함 
//여기에 저장되어 있는 간선만 남기고 나머지 간선은 필요 없음 + treeWeight[N] 또한 필요 없음(그래프를 2개로 나눌 때 가장 비싼 간선을 버리면 됨)
int parent[100001]; //각 정점의 부모

void initParent(int N); //parent를 자기 자신으로 초기화
bool isUnion(int a, int b); //a와 b가 같은 그룹인지 확인
void makeUnion(int a, int b); //a와 b를 합치기
int findParent(int a); //a의 부모 찾기
int minTreeSum = 0; //최소신장 트리의 가중치 합 (마지막 가중치 제외)
int lastWeight; //마지막 가중치

void kruskal(int N, int M); //최소 신장 트리 만들기

int main() {

	int N, M;
	int i;
	int A, B, C;
	int originSum=0; //맨 처음 그래프의 모든 간선의 가중치 합

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);				
		edge.push_back({ C,A,B });
		originSum += C;
	}
	
	kruskal(N, M);

	printf("%d", minTreeSum - lastWeight);

}

void initParent(int N) {
	int i;
	for (i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

bool isUnion(int a, int b) {
	int pa, pb;

	pa = findParent(a);
	pb = findParent(b);
	if (pa == pb) return true;
	else return false;
}

void makeUnion(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else parent[a] = b;
}

int findParent(int a) {
	if (parent[a] != a) { //상위 조상이 존재함
		parent[a] = findParent(parent[a]);
	}

	return parent[a];
}

void kruskal(int N, int M) { //M개의 간선을 하나씩 조사하기 start와 end가 union인지, 아니면 union 만들고 tree에 넣기
	int i;
	int a, b, w;

	//간선 sort 해주기
	sort(edge.begin(), edge.end());	

	//parent 값 초기화
	initParent(N);

	for (i = 0; i < M; i++) {
		w = get<0>(edge[i]);
		a = get<1>(edge[i]);
		b = get<2>(edge[i]);

		if (!isUnion(a,b)) { //union이 아니면
			makeUnion(a, b); //그룹 만들기
			minTreeSum += w;
			lastWeight = w;
			//printf("make i: %d  a: %d  b: %d  w: %d\n",i,a,b,w);
		}
	}

}


/*
7 12 
1 2 3 
1 3 2 
3 2 1 
2 5 2 
3 4 4 
7 3 6 
5 1 5 
1 6 2 
6 4 1 
6 5 3 
4 5 3 
6 7 4
*/#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> edge; //w, a,b -> 간선을 가중치 기준으로 정렬해야 하기 때문
//최소신장트리의 간선이 가중치 순서대로 들어 있고, 가중치를 저장함 
//여기에 저장되어 있는 간선만 남기고 나머지 간선은 필요 없음 + treeWeight[N] 또한 필요 없음(그래프를 2개로 나눌 때 가장 비싼 간선을 버리면 됨)
int parent[100001]; //각 정점의 부모

void initParent(int N); //parent를 자기 자신으로 초기화
bool isUnion(int a, int b); //a와 b가 같은 그룹인지 확인
void makeUnion(int a, int b); //a와 b를 합치기
int findParent(int a); //a의 부모 찾기
int minTreeSum = 0; //최소신장 트리의 가중치 합 (마지막 가중치 제외)
int lastWeight; //마지막 가중치

void kruskal(int N, int M); //최소 신장 트리 만들기

int main() {

	int N, M;
	int i;
	int A, B, C;
	int originSum=0; //맨 처음 그래프의 모든 간선의 가중치 합

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);				
		edge.push_back({ C,A,B });
		originSum += C;
	}
	
	kruskal(N, M);

	printf("%d", minTreeSum - lastWeight);

}

void initParent(int N) {
	int i;
	for (i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

bool isUnion(int a, int b) {
	int pa, pb;

	pa = findParent(a);
	pb = findParent(b);
	if (pa == pb) return true;
	else return false;
}

void makeUnion(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else parent[a] = b;
}

int findParent(int a) {
	if (parent[a] != a) { //상위 조상이 존재함
		parent[a] = findParent(parent[a]);
	}

	return parent[a];
}

void kruskal(int N, int M) { //M개의 간선을 하나씩 조사하기 start와 end가 union인지, 아니면 union 만들고 tree에 넣기
	int i;
	int a, b, w;

	//간선 sort 해주기
	sort(edge.begin(), edge.end());	

	//parent 값 초기화
	initParent(N);

	for (i = 0; i < M; i++) {
		w = get<0>(edge[i]);
		a = get<1>(edge[i]);
		b = get<2>(edge[i]);

		if (!isUnion(a,b)) { //union이 아니면
			makeUnion(a, b); //그룹 만들기
			minTreeSum += w;
			lastWeight = w;
			//printf("make i: %d  a: %d  b: %d  w: %d\n",i,a,b,w);
		}
	}

}


/*
7 12 
1 2 3 
1 3 2 
3 2 1 
2 5 2 
3 4 4 
7 3 6 
5 1 5 
1 6 2 
6 4 1 
6 5 3 
4 5 3 
6 7 4
*/
