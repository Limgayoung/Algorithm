#include <vector>
#include <iostream>
using namespace std;

int isPrime[3001];

void calPrime(){
    fill(isPrime, isPrime+3000,1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    
    for(int i=2;i*i<=3000;i++){
        if(isPrime[i] == 1){ //i가 소수
            for(int j=i*i;j<=3000;j+=i){
                if(j%i==0){
                    isPrime[j] = 0;
                }                
            }
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;

    int numSize = nums.size();
    calPrime();
    
    for(int i=0;i<numSize;i++){
        for(int j=i+1;j<numSize;j++){
            for(int k=j+1;k<numSize;k++){
                if(isPrime[nums[i]+nums[j]+nums[k]] == 1){
                    answer++;
                }
            }
        }
    }

    return answer;
}
