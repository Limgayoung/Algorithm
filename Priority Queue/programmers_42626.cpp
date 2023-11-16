#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    sort(scoville.begin(), scoville.end());
    
    for(int s:scoville){
        pq.push(-s); //오름차순 정렬을 위해        
    }
    //3. pq가 빌 때까지 시도
    while(!pq.empty()){
        int first = -pq.top();
        pq.pop();
        if(pq.size() <1){     
            if(first < K){
                answer = -1;
            }
            break;
        }
        if(first >= K){ //이후 값은 모두 K 이상
            break;
        }     
        
        int second = -pq.top();
        pq.pop();
        int newScoville = first + second*2;
        pq.push(-newScoville);
        
        answer++;
    }
    
    
    return answer;
}
