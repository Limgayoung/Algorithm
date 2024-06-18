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
제한시간 1초
N, M <= 100
T <= 10000

상하좌우 이동 가능
벽을 뚫을 수 없음
그람 찾으면 벽 뚫고 가기 가능
1. 그람 찾지 않고 공주에게 바로 가는 경우
  - 중간에 그람이 나온다면 벽 뚫기 가능
2. 그람부터 찾고 공주에게 가는 경우

성공 시 최단 시간 구하기

*/

typedef struct info {
	int x;
	int y;
	int cnt;
	bool hasGram;
}info;

int N, M, T;
vector<vector<int>> arr;
vector<vector<bool>> visit;
pair<int, int> gram; //그람 위치

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int isDone = false;

bool isInside(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

int getMinTime(int destX, int destY) {
	queue<info> q;

	q.push({ 0,0,0,false });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		bool hasGram = q.front().hasGram;
		q.pop();

		if (x == destX && y == destY) { //목적지 도달했다면 return (목적지는 그람까지 일수도, 공주까지 일수도 있음)	
			isDone = true;
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInside(nx, ny) && !visit[nx][ny]) {
				if (!hasGram && arr[nx][ny] == 1) continue;
				visit[nx][ny] = true;
				q.push({ nx,ny,cnt + 1 });
			}
		}
	}	
	return 987654321;
}

int main()
{
	scanf("%d %d %d", &N, &M, &T);

	arr = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	gram = { -1,-1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				gram = { i,j };
			}
		}
	}

	int findGramTime = 987654321;
	if (gram.first != -1) {
		findGramTime = getMinTime(gram.first, gram.second);
		//printf("gram만: %d\n", findGramTime);
		findGramTime += (abs(N - 1 - gram.first) + abs(M - 1 - gram.second));
	}
	//fill(&visit[0][0], &visit[N-1][M], false);
	visit = vector<vector<bool>>(N, vector<bool>(M, false));

	int findPrincessTime = getMinTime(N - 1, M - 1);

	int answer = min(findGramTime, findPrincessTime);

	//printf("gram: %d princess: %d\n", findGramTime, findPrincessTime);

	if (answer <= T && isDone) printf("%d", answer);
	else printf("Fail");

}

/*
4 4 10
0 0 0 0
0 0 1 0
0 1 2 1
0 0 0 0
*/
