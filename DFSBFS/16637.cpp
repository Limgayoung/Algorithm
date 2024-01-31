#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
vector<char> opers;
long long maxResult = -987654321;

long long operResult(long long result, int nextNum, char nextOper) {
	if (nextOper == '+') {
		return result + nextNum;
	}
	else if (nextOper == '*') {
		return result * nextNum;
	}
	else if (nextOper == '-') {
		return result - nextNum;
	}
}

void dfs(long long result, int index) {
	//printf("index: %d result: %lld\n", index, result);
	if (index >= nums.size()-1) {
		maxResult = max(maxResult, result);
		//printf("\n");
		return;
	}

	int nextNum = nums[index+1];
	char nextOper = opers[index+1];

	dfs(operResult(result, nextNum, nextOper), index + 1);

	if (index + 2 <= nums.size() - 1) {
		//printf("괄호 사용 result: %lld\n", result);
		int nenextNum = nums[index + 2];
		char nenextOper = opers[index + 2];
		//printf("nextNum: %d nextOper: %c nenextNum: %d nenextOper: %c\n", nextNum, nextOper, nenextNum, nenextOper);
		dfs(operResult(result, operResult(nextNum, nenextNum, nenextOper), nextOper), index + 2);
	}
}

int main(int argc, char** argv)
{
	int N;

	scanf("%d", &N);

	char a;
	long long result;



	for (int i = 0; i <= N; i++) {
		scanf("%c", &a);
		if (a >= '0' && a <= '9') { //숫자
			nums.push_back(a - '0');
		}
		else {
			opers.push_back(a);
		}
	}

	dfs(nums[0], 0);

	printf("%lld", maxResult);

}
