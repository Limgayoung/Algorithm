#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else return a.second > b.second;
    }
};

bool comparePair(pair<int,int> a, pair<int,int> b){     
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool compareVector(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    sort(jobs.begin(), jobs.end(), compareVector);
    
    int i=0;
    int nowTime = 0;
    while(i<jobs.size() || !pq.empty()){
        //printf("nowTime: %d\n",nowTime);
        if(i<jobs.size() && nowTime >= jobs[i][0]){
            //printf("push! %d번째 job\n",i);
            pq.push({jobs[i][0], jobs[i][1]});
            i++;
            continue;
        }
        
        if(!pq.empty()){        
            //printf("작업! nowTime: %d 요청시간: %d 작업시간: %d\n",nowTime, pq.top().first, pq.top().second);
            nowTime += pq.top().second;
            answer += (nowTime - pq.top().first);           
            pq.pop();
        }
        else{
            nowTime = jobs[i][0];
        }
    }
    

    answer /= jobs.size();
    return answer;
}
