#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int firstAnswer[5] = {1,2,3,4,5};
int secondAnswer[8] = {2,1,2,3,2,4,2,5};
int thirdAnswer[10] = {3,3,1,1,2,2,4,4,5,5};


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int firstScore = 0;
    int secondScore = 0;
    int thirdScore = 0;
    
    int firstIndex, secondIndex, thirdIndex;
    firstIndex = secondIndex = thirdIndex = 0;

    for(int answer:answers){
        if(firstAnswer[firstIndex] == answer){
            firstScore++;
        }
        if(secondAnswer[secondIndex] == answer){
            secondScore++;
        }
        if(thirdAnswer[thirdIndex] == answer){
            thirdScore++;
        }
        
        firstIndex = (firstIndex+1) % 5;
        secondIndex = (secondIndex+1) % 8;
        thirdIndex = (thirdIndex+1) % 10;
    }
    
    //max 값 찾기
    int maxScore = 0;
    maxScore = max(firstScore, secondScore);
    maxScore = max(maxScore, thirdScore);
    
    if(maxScore == firstScore) answer.push_back(1);
    if(maxScore == secondScore) answer.push_back(2);
    if(maxScore == thirdScore) answer.push_back(3);
    
    
    return answer;
}
