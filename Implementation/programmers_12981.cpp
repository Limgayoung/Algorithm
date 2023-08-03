#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<string> wordSet;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int num, count; //번호, 차례
    char beforeWordEnd;
    
    num=2;
    count = 1;    
    wordSet.insert(words[0]);
    beforeWordEnd = words[0][words[0].size() -1];
    
    for(int i=1;i<words.size();i++){
        if(beforeWordEnd != words[i][0] || wordSet.count(words[i]) == 1){ //끝남
            //cout<<"beforeWord: "<<beforeWordEnd<<" nowWord: "<<words[i]<<endl;
            answer.push_back(num);
            answer.push_back(count);
            break;
        }
        
        wordSet.insert(words[i]);
        num++;
        if(num/(n+1) >0){
            count++;
            num = 1;            
        }
        beforeWordEnd = words[i][words[i].size() -1];
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
