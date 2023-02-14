#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int locx[8] = { 2,2,-2,-2,1,-1,1,-1 };
int locy[8] = { 1,-1,1,-1,2,2,-2,-2 };

int main() {
	char loc[3];
	int nx, ny;
	int x, y;
	int cnt = 0;

	scanf("%s", loc);
	x = loc[0] - 'a' + 1;  //1부터 시작
	y = loc[1] - '1' + 1;
	//printf("loc: %s %d %d\n",loc, x, y);

	for (int i = 0; i < 8; i++) {
		nx = locx[i] + x;
		ny = locy[i] + y;

		if (nx > 8 || nx < 1 || ny>8 || ny < 1)
			continue;
		cnt++;
	}
	printf("%d", cnt);
	
}

/*
a1
*/
