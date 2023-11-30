#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    sort(people.begin(), people.end());
    
    int l = 0;
    int r = n-1;
    
    while(l<=r){        
        if(people[l] + people[r] > limit){ //뒷사람만 탈 수 있음
            answer++;
            r--;
        }
        else{ //같이 탈 수 있음
            answer++;
            l++;
            r--;
        }
    }
    
    return answer;
}
