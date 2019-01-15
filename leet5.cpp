#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int ans = 0, start=0;
		for (int i = 0; i<s.length(); ++i) {
			int j = 0;
			while (i - j>=0 && j + i<s.length() && s[i - j] == s[j + i])
				++j;
			if (2 * j - 1>ans) {
				ans = 2 * j - 1;
				start = i - j+1;
			}
			j = 0;
			while (i - j>=0 && j + i + 1<s.length() && s[i - j] == s[j + i + 1])
				++j;
			if (2 * j>ans) {
				ans = 2 * j;
				start = i - j + 1;
			}
		}
		return s.substr(start, ans);
	}
};
int main() {
	Solution s;
	cout<<s.longestPalindrome("");
	return 0;
}