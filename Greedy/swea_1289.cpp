#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str;
        cin >> str;

        //앞에서부터 바꿔 나가야함
        int nowNum = 0;
        int cnt = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]-'0' != nowNum){ //뒤에 싹 바꿔줘야함
                nowNum++;
                nowNum %= 2;
                cnt++;
            }
        }
        
        printf("#%d %d\n",test_case, cnt);
	}
	return 0;
}
