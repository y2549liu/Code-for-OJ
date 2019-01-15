#include <bits/stdc++.h>
using namespace std;
const int mod = 10e9 + 7;
int num[20000];
int main() {
	int t,n;
	cin >> t;
	while (t--) {
		cin >> n;
		num[1] = 1;
		num[2] = 1;
		//cout << 1 << " " << 1<<" ";
		for (int i = 3; i <= n; ++i)
		{
			num[i] = num[i - num[i - 1]] + num[i - 1 - num[i - 2]];
		}
		int cnt = 1;
		int tot=0;
		for (int i = 2; i <= n; ++i)
		{
			if (num[i] == num[i - 1])
				++cnt;
			else {
				cout << cnt << " ";
				++tot;
				if (tot % 8 == 0)
					cout << endl;
				cnt = 1;
			}
		}
	}
	return 0;
}