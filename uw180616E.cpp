#include <bits/stdc++.h>
using namespace std;

int translate(string &str) {
	int ans=0;
	for (auto i : str) {
		if (i == '-')
			continue;
		else if (i<='9' && i>='0')
			ans = 10 * ans + i- '0';
		else if (i >= 'A' && i <= 'C') 
			ans = 10 * ans + 2;
		else if (i<='F')
			ans = 10 * ans + 3;
		else if (i <= 'I')
			ans = 10 * ans + 4;
		else if (i <= 'L')
			ans = 10 * ans + 5;
		else if (i <= 'O')
			ans = 10 * ans + 6;
		else if (i <= 'S')
			ans = 10 * ans + 7;
		else if (i <= 'V')
			ans = 10 * ans + 8;
		else if (i <= 'Y')
			ans = 10 * ans + 9;
	}
	return ans;
}

int main() {
	int n; string str;
	cin >> n;
	map<int,int> ms;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		++ms[translate(str)];
	}
	for (auto i : ms) {
		if (i.second > 1) {
			cout.width(3);
			cout.fill('0');
			cout <<i.first / 10000;
			cout << "-" << i.first % 10000 << " " << i.second << endl;
		}
			
	}
	return 0;
}