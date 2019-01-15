#include <bits/stdc++.h>
using namespace std;
int n;
int d[32][32]; 

void BFS(int x = 0, int y = 0) {
	if (d[x][y] == 0) {
		d[x][y] = -1;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (abs(i + j) == 1 && x+i>=0 && y+j >=0 && x+i<=n+1 && y+j <= n+1) {
					BFS(x + i, y + j);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> d[i][j];
		}
	}
	BFS();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			switch (d[i][j])
			{
				case -1:
					printf("0 ");
					break;
				case 1:
					printf("1 ");
					break;
				case 0:
					printf("2 ");
					break;
			}
		}
		printf("\n");
	}
	return 0;
}