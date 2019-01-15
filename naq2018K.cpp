#include <bits/stdc++.h>
using namespace std;



int main() {
	string input,ans=""; char type;
	cin >> type >> input;
	if (type == 'E') {
		int cnt = 0;
		for (int i = 0; i < input.length(); ++i) {
			if (cnt == 0) 
				++cnt;
			else {
				if (input[i] == input[i - 1]) 
					++cnt;
				else {
					ans += input[i - 1];
					ans += ('0' + cnt);
					cnt = 1;
				}
			}
		}
		if (cnt) {
			ans += input[input.length()-1];
			ans += ('0' + cnt);
		}
	}
	else {
		for (int i = 0; i < input.length(); i += 2) {
			for (int j = 0; j < input[i + 1] - '0'; ++j) {
				ans += input[i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}