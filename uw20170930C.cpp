#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, arr[200001];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i <= n - k; ++i) {
		ans = max(ans, arr[i + k - 1] - arr[i]);
	}
	cout << ans;
	return 0;
}