#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isEmptyString(string str){
    if(str == ""){
        return true;
    }
    else return false;
}

int separateString(string str){
    int left=0, right=0;
    int i=0;
    for(i=0;i<str.size();i++){
        if(str[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if(left == right){ //균형잡힌 문자열 -> u,v 분리
            break;
        }
    }
    return i; //마지막까지 균형잡히지 않은 경우
}

bool isRightString(string str){
    stack<int> s;
    
    for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            s.push(1);
        }
        else{
            if(!s.empty()){
                s.pop();
            }
            else return false;            
        }        
    }
    return true;
}

string reverseString(string str){
    int i;
    string returnString = "";
    for(i=0;i<str.size();i++){
        if(str[i] == '('){
            returnString +=')';
        }
        else returnString+='(';
    }
    return returnString;
}

string dfs(string p){
    string u="", v="";
    int i,j;
    if(isEmptyString(p)) return ""; //1단계
    else{        
        //2단계 (분리)
        int index = separateString(p);
        for(i=0;i<=index;i++){
            u+=p[i];
        }
        for(i=i;i<p.size();i++){
            v+=p[i];
        }
        //3단계
        if(isRightString(u)){
            return u+dfs(v);
        }
        else{ //4단계
            string str="";
            if(!isEmptyString(u)){
                for(j=1;j<u.size()-1;j++){
                    str+=u[j];
                }
            }
            u = reverseString(str);
            return '('+dfs(v)+')'+u;
        }        
    }    
}

string solution(string p) {
    string answer = "";
    answer = dfs(p);
    return answer;
}
