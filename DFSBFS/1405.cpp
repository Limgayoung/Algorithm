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

*/

int N;
int prob[4]; //동서남북 확률
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[100][100];
double answer = 0;

double dfs(int x, int y, int cnt) {
	
	if (cnt == N) {
		//printf("x: :%d y: %d cnt: %d\n", x, y, cnt);		
		return 1.0;
	}

	double result = 0.0;
	visit[x][y] = true;

	//4방향 탐색
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny] || prob[i] == 0) continue;
		
		result = result + (prob[i]/100.0) * dfs(nx, ny, cnt + 1);				
	}
	visit[x][y] = false;

	return result;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &prob[i]);
	}

	visit[50][50] = true;
	answer = dfs(50,50,0);
	
	cout.precision(10);
	cout << fixed << answer << endl;
}

/*

*/
