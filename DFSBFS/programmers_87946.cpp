#include <string>
#include <vector>

using namespace std;
int maxCnt = 0;

void dfs(vector<vector<int>> dungeons, vector<int> isVisit, int index, int k, int cnt){
    if(cnt > maxCnt){ //종료조건
        maxCnt = cnt;
    }
    for(int i=0;i<dungeons.size();i++){
        if(isVisit[i] == 0){ //방문 전이면 방문
            int nextNeedK = dungeons[i][0];
            int nextUseK = dungeons[i][1];
            
            if(k >= nextNeedK){
                isVisit[i] = 1;
                dfs(dungeons, isVisit, i, k-nextUseK, cnt+1); //방문
                isVisit[i] = 0;
            }            
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //1. dfs로 모든 경우 다 해주기
    vector<int> isVisit(dungeons.size(), 0);
    
    dfs(dungeons, isVisit, 0,k,0);    

    
    answer = maxCnt;
    return answer;
}
