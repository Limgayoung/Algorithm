#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool VPS() {
	int i;
	char x[102];
	int flag = 0;
	stack<char> s;

	scanf("%[^\n]s", x);

	if (strcmp(".", x) == 0) {
		return false;
	}
	getchar();

	for (i = 0; i < strlen(x); i++) {
		if (x[i] == '(' || x[i]=='[') {
			s.push(x[i]);
		}
		else if (x[i] == ')') {
			if (!s.empty()&&s.top()!='[') {
				s.pop();
			}
			else {
				flag = 1;
				break;
			}
		}
		else if (x[i] == ']') {
			if (!s.empty() && s.top() != '(') {
				s.pop();
			}
			else {
				flag = 1;
				break;
			}
		}
	}

	if (s.empty() && flag == 0) {
		printf("yes\n");
	}
	else printf("no\n");

	return true;
}

int main() {
	bool run = true;


	while (run) {
		run = VPS();
	}

	return 0;
}
