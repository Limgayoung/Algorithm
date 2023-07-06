#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int i;
    sort(targets.begin(), targets.end());

    int now;
    now = targets[0][1];
    
    for(i=1;i<targets.size();i++){ //하나씩 비교
        if(now <= targets[i][0]){ //다음 타겟과 같이 없애지 못하는 경우
            answer++;
            now = targets[i][1];
        }
        else{
            now = min(now, targets[i][1]);
        }
    }

    return answer+1;
}
