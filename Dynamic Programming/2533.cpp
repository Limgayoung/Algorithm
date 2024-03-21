#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <set>

#define MAX_INT 10000000
using namespace std;

/*
1. findParent -> in이 0인 곳 찾기
2. dp inf로 init
3. leaf 노드부터 거슬러 올라가면서 dp 수행 -> 레벨 별로 돌려야 함
	- leaf 노드 찾는 방법 - size가 0인 곳 찾기
	- dp[i][0]: i번째 선택 안했을 때 필요한 얼리어답터 수 (자식 선택x, 자식 선택o 둘다 가능 -> min 값)
	- dp[i][1]: i번째 선택했을 때 필요한 얼리어답터 수 (+1 해줘야 함)
*/

int N;
vector<vector<int>> G;
vector<vector<int>> dp;
vector<bool> visit;


int dfs(int n) { //후위순회 하면서 dp 갱신
	visit[n] = true;

	int newDp0 = 0, newDp1 = 1;
	for (int i = 0; i < G[n].size(); i++) {
		int nextNode = G[n][i];		

		if (!visit[nextNode]) {
			dfs(nextNode);
			newDp0 += dp[nextNode][1];
			newDp1 += min(dp[nextNode][0], dp[nextNode][1]);
		}

		
	}
	dp[n][0] = min(dp[n][0], newDp0);
	dp[n][1] = min(dp[n][1], newDp1);
	return min(dp[n][0], dp[n][1]);
}

int main() {
	
	int a, b;

	scanf("%d", &N);
	
	G = vector<vector<int>>(N + 1, vector<int>());
	dp = vector<vector<int>>(N + 1, vector<int>(2, MAX_INT));
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int answer = dfs(1);

	printf("%d", answer);

	return 0;
}

/*
*/
