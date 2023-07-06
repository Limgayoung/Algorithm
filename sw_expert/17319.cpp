/* //풀이 1번
#include<iostream>
#include <cstring>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    int N;
    int i, j;
    char str[102];
    char firstStr[52], secondStr[52];
 
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        scanf("%d", &N);
        scanf("%s", str);
         
        if(N%2 == 1){
             cout<<"#"<<test_case<<" No\n";
            continue;
        }
 
        for (j = 0; j < N; j++) {
            if (j < N / 2) {
                firstStr[j] = str[j];
            }
            else {
                secondStr[j - N / 2] = str[j];
            }
            if (j == N / 2) firstStr[j] = '\0';
        }
 
        secondStr[N - N / 2] = '\0';
 
        cout<<"#"<<test_case<<" ";
        if (strcmp(firstStr, secondStr) == 0) cout<<"Yes\n";
        else cout<<"No\n";
 
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/

//풀이 2
#include<iostream>
#include<string>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;    
        string str, first_str, second_str;
 
        cin>>N>>str;                  
        if(N%2 != 0){
            cout<<"#"<<test_case<<" No"<<endl;
            continue;
        }
        first_str = str.substr(0, N / 2);
        second_str = str.substr(N/2);
 
        if (first_str == second_str){
            cout<<"#"<<test_case<<" Yes"<<endl;
        }
        else {
            cout<<"#"<<test_case<<" No"<<endl;
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
