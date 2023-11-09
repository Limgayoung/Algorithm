#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<pair<int,int>> pq; //location, 우선순위
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i=0;i<priorities.size();i++){
        pq.push({priorities[i], i});
        q.push({priorities[i], i});
    }
    
    while(q.empty()!=1){
        int nowPriority = q.front().first;
        int nowIndex = q.front().second;
        int topPriority = pq.top().first;
        int topIndex = pq.top().second;
        
        //printf("now: %d %d, top: %d %d\n",nowPriority, nowIndex, topPriority, topIndex);
                
        if(nowPriority < topPriority){
            q.pop();
            q.push({nowPriority, nowIndex});
        }
        else if(nowPriority == topPriority){            
            q.pop();
            pq.pop();
            answer++;
            if(nowIndex == location) return answer;
        }        
    }
    
    return answer;
}
