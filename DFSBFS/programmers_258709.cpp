#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
주사위 조합은 완탐으로 구해야 함 10C5
A, B 주사위 각각에서 나올 수 있는 모든 합 구하기
-> 합을 비교해 횟수 구하기
*/

int N;
vector<int> arrA, arrB;
vector<int> sumA, sumB;
int maxWin = 0;
vector<int> ans;

//각 주사위 조합에서 나올 수 있는 합 구하기
void makeSum(int cnt, int sum, bool isA, vector<vector<int>> dice){
    if(cnt == N/2){
        if(isA){
            sumA.push_back(sum);
        }
        else sumB.push_back(sum);
        return;
    }
    
    for(int i=0;i<6;i++){
        if(isA){
            makeSum(cnt+1, sum+dice[arrA[cnt]][i], isA, dice);    
        }
        else{
            makeSum(cnt+1, sum+dice[arrB[cnt]][i], isA, dice);
        }
        
    }
}
 
//A가 이기는 횟수 구하기
int calWinCnt(){    
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());    
    
    int winCnt=0;
    int a=0;
    int b=0;

    for(int i=0;i<sumA.size();i++){
        for(int j=0;j<sumB.size();j++){
            if(sumA[i] > sumB[j]) winCnt++;
        }        
    }
  
    return winCnt;
}

//A가 뽑는 조합 구하기 (남는게 B)
void makeDicePer(int index, int cnt, vector<vector<int>> dice){ 
    if(cnt == N/2){        
        //B가 뽑은 주사위 구하기
        int j,k;
        j=k=0;
        for(int i=0;i<N;i++){
            if(j>=arrA.size() || arrA[j] != i){
                arrB[k] = i;
                k++;
            }
            else j++;
        }
        
        //A, B 각각의 합 구하기
        sumA.clear();
        sumB.clear();
        makeSum(0,0,true,dice);
        makeSum(0,0,false,dice);
        
        //승리할 확률 구하기
        int winCnt = calWinCnt();
        if(maxWin < winCnt){
            ans = arrA;
            maxWin = winCnt;
        }
       // printf("winCnt: %d\n",winCnt);
        return;
    }
    
    for(int i=index;i<N;i++){
        arrA[cnt] = i;
        makeDicePer(i+1, cnt+1, dice);
    }
    
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    N = dice.size();    
    arrA = vector<int>(N/2);
    arrB = vector<int>(N/2);
    
    makeDicePer(0,0,dice);
    for(int i=0;i<ans.size();i++){
        ans[i]++;
    }
    
    return ans;
}
