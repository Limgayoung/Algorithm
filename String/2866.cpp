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

alfa
beta
zeta
문자열 열로 읽어서 안겹치면 행 삭제, count++ -> 반복
set에 넣고 count 1이면 겹치는 것
1000 * 1000 -> 1000000

1. 문자열 세로로 잘라서 저장
2. 중복 검사
	set에 넣으면서 count

*/

int R, C;

vector<string> arr, colArr;
set<string> strSet;
bool flag = false;
int answer = 0;

int main()
{
	scanf("%d %d", &R, &C);

	arr = vector<string>(R);
	colArr = vector<string>(C);

	for (int i = 0; i < R; i++) {
		cin >> arr[i];			
		
	}

	//문자열 세로로 잘라서 저장
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			colArr[i] += arr[j][i];
		}
	}

	//맨 앞 글자 자르기
	for (int j = 0; j < C; j++) {
		colArr[j] = colArr[j].substr(1, colArr[j].length());
	}

	//중복 검사하면서 한 줄씩 자르기
	for (int i = 1; i < R; i++) {
		//printf("=======================\n");
		for (int j = 0; j < C; j++) {
			//cout << colArr[j] << endl;
			if (strSet.count(colArr[j]) > 0) { //검사 종료
				flag = true;
				break;
			}

			strSet.insert(colArr[j]);
		}
		if (flag) break;
		answer++;

		if (colArr[0].length() == 1) { //더 이상 자를 수 없음			
			break;
		}

		//맨 앞 글자 자르기
		for (int j = 0; j < C; j++) {
			colArr[j] = colArr[j].substr(1, colArr[j].length());
		}
		strSet.clear();
	}

	printf("%d", answer);
}

/*

*/
