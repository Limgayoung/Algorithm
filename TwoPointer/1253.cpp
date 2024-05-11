#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
N개의 수 중에서 두 수의 합으로 나타낼 수 있는 수 -> 좋다
좋은 수 개수 구하기
수의 위치 다르면 값 같아도 다른 수

N<=2000

투포인터 사용해 각 숫자가 좋은 수인지 확인

*/

int N;
map<int, int> haveNum; //number, index
vector<int> arr;
int answer = 0;
vector<bool> isGood;

int main()
{
    scanf("%d", &N);
    arr = vector<int>(N);
    isGood = vector<bool>(N, false);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        haveNum.insert({ arr[i], i });
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        int findNum = arr[i];
        //투포인터로 찾기
        int l = 0;
        int r = N - 1;
        while (l < r) {
            int sum = arr[l] + arr[r];

            //자기 자신은 안됨
            if (l == i) l++;
            else if (r == i) r--;
            else if (sum == findNum) {
                answer++;
                break;
            }
            else if (findNum > sum) {
                l++;
            }
            else {
                r--;
            }
        }
    }


    printf("%d", answer);
}

/*
10
0 2 3 4 5 6 7 8 9 10
*/
