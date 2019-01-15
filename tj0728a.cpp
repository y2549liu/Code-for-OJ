#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 3) {
		cout << "0";
		return 0;
	}
	vector<int> num(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
	}
	int i = 1;
	while (i<n && num[i + 1] == num[i])
		++i;

	//at least n-1 elements are same;
	if (i >= n-1) {
		cout << "0";
		return 0;
	}
	//remember it
	int start = i;
	if (num[i + 1] > num[i]) {
		//try to find the decrease point;
		while (i < n && num[i + 1] >= num[i]) ++i;
		if (i < n) {
			cout << "3\n" << start << " " << i << " " << i + 1;
			return 0;
		}
	}
	i = start;
	if (num[i + 1] <num[i]) {
		//try to find the increase point;
		while (i < n && num[i + 1] <= num[i]) ++i;
		if (i < n) {
			cout << "3\n" << start << " " << i << " " << i + 1;
			return 0;
		}
	}
	cout << "0";
	return 0;
}