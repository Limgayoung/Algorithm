#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

/*
아기상어는 크기가 작은 물고기만 먹을 수 있다.
크기가 같은 물고기 : 지나갈 수 있음 -> 거리 계산 시 PQ로 bfs 돌려서 계산해야함
(각 거리를 arr에 저장하고 bfs 종료 후 최솟값 찾기)

먹을 수 있는 물고기 1마리 -> 먹으러 감
먹을 수 있는 물고기 2마리 이상 -> 거리 가장 가까운 물고기
	거리 : 지나야 하는 칸 개수 최솟값
	가까운 물고기 많으면 가장 위, 가장 왼쪽 물고기

이동은 1초 걸림
자신의 크기와 같은 수 먹을 때마다 크기 1 증가
*/

typedef struct info {
	int x;
	int y;
	int d;
}info;

struct compare {
	bool operator()(const info& s1, const info& s2) {
		return s1.d > s2.d;
	}
};

using namespace std;
int N;
vector<vector<int>> map;
vector<vector<int>> dist;

pair<int, int> shark; //아기상어 위치
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minDist;

void printMap() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printDist() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

vector<pair<int,int>> calSharkToFishDist(int size) { //아기상어 위치에서 각 물고기까지의 거리 계산
	priority_queue<info, vector<info>, compare> pq;

	pq.push({ shark.first, shark.second, 0 });

	minDist = 987654321;
	vector<pair<int, int>> result = vector<pair<int, int>>();
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int d = pq.top().d;
		if (minDist == 987654321 && map[x][y] < size && map[x][y] != 0 && map[x][y] != 9) { //현재 dist가 가장 가까움
			//printf("nowDist: %d x: %d y: %d\n", d, x, y);
			minDist = d;
		}
		if (minDist != 987654321) { //최소 거리가 초기화 된 상태이고
			if(d != minDist) break;
			else if (map[x][y] != 0 && map[x][y]<size && map[x][y] != 9) { //먹을 수 있다면
				result.push_back({ x,y });
			}
		}
		
		pq.pop();

		for (int i = 0; i < 4; i++) { //4방향
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny]<=size && dist[nx][ny] == -1) {
				dist[nx][ny] = d + 1;
				pq.push({ nx,ny,d + 1 });
			}
		}
	}
	
	return result;
}

pair<int,int> findMinFishPosition(int size) {

	fill(dist.begin(), dist.end(), vector<int>(N, -1));
	dist[shark.first][shark.second] = -9; //아기상어 위치

	vector<pair<int,int>> minDistPosi = calSharkToFishDist(size);

	pair<int, int> minPosi = { -1,-1 };
	//minDist = 987654321;

	if (minDistPosi.size() == 0) {
		//printf("end!\n");
		return minPosi;
	}
	minPosi = minDistPosi[0];	
	
	for (pair<int, int> p : minDistPosi) {
		if (p.first < minPosi.first) { //더 위에 있음
			minPosi = p;
		}
		else if (p.first == minPosi.first) { //같은 행에 위치
			if (p.second < minPosi.second) { //더 왼쪽에 있음
				minPosi = p;
			}
		}
	}

	return minPosi;
}

int main()
{
	scanf("%d", &N);

	map = vector<vector<int>>(N, vector<int>(N));
	dist = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				shark = { i,j };
			}
		}
	}

	int nowSize = 2;
	int eatNum = 0;
	int time = 0;
	while (true) {
		pair<int,int> nextPosi = findMinFishPosition(nowSize);
		if (nextPosi.first == -1 && nextPosi.second == -1) {
			break;
		}
		map[shark.first][shark.second] = 0;
		shark.first = nextPosi.first;
		shark.second = nextPosi.second;
		eatNum++;
		time += minDist;		
		map[shark.first][shark.second] = 9;
		if (eatNum == nowSize) {
			nowSize++;
			eatNum = 0;
		}
	}

	printf("%d", time);

	return 0;
}

/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 9 1 1 1 1 1 1 1 1 1 1

*/
