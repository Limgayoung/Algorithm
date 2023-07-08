#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string number;
    int left, right;

    while (1) {
        cin >> number;
        if (number.compare("0") == 0) break;
        left = 0;
        right = number.length() - 1;

        while (left < right) {
            if (number[left] != number[right]) {
                printf("no\n");
                break;
            }
            left++;
            right--;
        }
        if(left >=right) printf("yes\n");
    }

    return 0;
}

/*
121
1231
12421
0
*/
