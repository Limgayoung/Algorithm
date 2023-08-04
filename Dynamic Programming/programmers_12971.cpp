#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    vector<int> dp(sticker.size());
    int maxSum = -1;
    int i;
    int answer = 0;
    
    if(sticker.size() == 1){
        return sticker[0];
    }
    else if(sticker.size() == 2){
        return max(sticker[0], sticker[1]);
    }
    
    //첫 번째 스티커 뜯을 경우
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(i=2;i<sticker.size()-1;i++){ //마지막 스티커 뜯지 못함
        dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    dp[i] = dp[i-1]; //마지막 스티커 안뜯음    
    maxSum = max(maxSum, dp[i]);
    
    //첫 번째 스티커 안 뜯을 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    for(i=2;i<sticker.size();i++){ //마지막 스티커 뜯을 수 있음
        dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);        
    }
    maxSum = max(maxSum, dp[i-1]);
    
    answer = maxSum;
    return answer;
}
