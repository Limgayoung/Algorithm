#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> num;

void init_map(){
    //map 만들기
    num.insert({"zero",0});
    num.insert({"one",1});
    num.insert({"two",2});
    num.insert({"three",3});
    num.insert({"four",4});
    num.insert({"five",5});
    num.insert({"six",6});
    num.insert({"seven",7});
    num.insert({"eight",8});
    num.insert({"nine",9});
}

int solution(string s) {
    
    int answer = 0;
    init_map();
    
    //printf("%d",num["zero"]);

    string checkWord="";
    for(int i=0;i<s.length();i++){
        if(s[i] >='0' && s[i]<='9'){
            answer*=10;
            answer+=(s[i]-'0');
        }
        else{
            checkWord+=s[i];
            if(num.count(checkWord)>0){
                answer*=10;
                answer+= num[checkWord];
                checkWord="";
            }
        }
    }
    
    return answer;
}
