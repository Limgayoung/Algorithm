#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool VPS() {
	int i;
	char x[51];
	int flag = 0;
	stack<char> s;

	scanf("%s", x);
	for (i = 0; i < strlen(x); i++) {
		if (x[i] == '(') {
			s.push(x[i]);
		}
		else if (!s.empty()) {
			s.pop();
		}
		else {
			flag = 1;
			break;
		}
	}

	if (s.empty() && flag == 0) {
		return true;
	}
	else return false;
}

int main() {
	int N;
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		if (VPS()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
