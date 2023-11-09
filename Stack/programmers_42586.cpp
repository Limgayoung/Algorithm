#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> days;

void calDays(vector<int> progresses, vector<int> speeds){
    for(int i=0;i<progresses.size();i++){
        int remain = 100 - progresses[i];
        int day = remain/speeds[i];  
        if(remain%speeds[i]!=0) day++;
        days.push_back(day);
    }
}

void printDays(){
    for(int i=0;i<days.size();i++){
        cout<<days[i]<<" ";
    }
    cout<<endl;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
        
    //1. 작업 기간 계산
    calDays(progresses, speeds);
    //printDays();
    //2. 앞 숫자 이하면 배포 가능
    int topDay = days[0];
    int count = 1;
    for(int i=1;i<days.size();i++){
        if(topDay >= days[i]){ //배포 가능
            count++;
        }
        else{ //배포 불가능
            topDay = days[i];
            answer.push_back(count);
            count = 1;
        }        
    }
    if(count != 0) answer.push_back(count);
    return answer;
}
