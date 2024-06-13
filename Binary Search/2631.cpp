#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*

시간 제한 1초
N <= 200

연속적인 숫자가 되도록 놔야 함
N - 가장 큰 증가하는 부분 수열 길이 만큼 옮겨야 한다.

3 5 6
3 7 5 2 6 1 4
-> 3 7 4 5 2 6 1
-> 3 4 5 2 6 1 7
-> 1 3 4 5 2 6 7
-> 1 2 3 4 5 6 7

3 7
3 5
2 5
2 5 6
1 5 6
1 4 6

*/

int N;
vector<int> nums;

int findLength() {
	vector<int> arr;
	arr.push_back(nums[0]);

	for (int i = 1; i < N; i++) {
		//가장 뒤의 숫자보다 크면 맨 뒤에 넣기
		if (arr[arr.size() - 1] < nums[i]) {
			arr.push_back(nums[i]);
		}
		else { //이분탐색으로 위치 탐색해서 바꾸기
			int l = 0;
			int r = arr.size() - 1;

			while (l < r) {
				int m = (l + r) / 2;
				if (arr[m] > nums[i]) {
					r--;
				}
				else {
					l++;
				}
			}
			arr[(l + r) / 2] = nums[i];
		}		
	}

	/*for (int i = 0; i < arr.size(); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	return arr.size();
}

int main()
{
	scanf("%d", &N);
	nums = vector<int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	int length = findLength();

	printf("%d", N - length);
}

/*

*/
