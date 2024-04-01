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
가격의 차이가 최대 D가 되는 최대 만족도 구하기
정렬 후 투포인터
*/


int main() {
	int N, D;
	vector<pair<int, int>> arr;
	long long answer = 0;

	scanf("%d %d", &N, &D);
	arr = vector<pair<int, int>>(N);

	for (int i = 0; i < N; i++) {
		int p, v;
		scanf("%d %d", &p, &v);
		arr[i] = { p,v };
	}

	sort(arr.begin(), arr.end()); //오름차순 정렬

	//가격 차이가 D가 되도록 하는 구간 이동하면서 해당 구간 만족도 구하기
	int l = 0;
	int r = 0;
	int lPrice, rPrice;
	long long sum = 0;
	while (l<=r && r<arr.size()) {
		lPrice = arr[l].first;
		rPrice = arr[r].first;
		//printf("l: %d %d  r: %d %d\n", l, lPrice, r, rPrice);
		//D보다 작아야 다음으로 넘어가기 가능
		if (rPrice - lPrice < D) {
			sum += arr[r].second;
			r++;
		}
		else {			
			sum -= arr[l].second;
			l++;
		}
		//printf("sum: %d\n", sum);
		answer = max(answer, sum);
	}
	//answer = max(answer, sum);
	printf("%lld", answer);
	
	return 0;
}

/*
5 100
10 20
10 15
10 15
11 30
11 20

---------
l~r까지 구간합
r-l
D보다 작으면 r 늘리기
D보다 크면 l 늘리기
*/
