#include <bits/stdc++.h>
using namespace std;
int n;
char d[120][120];
bool visited[120][120];
char str[10] = "yizhong";
typedef pair<int, int> pii;

bool check(pii s, pii dir) {
	for (int i = 0; i < 7; ++i) {
		if (d[s.first + dir.first*i][s.second + dir.second*i] != str[i])
			return false;
	}
	for (int i = 0; i < 7; ++i) {
		visited[s.first + dir.first*i][s.second + dir.second*i] = 1;
	}
	return 1;
}

int main() {
	cin >> n;
	for (int i = 7; i < n+7; ++i) {
		for (int j = 7; j < n+7; ++j) {
			cin>>d[i][j];
		}
	}
	for (int i = 7; i < n+7; ++i) {
		for (int j = 7; j < n+7; ++j) {
			if (d[i][j] != 'y')
				continue;
			for (int u = -1; u <= 1; ++u) {
				for (int v = -1; v <= 1; ++v) {
					if (u == 0 && v == 0)
						continue;
					check(make_pair(i, j), make_pair(u, v));
				}
			}
		}
	}
	for (int i = 7; i < n + 7; ++i) {
		for (int j = 7; j < n + 7; ++j) {
			if (visited[i][j])
				putchar(d[i][j]);
			else
				putchar('*');
		}
		printf("\n");
	}
	return 0;
}