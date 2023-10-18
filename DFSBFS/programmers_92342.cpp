#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> lionScore, apeachScore; //라이언, 어피치 점수
vector<int> answerScore; //가장 차이 많이날 경우의 score
int aScore, lScore; //라이언, 어피치 현재 점수
int N; //총 화살 개수
int maxScore = 0; //가장 높은 점수차

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        printf("점수: %d 개수: %d\n", 10-i, v[i]);
    }
    printf("\n");
}

vector<int> scoreComparison(){ //answerScore와 lionScore 비교, 낮은 화살 더 많은 것 반환
    for(int i=10;i>=0;i--){
        if(answerScore[i] < lionScore[i]){
            return lionScore;
        }        
        else if(answerScore[i] > lionScore[i]) return answerScore;
    }
    return answerScore;
}

void dfs(int index, int lc, int ac, int nowArrow){ 
    //현재 점수 위치, 라이언 점수, 어피치 점수, 현재 화살 개수
    
    if(nowArrow > N) {
        //printf("화살촉 더 많이씀!\n");
        return;
    }
                      
    if(index == 11){ //종료조건, 비교
        //printf("종료조건!\n");
        //printf("어피치 점수: %d 라이언 현재 점수: %d  점수차: %d\n", ac, lc, lc-ac);
        if(lc <= ac) return;
        lionScore[10] += N-nowArrow;
        
        if((lc - ac) > maxScore){ //점수차 더 큰 경우
            maxScore = lc-ac;
            answerScore = lionScore;
        }
        else if((lc - ac) == maxScore){ //점수차 같을 경우 -> 가장 낮은 점수 비교
            answerScore = scoreComparison();
        }

        return;
    }
    
    //어피치 개수보다 1개 많이 해야 점수 따기 가능
    int nextArrow = apeachScore[index] +1; //던져야 하는 화살 수 
    int aScore = 0;
    if(apeachScore[index] > 0) aScore = 10-index;
    
    if(nextArrow + nowArrow <= N){ //점수 따기 가능
        lionScore.push_back(nextArrow);
        dfs(index+1, lc+ (10-index), ac, nowArrow+nextArrow);
        lionScore.pop_back();                
    }
    
    //점수 안 딸 경우
    lionScore.push_back(0);
    dfs(index+1, lc, ac+aScore, nowArrow);
    lionScore.pop_back();
          
}


vector<int> solution(int n, vector<int> info) { //info에는 10 9 8 ... 순으로 개수 저장
    vector<int> answer;    
    N=n;
    apeachScore = info;
    
    for(int i=0;i<n;i++){
        
    }
    dfs(0,0,0,0);
    if(maxScore == 0){
        answerScore.push_back(-1);        
    }
    return answerScore;
}
