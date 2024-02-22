#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
i원으로 얻기 가능한 고객 수를 dp로 구하기

dp[i] = max(dp[i-N[0].num]+N[0].cost , ... , dp[i-N[N-1].num]+N[N-1].cost)

*/

#define MAX_DP 100001

int dp[MAX_DP] = { 0 }; //i원으로 얻을 수 있는 고객 수
int C, N;

void printDP() {
	for (int i = 0; i <= C; i++) {
		printf("dp[%d]: %d\n", i, dp[i]);
	}
}
int main()
{


	scanf("%d %d", &C, &N); //만들어야 하는 고객 수, 도시 수
	vector<pair<int, int>> infos(N); //비용, 고객 수

	//dp 초기화
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &infos[i].first, &infos[i].second);
		dp[infos[i].first] = max(dp[infos[i].first], infos[i].second); 
	}

	dp[0] = 0;	

	//dp 구하기
	for (int i = 1; i <= MAX_DP; i++) { //비용
		for (int j = 0; j < N; j++) { //각 도시마다 확인
			int nowCost = infos[j].first;
			int nowPeopleNum = infos[j].second;
			int index = i - nowCost; //현재 비용 사용
			//printf("i: %d index: %d\n", i, index);
			if (index < 0) {
				//printf("continue!!\n");
				continue;
			}

			dp[i] = max(dp[i], dp[index] + nowPeopleNum);
		}
		if (dp[i] >= C) {
			printf("%d\n", i);
			break;
		}
	}

	//printDP();

	return 0;
}

/*
1000 1
100 1
100000
*/
