#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, len;
	string str;
	cin >> t;
	while (t--) {
		cin >> len >> str;
		bool flag = 1;
		for (int i = 0; i < len / 2; ++i) {
			if (abs(str[i] - str[len - 1 - i]) !=2  && str[i] != str[len - 1 - i]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}