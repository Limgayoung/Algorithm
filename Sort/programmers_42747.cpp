#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int maxCitation = citations[citations.size()-1];
    
    
    for(int i=0;i<maxCitation;i++){
        int cnt = 0;
        for(int citation:citations){
            if(citation >= i) cnt++;
        }
        if( i >= cnt ) answer = max(cnt, answer);
    }

    return answer;
}
