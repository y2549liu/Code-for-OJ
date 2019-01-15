#include <bits/stdc++.h>
using namespace std;

int Data[102][102],n,m;
int length[102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int DFS(int x,int y) {
	if (length[x][y])
		return length[x][y];
	length[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (Data[nx][ny] < Data[x][y]) {
			length[x][y] = max(length[x][y], DFS(nx, ny) + 1);
		}
	}
	return length[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	memset(Data, 0x7f, sizeof(Data));
	cin >> n >> m ;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> Data[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans = max(ans, DFS(i, j));
		}
	}
	cout << ans;
	return 0;
}