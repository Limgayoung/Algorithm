#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int map[11] ={0,0,1,1,0,1,0,1,0,0,0}; //0~10까지 각 수의 소수여부
string knum="";

long long makeTenToK(int n, int k){ //k진수로 바꾸기
    long long result = 0;
    long long i=1;
    
    while(n>0){
        result += (i*(n%k));
        knum+= '0'+(n%k);
        n/=k;
        i*=10;        
    }
    
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    long long result;
    
    //10진수 n을 k진수로 변환
    result = makeTenToK(n,k);
    
    //변환한 값에서 0이 포함되지 않은 소수 찾기 -> 0으로 자르기

    int ksize = knum.length();
    vector<long long> nums;
    long long num=0;
    for(int i=ksize-1;i>=0;i--){
        if(i == 0){ //마지막
            if(knum[i] !='0'){
                num*=10;
                num+=(knum[i]-'0'); 
                nums.push_back(num);                
            }
        }
        if(knum[i] == '0'){                
            nums.push_back(num);
            num = 0;
        }
        else{
            num*=10;
            num+=(knum[i]-'0');            
        }
    }        
    
    int flag = 0;
    //소수 판별
    for(long long i=0;i<nums.size();i++){
        flag = 0;
        long long checkNum = nums[i];

        if(checkNum == 0 || checkNum == 1) continue;
        for(long long j=2;j<=(sqrt(checkNum));j++){
            if(checkNum%j ==0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) answer++;
        
    }
    
    
    return answer;
}
