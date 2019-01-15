#include <bits/stdc++.h>

using namespace std;
struct seg {
	int l, r;
	bool operator<(const seg& x)const {
		if (r == x.r)
			return (l < x.l);
		else
			return (r < x.r);
	}
};


int main()
{
	int n; cin >> n;
	priority_queue<seg> segQ;
	int left, right;
	while (cin >> left >> right) {
		if (left > right)
			swap(left, right);
		segQ.push({ left, right });
	}
	int tot = 0;
	int end=1;
	while (segQ.size()) {
		if (segQ.top().l >= end) {
			end = segQ.top().r;
			++tot;
		}
		segQ.pop();
	}
	cout << tot;
	return 0;
}
