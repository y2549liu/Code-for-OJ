#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[12], n, total;
int yh[13][13];
bool visited[12];
int c(int m, int n) {
	if (yh[m][n])
		return yh[m][n];
	if (n > (m >> 1))
		n = m - n;
	if (n == 0)
		return yh[m][n]= 1;
	return yh[m][n] = c(m, n - 1) * (m - n + 1) / n;
}

int DFS(int index, int sum) {
	if (sum > total)
		return 0;
	if (index == n && sum == total) {
		return 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			continue;
		visited[i] = 1;
		ans[index] = i;
		if (DFS(index + 1, sum + c(n-1,index)*i))
			return 1;
		visited[i] = 0;
	}
	return 0;
}

int main() {
	cin >> n >> total;
	if (DFS(0,0))
		for (int i = 0; i < n; ++i)
			cout << ans[i] << " ";
	return 0;
}