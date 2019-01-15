#include <bits/stdc++.h>
using namespace std;
char graph[300][600];
int maxr = 0,maxc=0;
void drawQube(int r,int c) {
	maxr = max(maxr, r + 5);
	maxc = max(maxc, c + 6);
	memcpy(graph[r + 5]+c+2, "+---+", 5);
	memcpy(graph[r + 4]+c+1,"/   /|", 6);
	memcpy(graph[r + 3]+c, "+---+ |", 7);
	memcpy(graph[r + 2]+c, "|   | +", 7);
	memcpy(graph[r + 1]+c, "|   |/", 6);
	memcpy(graph[r]+c,	   "+---+", 5);
}
void plot() {
	for (int i = maxr; i >= 0; --i) {
		for (int j = 0; j <= maxc; ++j)
			putchar(graph[i][j]);
		putchar('\n');
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	memset(graph, '.', sizeof(graph));
	int t;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			for (int k = 0; k < t; ++k) 
				drawQube(2 * (m - i) + 3 * k, 4 * j + 2 * (m - i));
		}
		//plot();
	}
	plot();
	return 0;
}