#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int cnt = 0;
int G[101][101] = {0};
int N;

void dfs(vector<int> isVisit, int start){
    isVisit[start] = 1;
    cnt++;
    
    for(int i=1;i<=N;i++){
        if(G[start][i] == 1 && isVisit[i] == 0){
            dfs(isVisit, i);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    N = n;
    //그래프 만들기
    for(vector<int> wire:wires){
        int a = wire[0];
        int b = wire[1];
        G[a][b] = 1;
        G[b][a] = 1;
    }
    
    //연결 하나씩 끊고, 개수 세기
    for(vector<int> wire:wires){
        int a = wire[0];
        int b = wire[1];
        G[a][b] = 0;
        G[b][a] = 0;
        vector<int> isVisit(n+1, 0);
        dfs(isVisit, a);
        int left = cnt;
        int right = n-cnt;
        
        answer = min(answer, abs(left - right));
        cnt = 0;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    
    
    return answer;
}
