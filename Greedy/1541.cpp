#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char x[51];  
    int n[50] = { 0 };
    int len, i,j=0;
    int sum = 0, num = 0;
    int answer;

    scanf("%s", x);

    len = strlen(x);
    for (i = 0; i < len; i++) {
        if (x[i] == '-'||x[i]=='+') {
            sum = sum + num;
            num = 0;

            if (x[i] == '-') {
                n[j] = sum;
                j++;
                sum = 0;
            }
        }
        else {
            num = num * 10 + (x[i] - '0');
        }
    }

    sum = sum + num;
    n[j] = sum;
    j++;

    answer = n[0];

    for (i = 1; i < j; i++) {
        answer = answer - n[i];
        //printf("n[%d]: %d\n", i, n[i]);                                                                                                   
    }

    printf("%d", answer);
    
    
    return 0;
}
