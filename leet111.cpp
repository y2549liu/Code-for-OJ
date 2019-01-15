#include <bits/stdc++.h>
using namespace std;
/*
vector<int> diStringMatch(string S) {
	vector<int> ans;
	int now = 0;
	int first = 0, last;
	int i = 1;
	for (; i <= S.length(); ++i) {
		if (i == S.length() || S[i] == 'I') {
			last = i;
			if (first == 0 && S[first] == 'I')
				ans.push_back(0);

			for (int j = last; j > first; --j)
				ans.push_back(j);
			if (first == 0 && S[first] == 'D')
				ans.push_back(0);
			first = i;
		}
	}
	return ans;
}
int main() {
	vector<int> ans = diStringMatch("IDID");
	return 0;
}
*/