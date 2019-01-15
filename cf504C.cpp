#include <bits/stdc++.h>
using namespace std;
bool vis[200001];
int main() {
	int n, k;string str;
	cin >> n >> k >> str;
	stack<pair<char,int>> s;
	string ans;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '(') {
			s.push(make_pair('(', i));
		}
		else {
			if (s.size()) {
				vis[s.top().second] = 1;
				vis[i] = 1;
				s.pop();
				cnt += 2;
				if (cnt == k)
					break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (vis[i])
			putchar(str[i]);
	}
	return 0;
}