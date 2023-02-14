#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int i;
	char loc;
	int x, y;
	int locx=1, locy=1;

	scanf("%d", &N);
	//getchar();
	for (i = 0; i < 6; i++) {
		x = 0;
		y = 0;		
		getchar();
		scanf("%c", &loc);		
		if (loc == 'L') {
			x = -1;			
		}
		else if (loc == 'R') {
			x = 1;
		}
		else if (loc == 'U') {
			y = -1;
		}
		else if (loc == 'D') {
			y = +1;
		}
		if ((locx + x) <= N && (locx + x) >= 1) {
			locx += x;
		}
		if ((locy + y) <= N && (locy + y) >= 1) {
			locy += y;
		}
		//printf("i: %d loc: %c   %d %d\n", i,loc, locx, locy);

	}
	printf("%d %d", locy, locx);
	//왠진 모르겠지만 책에는 x,y 좌표가 반대로 되어있음;
	
}

/*
5 
R R R U D D
*/
