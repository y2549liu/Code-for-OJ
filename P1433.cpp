#include <bits/stdc++.h>
using namespace std;

int n;
float ans = 0x7fffffff;
float dis[15][15];
struct point {
	float x, y;
} cheese[15];

bool visited[15];
int sequence[15];

void DFS(int index, float sum) {
	if (sum > ans)
		return;
	if (index == n) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		sequence[index] = i;
		if (index)
			DFS(index + 1, sum + dis[sequence[index - 1]][i]);
		else
			DFS(index + 1, dis[i][i]);
		visited[i] = false;
	}		
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cheese[i].x >> cheese[i].y;
		dis[i][i] = sqrt(cheese[i].x*cheese[i].x + cheese[i].y*cheese[i].y);
		for (int j = 0; j < i; ++j) {
			dis[j][i] = dis[i][j] = sqrt(pow((cheese[i].x - cheese[j].x), 2) + pow((cheese[i].y - cheese[j].y), 2));
		}
	}
	DFS(0, 0);
	printf("%0.2f", ans);
	return 0;
}
