#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>


using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int answer;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		vector<int> score(101, 0);
		int maxNum = 0;
		int maxCount = 0;
		int num;

		for (int i = 0; i < 1000; i++) {
			scanf("%d", &num);
			score[num]++;
		}

		for (int i = 0; i < 101; i++) {
			if (score[i] > maxCount) {
				maxCount = score[i];
				maxNum = i;
			}
			else if (score[i] == maxCount) {
				if (i > maxNum) {
					maxNum = i;
				}
			}
		}

		printf("#%d %d\n" , test_case, maxNum);
	}
	return 0;
}
