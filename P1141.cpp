#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
#define maxn 1005
char Map[maxn][maxn];
int s[maxn][maxn];
int amount[100000];
int cnt = 0;

void BFS(int x,int y) {
	if (s[x][y])
		return;
	++cnt;
	queue<pii> Q;
	Q.push(make_pair(x, y));
	s[x][y] = cnt;
	while (!Q.empty()) {
		x = Q.front().first; y = Q.front().second;
		Q.pop();
		++amount[cnt];
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (abs(i + j) == 1  && Map[x + i][y + j] + Map[x][y] == '0' + '1' && !s[x+i][y+j]  ) {
					Q.push(make_pair(x + i, y + j));
					s[x+i][y+j] = cnt;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", Map[i] + 1);
	}
	int x, y;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		BFS(x, y);
		cout << amount[s[x][y]]<<endl;
	}
	return 0;
}