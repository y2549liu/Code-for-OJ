#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//vi µÍÎ»ÔÚÇ°
vi bigmul(const vi& a ,const vi &b) {
	vi ans(a.size() + b.size());
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			ans[i + j] += a[i] * b[j];
			ans[i + j + 1] += ans[i + j] / 10;
			ans[i + j] %= 10;
		}
	}
	int i = ans.size()-1;
	while (ans[i] == 0 && i) --i;
	ans.resize(i + 1);
	return ans;
}



int main() {
	string s;
	vi a, b;
	char t; 
	int sig = 1;
	cin >> s;
	for (int i = s.length()-1; i >=0;--i) {
		if (s[i] == '-')
			sig *= -1;
		else
			a.push_back(s[i] - '0');
	}
	cin >> s;
	for (int i = s.length() - 1; i >= 0; --i) {
		if (s[i] == '-')
			sig *= -1;
		else
			b.push_back(s[i] - '0');
	}

	vi ans = bigmul(a, b);
	if (sig == -1 && ans[ans.size()-1])
		cout << "-";
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i];
	return 0;
}