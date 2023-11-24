#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> nums;
    int num = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == ',' || s[i] == '}'){ //num 끝
            if(num == 0) continue;
            //printf("num: %d\n",num);
            nums[num]++;
            num = 0;
        }
        else if(s[i] != '{'){ //숫자
            num*= 10;
            num+= s[i] - '0';            
        }
    }
    
    vector<pair<int,int>> numList(nums.begin(), nums.end());
    sort(numList.begin(), numList.end(), compare);
    
    for(int i=0;i<numList.size();i++){
        answer.push_back(numList[i].first);
    }
    
    return answer;
}
