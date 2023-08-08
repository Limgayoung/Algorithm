#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n\n");
}

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = -1;
    int n = land.size()*land.size();
    vector<int> l;    
    vector<long long> landSum(n); //누적합
        
    if(n == 1) return 0;
    
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land.size();j++){
            l.push_back(land[i][j]);
        }
    }    
    sort(l.begin(), l.end());
    
    //누적합 계산
    landSum[0] = l[0];
    for(int i=1;i<n;i++){
        landSum[i] = landSum[i-1] + l[i];
    }

    long long plus, minus, cost;
    int height;
    
    //0일 때 구하기
    answer = (landSum[n-1] - (n)*l[0]) * Q; //추가하는 경우 없음
    
    for(int i=1;i<n;i++){         
        height = l[i];
        plus = ((i) * height) - landSum[i-1]; //0~i-1
        minus = (landSum[n-1] - landSum[i]) - ((n-(i+1)) * height); //i+1 ~ n
        cost = plus*P + minus*Q;
        
        if(cost < answer) answer = cost;        
    }
    
    return answer;
}
