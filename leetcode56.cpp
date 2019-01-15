#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string ans;
		for (int i = 0; i<numRows; ++i) {
			int cycle = 2 * (numRows - 1);
			if (i == 0 || i == numRows - 1) {
				for (int j = i; j<s.length(); j += cycle)
					ans += s[j];
				continue;
			}
			int now = i, adds = cycle - 2 * i;
			ans += s[now];
			while (now + adds<s.length()) {
				now += adds;
				ans += s[now];
				adds = cycle - adds;
			}
		}
		return ans;
	}
};
int main() {
	Solution s;
	auto output = s.convert("PAYPALISHIRING",3);
	return 0;
}