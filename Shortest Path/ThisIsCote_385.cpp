#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_INT 200000000

using namespace std;

long long map[102][102] = { 0 };

int main() {
	int n, m;
	int i, j, k;
	int a, b, c;

	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = MAX_INT;
		}
	}


	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (map[a][b] > c) map[a][b] = c;	
	}

	//i~k +  k~j 와 ij 비교
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == MAX_INT) map[i][j] = 0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}


}


/*
2 
3 4 
1 3 3 2 2 1 4 1 0 6 4 7 
4 4 
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
*/
