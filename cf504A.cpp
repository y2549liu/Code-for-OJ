#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	if (n > m + 1)
	{
		cout << "NO";
		return 0;
	}
	size_t loc = s.find('*');
	if (loc == string::npos) {
		if (s == t)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	else {
		if (s.substr(0, loc) != t.substr(0, loc)\
			|| s.substr(loc + 1, n - loc - 1) != t.substr(m - n + loc + 1, n - loc - 1)) {
			cout << "NO";
			return 0;
		}
		for (int i = loc; i <= ((int)loc + m - n); ++i){
			if (t[i] > 'z' || t[i] < 'a') {
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
	}
	return 0;
}