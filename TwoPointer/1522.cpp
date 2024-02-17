#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main(int argc, char** argv)
{
    int aCount=0;
    int answer = 1000000;
    string str;

    cin >> str;

    //a가 연속 -> start ~ end 까지가 모두 a, 구간은 a의 count
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a')
            aCount++;
    }

    //한 구간씩 검사
    for (int i = 0; i < str.size(); i++) {
        int bCount = 0;
        for (int j = i; j < i+aCount; j++) {
            //printf("%c", str[j%str.size()]);
            if (str[j%str.size()] == 'b') { //구간 안에 있는 b만큼 교환해야 함
                bCount++;
            }
        }
        //printf("  %d 구간: %d\n", i, bCount);
        answer = min(answer, bCount);
    }
    
    printf("%d", answer);
   
    return 0;
}
