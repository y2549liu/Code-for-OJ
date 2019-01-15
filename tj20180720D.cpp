#include <bits/stdc++.h>
using namespace std;
int A[30001];



int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--) {
		int m, n, cnt = 0;
		cin >> m >> n;
		for (int i = 0; i < m; ++i)
			cin >> A[i];
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		for (int i = 0; i < n; ++i) {
			//n get
			int gap;
			cin >> gap;
			while (cnt < gap) {
				if (cnt<m)
					right.push(A[cnt++]);
				while (right.size() && left.size() && left.top() > right.top())
				{
					int rtop = right.top();
					right.pop();
					left.push(rtop);
					right.push(left.top());
					left.pop();
				}
			}
			cout << right.top() << endl;
			left.push(right.top());
			right.pop();
		}
		if (N)
			cout << endl;
	}
	return 0;
}