#include <bits/stdc++.h>
using namespace std;
int main() {
	map<string, int> dict;
	dict["one"] = 1;
	dict["two"] = 2;
	dict["three"] = 3;
	dict["four"] = 4;
	dict["five"] = 5;
	dict["six"] = 6;
	dict["seven"] = 7;
	dict["eight"] = 8;
	dict["nine"] = 9;
	dict["ten"] = 10;
	dict["eleven"] = 11;
	dict["twelve"] = 12;
	dict["thirteen"] = 13;
	dict["fourteen"] = 14;
	dict["fifteen"] = 15;
	dict["sixteen"] = 16;
	dict["seventeen"] = 17;
	dict["eighteen"] = 18;
	dict["nineteen"] = 19;
	dict["twenty"] = 20;
	dict["a"] = 1;
	dict["both"] = 2;
	dict["another"] = 1;
	dict["first"] = 1;
	dict["second"] = 2;
	dict["third"] = 3; 
	string s[7]; 
	int i = 0,t;
	int num[6];
	while (cin >> s[i]) {
		if (s[i][0] == '.')
			break;
		else if (s[i][s[i].size() - 1] == '.')
			s[i][s[i].size() - 1] == '\0';
		if (t=dict[s[i]]) {
			num[i] = (t*t) % 100;
			++i;
		}
	}
	sort(num, num + i);
	string ans;
	for (int j = 0; j < i; ++j) {
		if (num[j] < 10) {
			ans += '0';
			ans += char(num[j] + '0');
		}
		else {
			ans += char(num[j] / 10 + '0');
			ans += char(num[j] % 10 + '0');
		}
	}
	i = 0;
	while (ans[i] == '0')
		++i;
	cout << ans.c_str() + i;
	return 0;
}