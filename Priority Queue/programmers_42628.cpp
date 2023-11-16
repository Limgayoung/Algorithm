#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<long long> maxQueue;
    priority_queue<long long, vector<long long>, greater<long long>> minQueue;
    
    
    int cnt = 0;
    for(string operation:operations){
        long long number = stol(operation.substr(2));
        //printf("number: %lld\n", number);
        if(operation[0] == 'I'){ //Insert
            maxQueue.push(number);
            minQueue.push(number);
            cnt++;            
        }
        else{ //Delete            
            if(number == 1){ //최댓값 삭제
                if(maxQueue.empty()) continue;
                maxQueue.pop();
            }
            else if(number == -1){ //최솟값 삭제
                if(minQueue.empty()) continue;
                minQueue.pop();
            }
            cnt--;            
        }
        
        if(cnt == 0){
            maxQueue = priority_queue<long long>();
            minQueue = priority_queue<long long, vector<long long>, greater<long long>>();
        }
    }
    
    if(maxQueue.empty()) answer.push_back(0);
    else answer.push_back(maxQueue.top());
    
    if(minQueue.empty()) answer.push_back(0);
    else answer.push_back(minQueue.top());
    
    return answer;
}
