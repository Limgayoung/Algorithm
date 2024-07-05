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
N <= 100000
공정 라인을 몇 개 사용할건지 구해야 함
공정 라인 개수를 이분탐색 l=1, r=100000
	PQ 사용
	번호, 끝나는 시간 pair로 저장
	5 2 8 4 3 5
	PQ : 
		{0,5}, {1,2}, {2,8} -> {1,2} {0,5} {2,8}
		{1,6}, {0,5} {2,8} -> {0,5} {1,6} {2,8}
		{0,8} {1,6} {2,8} -> {1,6} {0,8} {2,8}
		{1,11} {0,8} {2,8}
		pop 하면서 최대 시간 구하기 -> 11
*/

typedef struct info {
	long long endTime;
}info;

struct compare {
	bool operator()(const info& a, const info& b) {
		return a.endTime > b.endTime;
	}
};

long long N, X;
vector<long long> times;


//n개의 공정 라인을 이용했을 때 걸리는 시간
long long calTime(int n) {
	priority_queue<info, vector<info>, compare> pq;

	if (n == 0) return 987654321;

	for (int i = 0; i < n; i++) {
		long long t = times[i];
		pq.push({ t });
	}

	for (int i = n; i < N; i++) {
		long long nowEnd = pq.top().endTime;
		pq.pop();
		long long t = nowEnd + times[i];
		pq.push({ t });
	}

	long long maxTime = 0;
	while(!pq.empty()) {
		//printf("%d ", pq.top());
		maxTime = max(maxTime, pq.top().endTime);
		pq.pop();
	}
	return maxTime;
}

int main()
{
	scanf("%lld %lld", &N, &X);
	times = vector<long long>(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &times[i]);
	}

	int l = 0;
	int r = N-1;
	int answer = N;
	while (l <= r) {		
		int m = (l + r) / 2;
		long long nowTime = calTime(m);
		//printf("l: %d r: %d nowTime: %d\n", l, r, nowTime);
		if (m > N) {
			m = N - 1;
		}
		if (nowTime > X) {
			l = m + 1;
		}
		else{
			r = m - 1;
			answer = min(answer, m);
		}
	}
	printf("%lld", answer);
}

/*

*/
