#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> G[20001];
int dist[20001]; //1번 노드와의 거리
int maxDist = 0;

void findDist(int start){
    queue<pair<int,int>> q; //node, dist
    
    q.push({start,0});
    
    while(!q.empty()){
        int nowNode = q.front().first;
        int nowDist = q.front().second;
        q.pop();
        //printf("nowNode: %d nowDist: %d\n",nowNode, nowDist);
        maxDist = max(maxDist, nowDist);
        
        for(int i=0;i<G[nowNode].size();i++){
        int nextNode = G[nowNode][i];
        
            if(dist[nextNode] == 0 && nextNode != 1){ //방문 전
                dist[nextNode] = nowDist+1;
                q.push({nextNode, nowDist+1});
            }
        }
    }
  
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    //그래프 만들기
    for(vector<int> e:edge){
        int a = e[0];
        int b = e[1];
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    findDist(1);
      
    /*
    for(int i=1;i<=n;i++){
        printf("%d ",dist[i]);
    }
    printf("\n");
    */
    
    for(int i=1;i<=n;i++){
        if(dist[i] == maxDist){
            answer++;
        }
    }
    
    return answer;
}
