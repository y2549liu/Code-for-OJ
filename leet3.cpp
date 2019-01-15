//leetcode: Longest Substring Without Repeating Characters
//sliding windows
#include <iostream>
#include <cstring>
#include <map>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int lengthOfLongestSubstring(string s) {
	map<int, int> existedCh;
	int ans = 0, cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		char c = s[i];
		if (existedCh[c]) {
			ans = max(ans, cnt);
			for (int j = i - cnt; j < existedCh[c]; ++j)
				existedCh.erase(s[j]);
			existedCh[c] = i + 1;
			cnt = existedCh.size();
		}
		else {
			existedCh[c] = i + 1;
			++cnt;
		}
	}
	ans = max(ans, cnt);
	return ans;
}
int main() {
	cout << lengthOfLongestSubstring("pwwkew");
	return 0;
}