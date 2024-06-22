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
제한시간 1초
길이 <= 1000000
문자열에 있는 PPAP를 P로 변환 반복
4글자 남았을 때(혹은 더는 변환할 수 없을 때) PPAP가 된다면 PPAP, 아니면 NP

PPPAPAP
PPAP 하나씩 찾아서 변환 -> 시간초과

PPPAP -> PPAP!
-> PP -> PPAP! -> 맞음

PPAPAPP
PPAP! -> P
-> PAPP -> 아님

stack을 사용한다면?
가장 나중에 들어온 4글자를 따로 저장해서 확인하기, 맞다면 stack에서 3글자 pop! (마지막 P는 남겨놔야 한다)
PPPA
PPAP -> 3글자 pop!
PP
PPAP -> 3글자 pop! -> P -> PPAP!!

PPAPAPP
PPAP -> pop!
P
PAPP

str = PPAP 의 뒤 3글자 + 지금 읽은 한글자 - 계속 갱신해 줘야 함

*/


int main()
{
	string str;

	cin >> str;

	stack<char> ppapStack;
	string lastStr=""; //stack의 맨 위 4글자


	for (int i = 0; i < str.length(); i++) {
		if (lastStr.length() < 4) {
			lastStr += str[i];
		}
		else { //check
			if (lastStr.compare("PPAP")==0) {
				//lastStr 갱신하기
				//PPAP P -> P P
				// -> stack에서 2개 뺀 다음에 P + str[i]
				lastStr = "";
				while (!ppapStack.empty() && lastStr.length() < 2) {
					lastStr += ppapStack.top();
					ppapStack.pop();
				}
				lastStr += "P";
				lastStr += str[i];
			}
			else {
				ppapStack.push(lastStr[0]);
				lastStr = lastStr.substr(1,4) + str[i];
			}
		}
	}

	//printf("lastStr: %s  ppapStack size: %d\n", lastStr.c_str(), ppapStack.size());
	if (lastStr.compare("PPAP") == 0 && ppapStack.empty()) printf("PPAP");
	else if (lastStr.compare("P") == 0) printf("PPAP");
	else printf("NP");

}

/*

*/
