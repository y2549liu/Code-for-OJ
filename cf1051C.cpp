#include <bits/stdc++.h>
using namespace std;
int num[101];
int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		++mp[num[i]];
	}
	int appear[4] = { 0 };
	for (auto ele : mp) {
		if (ele.second <= 2)
			++appear[ele.second];
		else
			++appear[3];
	}
	if (appear[1] & 1 && appear[3] == 0)
		puts("NO\n");
	else {
		puts("YES");
		if (appear[1] & 1) {
			int cnt = 1,repnum=0; 
			bool flag = 1;
			for (int i = 0; i < n; ++i) {
				if (mp[num[i]] == 1) {
					putchar('A' + ((cnt++) & 1));
				}
				else if (flag&&mp[num[i]]>2){
					repnum = num[i];
					flag = 0;
					putchar('A');
				}
				else 
					putchar('B');
			}
		}
		else 
			for (int i = 0, cnt = 0; i < n; ++i) {
				if (mp[num[i]] == 1)
					putchar('A' + ((cnt++) & 1));
				else
					putchar('A');
			}
				
	}
	return 0;
}