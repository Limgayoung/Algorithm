#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[1000001];
int maxNodeNum;
int edgeNum, nodeNum;

int in[1000001] = {0}; //진입 노드 개수, 0인 곳이 시작 지점
int visit[1000001] = {0};

void printIn(int maxNodeNum){
    for(int i=1;i<=maxNodeNum;i++){
        printf("%d ",in[i]);
    }
    printf("\n\n");
}

void dfs(int n){
    visit[n] = 1;    
    nodeNum++;
    
    for(int i=0;i<G[n].size();i++){
        int nextNode = G[n][i];
        if(visit[nextNode] == 0){
            dfs(nextNode);
        }
        edgeNum++;
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    int rootNode;
    
    maxNodeNum = edges[0][0];
    
    for(vector<int> edge:edges){
        int a = edge[0];
        int b = edge[1];
        
        G[a].push_back(b);
        in[b]++;        
        int maxNode = max(a,b);
        if(maxNodeNum < maxNode) maxNodeNum = maxNode;
    }
    
    //시작 지점 찾기, 0인게 여러개 있을 수 있음 -> 무조건 막대 시작점이거나, root거나
    //in이 0이고 size가 2 이상인 정점!
    for(int i=1;i<maxNodeNum;i++){
        if(in[i] == 0 && G[i].size() > 1) {
            rootNode = i;
        }
    }
    
    //rootNode와 연결된 node들 dfs 해서 도넛/막대/8자 확인    
    answer[0] = rootNode;

    for(int i=0;i<G[rootNode].size();i++){
        edgeNum = 0;
        nodeNum = 0;    
        int nextNode = G[rootNode][i];
        if(visit[nextNode] == 1) continue;
        dfs(nextNode);
        if(edgeNum == nodeNum){ //도넛
            answer[1]++;
        }
        else if(edgeNum+1 == nodeNum){ //막대
            answer[2]++;
        }
        else{ //8자
            answer[3]++;
        }
    }
    
    return answer;
}

