#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct node{
    string parentName; //부모 이름
    int isExistParent; //부모 존재 여부
    int sales;
}node;

void printMap(unordered_map<string, node> map){
    for(auto iter:map){
        cout<<"name: "<<iter.first<< " parent: "<<iter.second.parentName<<endl;
    }
    printf("\n");
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {

    int peopleNum = enroll.size();
    vector<int> answer(peopleNum, 0);
    unordered_map<string, node> map;
    
    //map 만들기
    for(int i=0;i<peopleNum;i++){        
        node n;
        if(referral[i] == "-"){
            n.isExistParent = 0;      
            n.parentName = "-";
        }
        else{
            n.isExistParent = 1;
            n.parentName = referral[i];
        }
        n.sales = 0;
        map.insert({enroll[i], n});
    }
    
    //판매액 계산
    string sellerName;
    node sellerParent;
    int sellerSize = seller.size();
    int sellerSales, toParentMoney;
    
    for(int i=0;i<sellerSize;i++){
        sellerName = seller[i];
        sellerParent = map[sellerName];
        sellerSales = amount[i] * 100;        
        while(1){            
            toParentMoney = sellerSales/10; //부모에게 갈 돈
            map[sellerName].sales += (sellerSales - toParentMoney);
            sellerSales = toParentMoney;
            if(toParentMoney == 0) break;
            if(sellerParent.isExistParent == 0){ // 끝
                break;
            }
            else{
                sellerName = sellerParent.parentName;
                sellerParent = map[sellerName];
            }
        }
    }
    
    for(int i=0;i<peopleNum;i++){
        answer[i] = map[enroll[i]].sales;
    }
    
    return answer;
}
