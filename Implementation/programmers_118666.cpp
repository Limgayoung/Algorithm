#include <string>
#include <vector>
#include <map>

using namespace std;
int score[8] = {0, 3,2,1,0,1,2,3};
map<char, int> myScore;

void initMyScore(){
    myScore.insert({'R', 0});
    myScore.insert({'T', 0});    
    myScore.insert({'C', 0});
    myScore.insert({'F', 0});
    myScore.insert({'A', 0});
    myScore.insert({'N', 0});
    myScore.insert({'J', 0});
    myScore.insert({'M', 0});            
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    
    for(int i=0;i<choices.size();i++){
        if(choices[i] <4){ //앞 유형
            myScore[survey[i][0]] += score[choices[i]];
        }
        else{ //뒤 유형
            myScore[survey[i][1]] += score[choices[i]];
        }
    }
    
    if(myScore['R'] >= myScore['T']) answer+="R";
    else answer+="T";
    if(myScore['C'] >= myScore['F']) answer+="C";
    else answer+="F";
    if(myScore['J'] >= myScore['M']) answer+="J";
    else answer+="M";
    if(myScore['A'] >= myScore['N']) answer+="A";
    else answer+="N";
    
    return answer;
}
