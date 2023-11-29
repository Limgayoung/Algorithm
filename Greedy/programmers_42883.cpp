#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length();
    vector<int> num;
    
    for(int i=0;i<n;i++){
        num.push_back(number[i] - '0');
    }
    
    int cnt = 0;
    int index = 0;
    int maxNum;
    int remainNum = n - k; //만들어야 하는 자릿수
    for(int i=0;i<n-k;i++){
        maxNum = -1;
        int endIndex = index + (n - index - remainNum);
        for(int j=index;j<=endIndex;j++){            
            if(maxNum < num[j]){
                maxNum = num[j];
                index = j+1;
            }            
        }
        //printf("pick num: %d\n",maxNum);
        answer+=(maxNum+'0');      
        remainNum--;
    }
    
    return answer;
}
