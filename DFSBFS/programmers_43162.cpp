#include <string>
#include <vector>

using namespace std;

int visit[201] = {0};

vector<int> G[201];

void dfs(int n){
    visit[n] = 1;

    for(int i=0;i<G[n].size();i++){
        int nextNode = G[n][i];
        if(visit[nextNode] == 0){
            dfs(nextNode);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers.size();j++){
            if(i == j) continue;
            if(computers[i][j] == 1){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    
    for(int i=0;i<computers.size();i++){
        if(visit[i] == 0){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}
