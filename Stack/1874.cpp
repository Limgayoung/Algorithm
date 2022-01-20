#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int N;

	stack<int> num;
	queue<char> oper; //+- 저장할 스택
	int i, x, flag=0;
	int n = 0;
	num.push(0);

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		
		while (!flag) {
			if (x > n) {
				n++;
				num.push(n);
				oper.push('+');
			}
			else if (x > num.top() && x < n) {
				flag = 1;
				break;
			}
			else if (x < num.top()) {
				num.pop();
				oper.push('-');

			}
			else if(x==num.top()){
				num.pop();
				oper.push('-');
				break;
			}
		}
	}

	if (!flag) {
		while (!oper.empty()) {
			printf("%c\n", oper.front());
			oper.pop();
		}
	}
	else printf("NO");


	return 0;
}
