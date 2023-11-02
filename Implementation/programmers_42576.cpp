#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> playerMap;
    
    for(string s:participant){
        playerMap[s]++;
    }
    
    for(string s:completion){
        playerMap[s]--;
    }
    
    for(auto iter=playerMap.begin();iter!=playerMap.end();iter++){
        if(iter->second!=0) {    
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}
