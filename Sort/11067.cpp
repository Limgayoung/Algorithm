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
x축의 값이 작아지는 경우 없이 무조건 출구 도달 가능
세로축 - y  가로축 - x
1. 현재 위치에서 가장 가까운 y부터 가기
2. y로 갈 곳 없다면 x 이동
-> pair 정렬 x 오름차순, y

3. 같은 x인 곳을 y 시작점 대로 정렬	

*/

int n;
int m;
vector<int> findNum;
vector<pair<int, int>> cafe;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) return true;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T > 0) {

		scanf("%d", &n);

		cafe = vector<pair<int, int>>(n);

		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			cafe[i].first = x;
			cafe[i].second = y;
		}

		//정렬 -> 1,2번 해결됨
		//1. 현재 위치에서 가장 가까운 y부터 가기
		//2. y로 갈 곳 없다면 x 이동
		sort(cafe.begin(), cafe.end(), less<pair<int,int>>());

		//3. 오름차순 정렬 되어 있기 때문에 이전과 x와 y 모두 바뀌면 해당 구간 내림차순 정렬 해야함
		//이전 x의 y가 1일 때 - 1부터 작아지거나 커져야 함

		//맨 처음은 0,0부터 시작함
		int beforeY = 0; 
		int beforeX = -1;
		for (int i = 0; i < n; i++) {
			int nowX = cafe[i].first;
			int nowY = cafe[i].second;

			//1. 이전과 x가 같음 -> 다음으로 (달라질 때 재정렬 완료함)
			//2. 이전과 y가 같음 -> 바로 옆으로 이동한 것
			if (beforeX == nowX || beforeY == nowY) {
			}			
			//3. 재정렬 필요
			else {
				//x가 0인 경우
				if (beforeX == -1) {
					if (nowY >= 0) {
						beforeX = nowX;
						beforeY = nowY;
						continue;
					}
				}
				//구간 찾기
				int index = i;
				while (index<n) {
					if (cafe[index].first != nowX) break;
					index++;
				}
				//nowX부터 index까지 거꾸로 정렬해야 함
				reverse(cafe.begin()+i, cafe.begin()+index);

			}
			beforeX = nowX;
			beforeY = nowY;
		}

		//printf("끝!!\n");
		//for (int i = 0; i < n; i++) {
		//	printf("%d %d\n", cafe[i].first, cafe[i].second);
		//}

		scanf("%d", &m);
		findNum = vector<int>(m);

		for (int i = 0; i < m; i++) {
			scanf("%d", &findNum[i]);
		}


		//printf("-------------------------------\n");
		for (int i = 0; i < m; i++) {
			printf("%d %d\n", cafe[findNum[i]-1].first, cafe[findNum[i]-1].second);
		}
		//printf("-------------------------------\n");

		T--;
	}

}

/*
1
3
0 -1
0 -3
0 -5
3 1 2 3

1
3
0 1
0 3
0 5
3 1 2 3
*/
