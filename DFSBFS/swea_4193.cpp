#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <queue>

#define INT_MAX 98765432

using namespace std;

typedef struct info{
    int time;
    int x;
    int y;
}info;

struct compare{
	bool operator()(const info &info1, const info &info2){
     	return info1.time > info2.time;   
    }
};

int N;
int minTime;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

info makeInfo(int x, int y, int time){
    info i;
    i.x = x;
    i.y = y;
    i.time = time;
    return i;
}

bool isInsideMap(int x, int y){
    if(x >= 0 && y >= 0 && x < N && y < N) return true;
    else return false;
}

void bfs(int x, int y, vector<vector<int>> map, int endX, int endY){
 	priority_queue<info, vector<info>, compare> pq;
    vector<vector<int>> visit(N, vector<int>(N,0));
    visit[x][y] = 1;
	pq.push(makeInfo(x,y,0));
    
    while(!pq.empty()){
        info nowInfo = pq.top();
        int x = nowInfo.x;
        int y = nowInfo.y;
        int time = nowInfo.time;
        visit[x][y] = 1;
        pq.pop();
        
        if(x == endX && y == endY){
            minTime = time;
            return;
        }
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInsideMap(nx,ny) && visit[nx][ny] == 0 && map[nx][ny] != 1){
                if(map[nx][ny] == 0) pq.push(makeInfo(nx,ny,time+1));
                else if(map[nx][ny] == 2){
                    //소용돌이 언제 열리는지 시간 계산
                    pq.push(makeInfo(nx,ny,time+ 2 - time%3 + 1));                    
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d",&N);
        vector<vector<int>> map(N,vector<int>(N));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int startX, startY, endX, endY;
        scanf("%d %d",&startX, &startY);
        scanf("%d %d",&endX, &endY);

        minTime = INT_MAX;
        bfs(startX, startY, map, endX, endY);
        if(minTime == INT_MAX) minTime = -1;
        
        printf("#%d %d\n",test_case, minTime);
	}
	return 0;
}
