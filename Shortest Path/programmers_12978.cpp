#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[51][51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int a,b,c;

    fill(&dist[0][0], &dist[50][51], 1000000);
    
    for(int i=0;i<road.size();i++){
        a = road[i][0];
        b = road[i][1];
        c = road[i][2];
        if(dist[a][b] > c){
            dist[a][b] = c;
            dist[b][a] = c;
        }        
    }
    for(int i=1;i<=N;i++){
        dist[i][i] = 0;
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);            
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        //printf("dist 1 -> %d: %d\n", i,dist[1][i]);
        if(dist[1][i] <= K ) answer++;
    }

    return answer;
}
