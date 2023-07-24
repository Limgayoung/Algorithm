#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int numbersSize = numbers.size();    
    
    vector<int> answer(numbersSize, -1);
    stack<int> s;
    s.push(numbers[numbersSize-1]);
    for(int i=numbersSize-2;i>=0;i--){
        while(!s.empty()){
            if(numbers[i] < s.top()){
                answer[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(numbers[i]);
    }
    

    return answer;
}
