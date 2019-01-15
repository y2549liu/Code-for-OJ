#include <bits/stdc++.h>
using namespace std;

int n1[40001], n2[40001];
int ans = 0;
void merge(int start, int end) {
	if (end - start <= 1) 
		return;
	int mid = (start + end) / 2;
	merge(start, mid);
	merge(mid, end);
	int c1 = start, c2 = mid, cnt=0;
	while (c1 < mid && c2 < end) {
		if (n1[c1] <= n1[c2]) {
			n2[(cnt++) + start] = n1[c1++];
		}
		else {
			n2[(cnt++) + start] = n1[c2++];
			ans+=(mid-c1);
		}
	}
	if (c1 == mid) {
		for (int i = c2; i < end; ++i) {
			n2[start+ cnt++] = n1[i];
		}
	}
	else {
		//ans += (mid - c1)*(end-mid);
		for (int i = c1; i < mid; ++i) {
			n2[start+ cnt++] = n1[i];
		}
	}
	memcpy(n1 + start, n2 + start, (end - start) * sizeof(int));
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> n1[i];
	}
	merge(0, n);
	cout << ans;
	return 0;
}
