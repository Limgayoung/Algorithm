#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> str;
    bool answer = true;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            str.push(1);
        }
        else{ // )
            if(str.empty() == 1) return false;
            str.pop();
        }    
    }
    if(str.empty() == 0) answer = false;
    else answer = true;

    return answer;
}
