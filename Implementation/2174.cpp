#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*

시뮬레이션
잘못된 명령 : 다른 로봇과 충돌, 범위 벗어나는 경우

로봇이 위치한 땅 : 1
빈 땅 : 0
으로 설정.

*/

typedef struct robot {
	int x;
	int y;
	int dir;
}robot;

//가로 세로
int A, B, N, M;
vector<robot> robots;
vector<vector<int>> map;

//NESW
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void printMap() {
	printf("-----------------------------\n");
	printf("x:   ");
	for (int i = 1; i <= A; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= B; i++) {
		printf("y: %d ", i);
		for (int j = 1; j <= A; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}

int findOtherRobot(int x, int y){
	for (int i = 0; i < N; i++) {
		if (robots[i].x == x && robots[i].y == y) {
			return i;
		}
	}
	return 0;
}

int moveRobot(int index, char oper) {	
	if (oper == 'L') { //해당 index 로봇 방향 왼쪽 90도 회전 = -1
		robots[index].dir -= 1;
		if (robots[index].dir == -1)
			robots[index].dir = 3;
	}
	else if (oper == 'R') { //해당 index 로봇 방향 오른쪽 90도 회전 = +1
		robots[index].dir = (robots[index].dir + 1) % 4;
	}
	else if (oper == 'F') { //로봇 한 칸 이동
		int nowDir = robots[index].dir;
		int nx = robots[index].x+dx[nowDir];
		int ny = robots[index].y+dy[nowDir];
		//printf("dx: %d dy: %d\n", dx[nowDir], dy[nowDir]);
		//printf("nx: %d ny: %d\n", nx, ny);
		if (nx < 1 || nx > A || ny < 1 || ny > B) return 0; //벽과 충돌
		if (map[ny][nx] == 1) { //로봇과 충돌
			return findOtherRobot(nx, ny)+1;
		}

		map[robots[index].y][robots[index].x] = 0;
		map[ny][nx] = 1;	
		robots[index].x = nx;
		robots[index].y = ny;
	}

	return -1; //성공
}

int main()
{
	scanf("%d %d", &A, &B); //가로 세로
	scanf("%d %d", &N, &M); 

	map = vector<vector<int>>(B+1, vector<int>(A+1, 0));
	robots = vector<robot>(N);

	for (int i = 0; i < N; i++) {
		int a, b;
		char d;
		scanf("%d %d %c", &a, &b, &d);
		int dir;
		if (d == 'N') dir = 0;
		else if (d == 'E') dir = 1;
		else if (d == 'S') dir = 2;
		else dir = 3;
		robots[i] = { a,b,dir };
		map[b][a] = 1;
	}

	//명령 수행
	for (int i = 0; i < M; i++) {
		int n, cnt;
		char oper;
		scanf("%d %c %d", &n, &oper, &cnt);
		//printf("명령어\n");
		for (int j = 0; j < cnt; j++) {
			int result = moveRobot(n-1, oper);
			if (result == 0) {
				printf("Robot %d crashes into the wall\n", n);
				return 0;
			}
			else if (result > 0) {
				printf("Robot %d crashes into robot %d\n", n, result);
				return 0;
			}
			//printMap();
		}
		
	}
	printf("OK\n");

}

/*

5 4
2 2
1 1 N
5 4 S
1 F 7
2 F 7


1 3
2 1
1 1 N
1 2 N
1 F 2
*/
