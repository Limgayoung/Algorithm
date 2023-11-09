#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //시간
    queue<int> q;
    
    int sum = 0; //다리 위의 트럭 무게
    int i = 0; //트럭 id
    
    //1초씩 반복    
    while(1){
        if(i == truck_weights.size()){ //종료조건
            answer += bridge_length; //마지막 트럭이 건너는 시간 더하기
            break;
        }
        answer++;
        
        if(q.size() == bridge_length){ //맨 앞의 차가 다리를 다 건넘
            sum -= q.front(); //무게 감량
            q.pop();
        }
        
        if(sum+truck_weights[i] <= weight){ //건너기 가능
            q.push(truck_weights[i]);
            sum+=truck_weights[i];
            i++;
        }
        else{ //못건넘
            q.push(0);
        }
    }
    
    return answer;
}
