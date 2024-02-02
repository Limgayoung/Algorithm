#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calPeopleNum(vector<int> times, long long time){
    long long result = 0;
    
    for(int t:times){
        result += time/t;
    }
    return result;    
}

long long solution(int n, vector<int> times) {
    long long l = 1;
    long long r = (long long)times[times.size()-1] * n;
    long long answer = r;
    long long mid;

    while(l<=r){
        mid = (l+r)/2;
        long long nowNum = calPeopleNum(times, mid);
        if(nowNum < n){
            l = mid+1;            
        }
        else{
            answer = min(answer, mid);
            r = mid-1;
        }
    }

    return answer;
}
