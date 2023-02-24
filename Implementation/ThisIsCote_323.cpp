#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer;
    int i, j;
    int cnt=1;
    string sub, compareSub;
    string result;
    
    answer = s.size();    
    
    for(i=1;i<=s.size()/2;i++){        
        sub = s.substr(0,i); //sub string        
        for(j=i;j<s.size();j+=i){
            compareSub = s.substr(j,i); //비교할 sub string            
            if(sub.compare(compareSub)==0){ //압축 가능                
                cnt++;
            }
            else{ //압축 불가능                   
                result += (cnt>1)?to_string(cnt)+sub:sub;
                sub = compareSub;
                cnt=1;
            }
        }
        result += (cnt>1)?to_string(cnt)+sub:sub;
        
        //printf("result: %s\n",result.c_str());
        answer = min((int)result.length(), answer);        
        result = "";
        cnt = 1;
    }
    
    return answer;
}

int main(){
    string s;
    
    cin>>s;
    printf("%d",solution(s));
    //cout<<s<<endl;
}
