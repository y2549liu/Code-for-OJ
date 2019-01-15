#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int m, n;
char Map[102][102];
bool visited[102][102];
int cnt=0;

void DFS(int x,int y) {
	visited[x][y] = 1;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0)
				continue;
			int nx = x + i, ny = y + j;
			if (!visited[nx][ny] && Map[nx][ny] == '@') {
				DFS(nx, ny);
			}
		}
	}
}

int main() {
	while (cin >> m >> n && m) {
		memset(visited, 0, sizeof(visited));
		memset(Map, 0, sizeof(Map));
		cnt = 0;
		for (int i = 1; i <= m; ++i) {
			scanf("%s", Map[i] + 1);
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (Map[i][j] == '@' && !(visited[i][j])) {
					DFS(i, j);
					++cnt;
				}
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}