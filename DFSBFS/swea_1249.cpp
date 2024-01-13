#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <string>

using namespace std;       

int N;
int map[101][101];
int visit[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int minTime;

void printMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isInside(int x,int y){
	if(x >= 0 && y >= 0 && x < N && y < N) return true;
    return false;
}

void bfs(int x, int y){
	priority_queue<pair<int,pair<int,int>>> pq;
    
    pq.push({0,{x,y}});
    
    while(!pq.empty()){
        int nowTime = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        visit[x][y] = 1;
        pq.pop();
        
        if(x == N-1 && y == N-1){
            minTime = nowTime;
            break;
        }                
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isInside(nx,ny) && visit[nx][ny] == 0){
				int nextTime = nowTime + map[nx][ny];
                pq.push({-nextTime, {nx,ny}});
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
        string s;
        minTime = 98765432;
        fill(&map[0][0], &map[100][100], 0);
        fill(&visit[0][0], &visit[100][100], 0);
        for(int i=0;i<N;i++){
            cin>>s;
            for(int j=0;j<N;j++){         		
                map[i][j] = s[j]-'0';
            }
        }
        
        bfs(0,0);

		//printMap();        
        printf("#%d %d\n",test_case, minTime);


	}
	return 0;
}
