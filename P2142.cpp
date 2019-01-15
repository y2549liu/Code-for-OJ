#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


vi bigminus(const vi& a, const vi &b) {
	vi ans = a;
	for (int i = 0; i < a.size(); ++i) {
		if (i<b.size())
			ans[i] -= b[i];
		if (ans[i] < 0) {
			--ans[i + 1];
			ans[i] += 10;
		}
	}

	int i = ans.size()-1;
	while (ans[i]==0 && i) 
		--i;
	ans.resize(i + 1);
	return ans;
}

int main(){
	string s1,s2;
	vi a, b;
	cin >> s1>> s2;
	if (s1 == s2)
	{
		cout << "0";
		return 0;
	}
	for (int i = s1.length() - 1; i >= 0; --i)
		a.push_back(s1[i] - '0');
	for (int i = s2.length() - 1; i >= 0; --i)
		b.push_back(s2[i] - '0');
	
	if (s1.length() >s2.length() || (s1.length()==s2.length() && s1 > s2)) {
		vi ans = bigminus(a, b);
		for (int i = ans.size() - 1; i >= 0; --i) {
			cout << ans[i];
		}
	}
	else {
		vi ans = bigminus(b, a);
		cout << "-";
		for (int i = ans.size() - 1; i >= 0; --i) {
			cout << ans[i];
		}
	}
	return 0;
}