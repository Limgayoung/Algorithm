#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int dp[200001];
int nx[3] = { 1,-1,2 };

pair<int, int> findMinTime() {
	priority_queue<pair<int,int>> pq; //time, node
	int minTime, cnt;
	minTime = -1;
	cnt = 0;
	dp[N] = 0;

	pq.push({ 0,N });

	while (!pq.empty()) {
		int nowTime = -pq.top().first;
		int nowNode = pq.top().second;
		pq.pop();
		//printf("nowNode: %d time: %d\n", nowNode, nowTime);
		if (nowNode == K) {
			minTime = nowTime;
			cnt = 1;
			while (!pq.empty()) {				
				//printf("nowNode: %d time: %d\n", pq.top().second, -pq.top().first);
				if (-pq.top().first == nowTime) {
					if (pq.top().second == nowNode) {
						cnt++;						
					}
				}
				else {
					break;
				}
				pq.pop();
			}
			return { minTime, cnt };
		}
		//dp보다 작거나 같을때만 push
		for (int i = 0; i < 3; i++) {
			int nextNode;
			if (nx[i] == 2) {
				nextNode = nowNode * 2;
			}
			else {
				nextNode = nowNode + nx[i];
			}
			if (nextNode > 200000) continue;
			if (dp[nextNode] >= dp[nowNode] + 1) {				
				dp[nextNode] = dp[nowNode] + 1;				
				pq.push({ -(nowTime + 1), nextNode });
			}			
		}
	}
	
	return { minTime, cnt };
}

int main(int argc, char** argv)
{
	scanf("%d %d", &N, &K);

	fill(&dp[0], &dp[200000], 100001);

	pair<int,int> answer = findMinTime();

	printf("%d\n%d", answer.first, answer.second);

	return 0;
}
