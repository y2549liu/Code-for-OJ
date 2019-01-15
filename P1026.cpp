#include <bits/stdc++.h>
using namespace std;
int dp[201][201], word[201][201];
vector<string> vs;
int p, k, n;
string s, tmp;
void countword() {
	for (int j = s.length(); j > 0; --j) {
		for (int i = j-1; i >= 0; --i) {
			word[i][j] = word[i + 1][j];
			string sub = s.substr(i, j - i);
			for (auto w : vs) {
				if (strncmp(sub.c_str(),w.c_str(),w.length())== 0) {
					++word[i][j];
					break;
				}
			}
		}
	}
}

int main() {
	cin >> p >> k;
	while (p--) {
		cin >> tmp;
		s += tmp;
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		vs.push_back(tmp);
	}
	countword();
	for (int i = 1; i <= s.length(); ++i) {
		for (int seg = 1; seg <= min(i,k); ++seg) {
			for (int j = seg-1; j < i; ++j) {
				dp[i][seg] = max(dp[i][seg], dp[j][seg - 1] + word[j][i]);
			}
			//printf("i:%d seg:%d dp:%d\n", i, seg, dp[i][seg]);
		}
	}
	cout << dp[s.length()][k];
	return 0;
}