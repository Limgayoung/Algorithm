#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
N <= 1000000
정렬 후 그리디

1. before end 값이 now start보다 큼
	now end - before end 만큼 길이 증가
2. before end 값이 now start보다 작음
	now end - now start 만큼 길이 증가
*/

int N;
vector<pair<int, int>> arr;

int main()
{
	scanf("%d", &N);

	arr = vector<pair<int, int>>(N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = { a,b };
	}

	sort(arr.begin(), arr.end());

	int beforeEnd, nowStart, nowEnd;
	int answer = 0;

	beforeEnd = arr[0].second;
	answer = abs(arr[0].second - arr[0].first);
	for (int i = 1; i < N; i++) {
		//printf("answer: %d\n", answer);
		
		int nowStart = arr[i].first;
		int nowEnd = arr[i].second;
		//printf("beforeEnd: %d nowStart: %d nowEnd: %d\n", beforeEnd, nowStart, nowEnd);
		
		if (beforeEnd >= nowStart) {
			if (nowEnd > beforeEnd) {
				answer += (nowEnd - beforeEnd);
			}
		}
		else {
			if (nowEnd > beforeEnd) {
				answer += (nowEnd - nowStart);
			}
		}

		beforeEnd = max(beforeEnd, nowEnd);
	}

	printf("%d", answer);
}

/*
3
1 6
2 3
4 5
5
*/
