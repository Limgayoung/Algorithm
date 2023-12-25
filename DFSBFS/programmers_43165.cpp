#include <string>
#include <vector>

using namespace std;
vector<int> n;
int nSize;
int answer = 0;

void dfs(int num, int index, int target){    
    if(index == nSize && num == target){
        answer++;
    }
    if(index >= nSize) return;
    
    dfs(num+n[index], index+1, target);
    dfs(num-n[index], index+1, target);    
}

int solution(vector<int> numbers, int target) {
    //int answer = 0;
    n = numbers;
    nSize = numbers.size();
    dfs(0,0,target);
    return answer;
}
