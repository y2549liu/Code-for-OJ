#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	char str[52];
	cin >> n >> k;
	cin >> str;
	sort(str, str + n);
	int ans = 0,len = 0;
	char pre = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] > pre+1)
		{
			len++;
			ans += str[i] - 'a' + 1;
			pre = str[i];
		}
		if (len == k)
			break;
	}
	if (len == k)
		cout << ans;
	else
		cout << "-1";
	return 0;
}
