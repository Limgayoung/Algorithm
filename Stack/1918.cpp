#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

/*

*/

using namespace std;

int main() {

	string str;
	stack<char> s;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i]);
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') { //(를 만날 때까지 전부 빼줘야 함
			while (s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '-' || str[i] == '+') { // ( 전까지 전부 출력해야 함 -> *,/를 먼저 출력하기 위해서
			while (!s.empty() && s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			}
			s.push(str[i]);

		}
		else if (str[i] == '*' || str[i] == '/') { //앞에 있는 것이 *,/이면 빼주고 stack에 넣어야 함
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				printf("%c", s.top());
				s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}

	return 0;
}

/*

*/
