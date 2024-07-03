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
1초
N <= 100 (지역 개수)
m <= 15 (수색범위)
r <= 100 (길 개수)
양방향 그래프
수색범위 안에서 얻을 수 있는 최대 아이템 수 구하기 -> N번 반복해야함
한 번 탐색 - 100 * 100 = 10000
플루이드 워셜로 ? 100 * 100 * 100 = 1000000 가능함
*/

int N, m, r;
vector<int> items;
vector<vector<int>> arr;
int answer = 0;

int main()
{
	scanf("%d %d %d", &N, &m, &r);
	items = vector<int>(N+1);
	arr = vector<vector<int>>(N+1, vector<int>(N+1, 987654321));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &items[i]);
	}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		arr[a][b] = l;
		arr[b][a] = l;		
	}

	for (int i = 1; i <= N; i++) {
		arr[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}

	//각 N의 item 수 계산
	for (int i = 1; i <= N; i++) {
		int nowItem = 0;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] <= m) nowItem += items[j];
		}
		answer = max(nowItem, answer);
	}

	printf("%d", answer);

}

/*

*/
