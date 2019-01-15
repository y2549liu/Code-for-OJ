#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1501][1501];
int visited[1501][1501][3];
int getr(int x) {
	return (x%n + n) % n;
}
int getc(int x) {
	return (x%m + m) % m;
}
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
bool dfs(int lx,int ly) {
	int x = getr(lx), y = getc(ly);
	if (visited[x][y][0] && (lx!= visited[x][y][1] || ly!= visited[x][y][2]))
		return 1;
	if (mat[x][y] == '#' || visited[x][y][0])
		return 0;
	visited[x][y][0] = 1;
	visited[x][y][1] = lx;
	visited[x][y][2] = ly;
	for (int i = 0; i < 4;++i) {
		if (dfs(lx + dx[i], ly + dy[i]))
			return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	while (cin >> n >> m) {
		int sx, sy;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mat[i][j];
				if (mat[i][j] == 'S') 
					sx = i, sy = j;
			}
		}
		if (dfs(sx, sy))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}