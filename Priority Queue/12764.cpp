#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
1. 시작 시각 기준 오름차순 정렬
2. PQ 사용, {종료 시간, computer num} 해당 num에 넣을 때마다 ++
3. 빈 자리 중 컴퓨터 번호 가장 작은 자리에 앉는 것이 규칙
- pq에 빈 번호 저장
*/

int N;
vector<pair<int, int>> arr;
vector<int> computer;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //종료 시간, computer num
priority_queue<int, vector<int>, greater<int>> numPq; //빈자리
int comSize = 0;

int main() {

	scanf("%d", &N);

	arr = vector<pair<int, int>>(N);
	computer = vector<int>(N, 0);

	
	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		arr[i] = { s,e };
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		
		
		int nowStartTime = arr[i].first;
		int nowEndTime = arr[i].second;

		//1. 현재 시작 시각보다 빠른 종료 시간 가진 자리 비우기
		while (!pq.empty() && pq.top().first < nowStartTime) {
			numPq.push(pq.top().second);
			pq.pop();
		}
		//2. 빈 자리가 있다면 바로 넣기
		if (!numPq.empty()) {
			int n = numPq.top();
			numPq.pop();
			pq.push({ nowEndTime, n });
			computer[n]++;
		
		}
		//3. 빈 자리가 없다면 맨 뒤에 넣기
		else {
			pq.push({ nowEndTime, comSize });
			computer[comSize]++;
			comSize++;
		}
	
	}

	printf("%d\n", comSize);
	for (int i = 0; i < comSize; i++) {
		printf("%d ", computer[i]);
	}

	return 0;
}

/*

*/
