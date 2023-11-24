#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int K;

bool canGo(vector<int> stones, int mid){
    int cnt = 0;
    for(int i:stones){
        if(i - mid <= 0){
            cnt++;
        }
        else cnt = 0;
        
        if(cnt >= K) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0;
    int right = *max_element(stones.begin(), stones.end());
    K = k;
    int mid = (left+right) / 2;
    while(left <= right){
        mid = (left + right) / 2;
        if(canGo(stones, mid)){ //left 더하기
            left = mid + 1;
        }
        else{ //right 줄이기
            right = mid - 1;
        }
    }
    
    answer = left;
    return answer;
}
