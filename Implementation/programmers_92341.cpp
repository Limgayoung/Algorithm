#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
int lastTime = 1439; //23:59
map<string, int> inMap;
map<string, int> outMap;
map<string, int> timeMap; //차량별 시간
vector<string> answerCarOrder; //차량 순서

void printVector(vector<string> v){
    for(int i=0;i<v.size();i++){
        printf("%s ",v[i].c_str());        
    }
    printf("\n");
}

void printMap(map<string, int> map){
    for(auto &iter:map){
        cout<<"car number: "<<iter.first<<" time: "<<iter.second<<endl;
    }
    printf("\n");
}

int changeMin(int hour, int min){
    return hour*60+min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    //1. records 저장 (input 시간을 분 형태로 바꿔서 저장)
    //inmap, outmap에 key 차량번호, value time 저장
    for(int i=0;i<records.size();i++){        
        int hour = (records[i][0] -'0') * 10;
        hour += (records[i][1]-'0');
        int min = (records[i][3] - '0') * 10;
        min += (records[i][4]-'0');
        
        string carNum = "";
        for(int j=6;j<10;j++){
            carNum += records[i][j];
        }
        string inout = ""; 
        for(int j=11;j<13;j++){
            inout += records[i][j];
        }

        if(inout.compare("IN") == 0){
            if(inMap.count(carNum) == 0){ //처음 넣는 것
                answerCarOrder.push_back(carNum);
                inMap.insert({carNum, changeMin(hour, min)});
            }
            else{
                inMap[carNum] = changeMin(hour, min);
            }
        }
        else{ //out
            //out일 경우 시간 계산할 것
            int carTime = changeMin(hour,min) - inMap[carNum];
            inMap[carNum] = lastTime; //계산한 값이어서 23:59로 변경 (확인 위함)
            //printf("carNum: %s carTime: %d\n", carNum.c_str(), carTime);
            if(timeMap.count(carNum) != 0){
                timeMap[carNum] = timeMap[carNum] + carTime;
            }
            else{
                timeMap.insert({carNum, carTime});
            }
        }               
    }
    
    //입차 기록만 있는 경우 == inMap의 값이 23:59가 아닌 경우
    for(auto &iter:inMap){
        if(iter.second != lastTime){
            string carNum = iter.first;
            if(timeMap.count(carNum) != 0){
                timeMap[carNum] = timeMap[carNum] + (lastTime - iter.second);
            }
            else{
                timeMap.insert({carNum, (lastTime - iter.second)});
            }
        }
    }

    //2. 요금 계산
    sort(answerCarOrder.begin(), answerCarOrder.end());
    //printVector(answerCarOrder);
    //printMap(timeMap);
    
    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    for(string num : answerCarOrder){
        //기본요금 넘는지 확인
        if(timeMap[num] <= basicTime){
            printf("기본요금! carNum: %s\n", num.c_str());
            answer.push_back(basicFee);
        }
        else{
            //요금 계산
            int fee = basicFee;
            int remainTime = timeMap[num] - basicTime;
            int unit = remainTime / unitTime;        
            if(remainTime % unitTime != 0){
                unit++;
            }
            fee += (unit * unitFee);
            answer.push_back(fee);
            //printf("요금! carNum: %s %d\n", num.c_str(), fee);
        }
    }
    
    
    
    return answer;
}
