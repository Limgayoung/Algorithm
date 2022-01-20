#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>

using namespace std;

int main() {

	int T;
	char x[100002];
	char num[700000];
	int n;
	int i, j;

	deque<int> q;

	bool flag;
	bool Dflag;
	int qsize = 0;

	scanf("%d", &T);

	int len;
	
	for (i = 0; i < T; i++) {
		scanf("%s", x);
		scanf("%d", &n);
		scanf("%s", num);

		flag = true;
		Dflag = false;

		//숫자 q에 입력
		if (n != 0) {
			len = strlen(num);
			for (j = 0; j < len; j++) {
				if (num[j] == '[' || num[j] == ',') { //숫자 만들기
					q.push_back(atoi(&num[j + 1]));
				}
				else if (num[j] == ']') break;
			}
		}

		//명령 수행
		len = strlen(x);
		for (j = 0; j < len; j++) {
			if (x[j] == 'R') {
				flag = !(flag);
			}
			else if(x[j]=='D'){
				if (q.empty()) {
					Dflag = true;
					break;
				}
				else {
					if (flag) {
						q.pop_front();
					}
					else q.pop_back();
				}
			}
		}

		//출력
		if (Dflag) {
			printf("error\n");
			continue;
		}

		qsize = q.size();
		printf("[");
		if (flag) {
			for (j = 0; j < qsize; j++) {
				printf("%d", q.front());
				q.pop_front();
				if (j != qsize - 1) printf(",");
			}
		}
		else {
			for (j = 0; j < qsize; j++) {
				printf("%d", q.back());
				q.pop_back();
				if (j != qsize - 1) printf(",");
			}
		}
		printf("]\n");
		

	}

	return 0;
}
