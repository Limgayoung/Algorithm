#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*

N : 3~9
-> 길이 최대 9

연산 : +, -, ' '(이어붙이기 = originNum*10+nowNum)
완전탐색
3^9
*/

int N;

int calExpression(string expression) {
	vector<int> n;
	vector<char> oper;

	int num = 0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '+' || expression[i] == '-') {
			n.push_back(num);
			oper.push_back(expression[i]);			
			num = 0;
		}
		else if(expression[i] == ' '){
			num *= 10;						
		}
		else {
			num += expression[i] - '0';
		}
	}
	n.push_back(num);
	/*printf("n 분리\n");
	for (int i = 0; i < n.size(); i++) {
		printf("%d ", n[i]);
	}
	printf("\n");*/
	int result = n[0];

	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == '+') {
			result += n[i + 1];
		}
		else if (oper[i] == '-') {
			result -= n[i + 1];
		}
	}

	return result;
}

void makeExpression(string expression, int index) {
	//printf("index: %d\n", index);
	if (index > N) {
		if (calExpression(expression) == 0) {
			cout << expression << endl;
		}
		return;
	}
	
	makeExpression(expression + " " + to_string(index), index + 1);
	makeExpression(expression + "+" + to_string(index), index+1);
	makeExpression(expression + "-" + to_string(index), index+1);	
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		makeExpression("1", 2);
		printf("\n");
	}

}

/*
1
3
0 -1
0 -3
0 -5
3 1 2 3

1
3
0 1
0 3
0 5
3 1 2 3
*/
