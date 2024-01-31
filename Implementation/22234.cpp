#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct info {
	int id;
	int t;
	int c;
}info;

bool compare(info a, info b) {
	return a.c < b.c;
}

int N, T, W, M; 

queue<pair<int, int>> q; //손님 id, 남은 시간

int main()
{
	//영업 전 들어온 손님 수, 한 번에 할당 가능한 시간, 출력 시간, 영업 후 들어온 손님 수
	scanf("%d %d %d", &N, &T, &W);

	int p, t, c; //손님 id, 일처리 걸리는 시간, 영업 시간 c초 후 들어옴

	//영업 전에 들어온 손님 -> queue에 순서대로 넣을 수 있음
	for (int i = 0; i < N; i++) { //0초일 때 대기큐의 앞에 있는 고객
		scanf("%d %d", &p, &t);
		q.push({ p,t });
	}

	scanf("%d", &M);
	//영업 후에 들어온 손님 -> list 저장 후 들어온 시간 순으로 정렬
	//시간에 맞게 순서대로 queue에 넣을 수 있음
	vector<info> customers(M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &p, &t, &c);
		customers[i].id = p;
		customers[i].t = t;
		customers[i].c = c;
	}

	sort(customers.begin(), customers.end(), compare);

	//1초 마다 출력
	int time = 0;
	int nowCustomer = q.front().first;
	int nowCustomerTime = q.front().second;
	q.pop();
	int j = 0;

	for (int i = 0; i < W; i++) {
		//영업 이후 들어온 손님 들여보내기
		if (j < customers.size() && customers[j].c-1 == i) {
			q.push({ customers[j].id, customers[j].t });
			j++;
		}

		printf("%d\n", nowCustomer);
		nowCustomerTime--;
		if (nowCustomerTime == 0) { //현재 손님 완료
			time = 0;
			if (q.empty()) continue;
			nowCustomer = q.front().first;
			nowCustomerTime = q.front().second;
			q.pop();
			continue;
		}
		time++;
		if (time == T) { //다음 손님으로 넘겨야 함
			q.push({ nowCustomer, nowCustomerTime });
			nowCustomer = q.front().first;
			nowCustomerTime = q.front().second;
			q.pop();
			time = 0;
		}
	}


	return 0;
}

/*
1 5 7
1 6
1
3 1 5

1 5 7
1 6
3
3 1 5
2 1 7
4 1 3
*/
