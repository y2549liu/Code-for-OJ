#include <bits/stdc++.h>
using namespace std;
int cmp(string &a, string &b) {
	return (a + b > b + a);
	/* ¿¨ª¯∞Ê 
	int i;
	for (i = 0; i < min(a.length(), b.length()); ++i) {
		if (a[i] > b[i])//¥Û”≈œ»
			return 1;
		else if (a[i] < b[i])
			return 0;
	}
	if (a.length() < b.length())
		return (a[0] > b[i]);
	else if (a.length() < b.length())
		return 0;
	else 
		return (a[i] > b[0]);
	*/
}
int main() {
	int n;
	string s[20];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; ++i)
		cout << s[i];
	return 0;
}