#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*

입력만 됨
1. 맨 앞에 추가하기
2. 오름차순 정렬하기
2. 순서 뒤집기

정렬 명령어는 맨 뒤의 한 번만 실행하면 됨 -> 전체 중 1번만 정렬됨
정렬 명령어 맨 마지막 순서만 저장, 그전까지는 맨 앞 추가만 실행
정렬 이후부터는 deque 이용해 맨 앞 추가, 순서 뒤집기-> point 위치만 바꿔주면 됨

업무 번호 범위 제한 : 100000
명령 1000개

*/

int N, Q, k;
vector<int> arr; //정렬 전 저장
deque<int> d; 
vector<pair<int, int>> oper; //연산자 저장
int lastSortIndex; //마지막 정렬 위치
bool isFront; //true -> 포인터가 앞, fasle -> 포인터가 뒤

int main() {

	scanf("%d %d %d", &N, &Q, &k);

	oper = vector<pair<int, int>>(Q);

	lastSortIndex = Q + 1;
	for (int i = 0; i < Q; i++) {
		int type, num;
		num = -1;
		scanf("%d", &type);
		if (type == 0) {
			scanf("%d", &num);
		}
		oper[i] = { type, num };
		if (type == 1) {
			lastSortIndex = i;
		}
	}

	isFront = true;

	//lastSortIndex 전까지는 arr에 저장, 이후에는 deque에 저장
	if (lastSortIndex == Q + 1) { //정렬이 한 번도 나오지 않을 경우
		for (int i = 0; i < Q; i++) {
			if (oper[i].first == 0) {
				if (isFront) d.push_front(oper[i].second);
				else d.push_back(oper[i].second);
			}
			else {
				if (isFront) isFront = false;
				else isFront = true;
			}
		}
	}
	else {
		for (int i = 0; i < Q; i++) {
			if (i < lastSortIndex) { //arr에 넣기
				if (oper[i].first == 0) {
					arr.push_back(oper[i].second);
				}
				else if (oper[i].first == 2) {
					if (isFront) isFront = false;
					else isFront = true;
				}
			}
			else if (i == lastSortIndex) { // 1번 정렬 후 deque에 넣기
				sort(arr.begin(), arr.end());
				for (int i = 0; i < arr.size(); i++) {
					d.push_back(arr[i]);
					isFront = true;
				}
			}
			else { //deque에 저장			
				if (oper[i].first == 0) {
					if (isFront) d.push_front(oper[i].second);
					else d.push_back(oper[i].second);
				}
				else {
					if (isFront) isFront = false;
					else isFront = true;
				}
			}
		}
	}

	/*
	printf("\n---------------------\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", d.back());
		d.pop_back();
	}
	*/
	


	for (int i = 0; i < k-1; i++) {
		if (isFront) {
			d.pop_front();
		}
		else {
			d.pop_back();
		}
	}

	int answer;

	if (isFront) answer = d.front();
	else answer = d.back();

	printf("%d", answer);
	
	return 0;
}

/*

7 11 7
0 1
0 2
2
0 3
1
0 4
2
0 5
0 6
2
0 7

7 8 7
0 1
0 2
0 3
0 4
0 5
0 6
0 7
2
1
1
1


1 3 1
0 1
1
2
*/
