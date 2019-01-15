#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	
	int n, k, val;
	char ch;
	while (cin >> n >> k){
		priority_queue<int,vector<int>,greater<int>> num;
		for (int i = 0; i < n; ++i) {
			cin >> ch;
			if (ch == 'I') {
				cin >> val;
				num.push(val);
				if (num.size() > k)
					num.pop();
			}
			else
				cout << num.top() << endl;
		}
	}
	return 0;
}