#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

int N,M;
int color[1001] = {0}; //0: 색칠안됨  1: 색1  2: 색2
bool isPossible = true;
int visit[1001] = {0};
vector<vector<int>> G(1001);

int findNextColor(int nowColor){
    if(nowColor == 1) return 2;
    else return 1;
}

void dfs(int n){
    
    if(color[n] == 0){ //아직 색칠 안됨 (맨 처음 노드)
        color[n] = 1;
    }
    
    int nowColor = color[n];
    int mustNextColor = findNextColor(nowColor);
    visit[n] = 1;
    
    for(int i=0;i<G[n].size();i++){
        int nextNode = G[n][i];
        int nextColor = color[nextNode];
        
        if(nextColor == 0){ //방문x, 색칠하면 됨
            color[nextNode] = mustNextColor;
            dfs(nextNode);
        }        
        else{
            if(nowColor == nextColor){ //불가능
                isPossible = false;
                return;
            }
            else { //가능, 방문 안했으면 dfs
                if(visit[nextNode] == 0) dfs(nextNode);
            }
        }        
    }
}

int main(int argc, char** argv)
{
    int T;
    scanf("%d",&T);        
    
   while(T--){
       scanf("%d %d",&N,&M);
       fill(&G[0], &G[1001], vector<int>(0));
       fill(color, color+1001, 0);
       fill(visit, visit+1001, 0);
       isPossible = true;
       
       for(int i=0;i<M;i++){
           int a,b;
           scanf("%d %d", &a, &b);
           G[a].push_back(b);
           G[b].push_back(a);
       }
       
       for(int i=1;i<=N;i++){
           if(visit[i] == 0) dfs(i);
           if(!isPossible) break;
       }
       
       if(isPossible) printf("possible\n");
       else printf("impossible\n");
   }
	return 0;
}
