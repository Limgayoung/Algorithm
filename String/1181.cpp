#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

typedef struct word{
    string s;
    int len;
}word;

word str[20001];

bool compare(const word &a, const word &b) {
    if (a.len == b.len) { //길이가 같은 경우 사전순
        return a.s < b.s;
    }
    else {
        return a.len < b.len;
    }
}

int main()
{
    int N;
    int i;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        cin >> str[i].s;
        str[i].len = str[i].s.length();
    }

    sort(str, str + N, compare);

    for (i = 0; i < N; i++) {

        if (i != N-1 && str[i].s == str[i + 1].s) {
            continue;
        }
        cout << str[i].s << endl;
    }

    return 0;
}

/*
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
*/
