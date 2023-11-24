#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define MAX 1001
#define MAX_TRAP 10
#define MAX_INT 999999999

using namespace std;

int N;
int minTime = MAX_INT;

bool isActiveTrap(int node, int state, vector<int> isTrap){
    if((state & (1<<isTrap[node])) == false) return false;
    return true;
}

void findMinTime(int s, int e, vector<vector<vector<int>>> G, vector<int> isTrap){
    vector<vector<int>> dist(N+1, vector<int>(1<<MAX_TRAP, MAX_INT)); 
    // dist[n][state] : s부터 n까지 state하게 갔을 때 걸리는 시간
    queue<pair<int,int>> q; //현재 node, 현재 state
    
    q.push({s, 0});
    dist[s][0] = 0;
    
    while(!q.empty()){
        int nowNode = q.front().first;
        int nowState = q.front().second;
        int nowCost = dist[nowNode][nowState];
        q.pop();
        
        if(nowCost >= minTime){
            continue;
        }
        
        if(nowNode == e){
            minTime = min(minTime, nowCost);
        }                
        
        for(int i=0;i<G[nowNode].size();i++){
            int dir = G[nowNode][i][0]; //방향 0: 역방향 1: 정방향
            int nextNode = G[nowNode][i][1];
            int nextCost = G[nowNode][i][2];            
            
            int isFromTrap = isTrap[nowNode];
            int isToTrap = isTrap[nextNode];
            int cnt = 0;
            //from이 trap이고 trap이 활성 상태면
            if(isFromTrap != -1 && isActiveTrap(nowNode, nowState, isTrap)) cnt++;
            //to가 trap이고 trap이 활성 상태면
            if(isToTrap != -1 && isActiveTrap(nextNode, nowState, isTrap)) cnt++;
            //1,1 : 역방향 0,2 : 정방향
            //dir 0: 역방향, 1: 정방향
            if(cnt%2 == dir){ //현재 방향이 아닐 경우
                continue;
            }
            
            //queue에 넣기
            int nextState;
            if(isToTrap == -1){ //다음이 트랩 아님
                nextState = nowState;
            }
            else{ //다음이 트랩
                nextState = nowState ^ (1<<isToTrap); //XOR 연산을 해서 활성/비활성 
            }
            
            if(dist[nextNode][nextState] > dist[nowNode][nowState] + nextCost){
                dist[nextNode][nextState] = dist[nowNode][nowState] + nextCost;
                q.push({nextNode, nextState});
            }
            
        }
    }
    
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    N = n;
    vector<vector<vector<int>>> G(n+1); //t/f node dist
    vector<int> isTrap(n+1, -1); //trap 여부 확인, trap이 몇 번째인지 확인
    //map init
    for(vector<int> road:roads){
        int s = road[0];
        int e = road[1];
        int d = road[2];
        G[s].push_back({1,e,d}); //정방향
        G[e].push_back({0,s,d}); //역방향
    }    
    
    //trap init
    for(int i=0;i<traps.size();i++){        
        isTrap[traps[i]] = i;
    }        

    findMinTime(start,end, G, isTrap);
    
    answer = minTime;
    return answer;
}
