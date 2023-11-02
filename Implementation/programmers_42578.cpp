#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothesMap;
    
    for(vector<string> c:clothes){
        clothesMap[c[1]]++;
    }
    
    for(auto iter=clothesMap.begin(); iter!=clothesMap.end(); iter++){
        //cout<<iter->first<<" "<<iter->second<<endl;
        answer *= iter->second+1;
    }

    return answer-1;
}
