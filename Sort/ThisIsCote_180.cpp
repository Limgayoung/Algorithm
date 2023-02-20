#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;
pair<int, string> student[100001];

int main() {
	int N;
	char name[101];
	int score;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %d", name, &score);
		printf("%s %d\n", name, score);
		student[i].first = score;
		string n = name;
		student[i].second = n;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %d\n", student[i].second.c_str(), student[i].first);
	}

	sort(student, student + N);	

	for (int i = 0; i < N; i++) {
		printf("%s ", student[i].second.c_str());
	}

}

/*
2
홍길동 95 
이순신 77
*/
