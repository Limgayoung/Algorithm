#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){ //두 수 합쳤을 때 더 큰게 큰 수
    string sa = to_string(a);
    string sb = to_string(b);
    
    string left = sa+sb;
    string right = sb+sa;
    
    return stoi(left) > stoi(right);
}

void printVector(vector<int> numbers){
    for(int i:numbers){
        printf("%d ", i);
    }
    printf("\n");
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    //printVector(numbers);
    for(int n:numbers){
        if(answer.empty() && n == 0) continue;
        answer += to_string(n);
    }
    
    if(answer.empty()) answer.push_back('0');
    
    return answer;
}
