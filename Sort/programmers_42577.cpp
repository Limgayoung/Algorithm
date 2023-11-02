#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printVector(vector<string> v){
    for(string s:v){
        cout<<s<<endl;
    }
    printf("\n");
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    //printVector(phone_book);
    
    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].length()))
            return false;
    }
    
    return answer;
}
