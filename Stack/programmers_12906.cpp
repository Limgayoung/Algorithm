#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int num = arr[0];
    answer.push_back(num);
    for(int i=1;i<arr.size();i++){
        if(num != arr[i]){
            num = arr[i];
            answer.push_back(num);
        }
    }

    return answer;
}
