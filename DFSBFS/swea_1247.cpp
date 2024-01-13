#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <math.h>
#include <vector>

using namespace std;

int N;
int hx, hy, wx, wy; //집, 회사 좌표
int cusMap[11][2]; //고객 좌표
int minDist;
int visit[11];

int calDistance(int sx, int sy, int ex, int ey){
    return abs(sx-ex) + abs(sy-ey);
}

void dfs(int x, int y, int dist, int cnt){
    if(cnt == N){ //마지막
        dist += calDistance(x,y,hx,hy);
        if(minDist > dist) minDist = dist;
        return;
    }

    for(int i=0;i<N;i++){ //모든 집 순회
        if(visit[i] == 0){
            int nx = cusMap[i][0];
            int ny = cusMap[i][1];
            int distance = calDistance(x,y,nx,ny);
            visit[i] = 1;            
            dfs(nx,ny,dist+distance,cnt+1);
            visit[i] = 0;
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
        cin >> N;
        cin >> wx >> wy >> hx >> hy;
        minDist = 987654321;
        int x,y;
        for(int i=0;i<N;i++){
            cin >> x >> y;
            cusMap[i][0] = x;
            cusMap[i][1] = y;
        }                
        
        fill(&visit[0], &visit[10], 0);
        dfs(wx,wy,0,0);
        
        printf("#%d %d\n",test_case, minDist);
	}

	return 0;
}
