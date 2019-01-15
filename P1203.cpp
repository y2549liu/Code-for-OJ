#include <bits/stdc++.h>
using namespace std;
int len;
int getloc(int n) {
	return (n%len + len) % len;
}
// n belongs to [0,len-1]
int count(string str,int n) {
	int ans = 0;
	int i = n;
	while (str[getloc(i)] == str[n] || str[getloc(i)]=='w' || str[n]=='w' ) {
		++ans;
		if (str[getloc(i)] != 'w' && str[n] == 'w')
			str[n] = str[getloc(i)];
		i--;
		if (ans >= len)
			return len;
	}
	i = n = getloc(n + 1);
	while (str[getloc(i)] == str[n] || str[getloc(i)] == 'w' || str[n] == 'w') {
		if (str[getloc(i)] != 'w' && str[n] == 'w')
			str[n] = str[getloc(i)];
		i++;
		++ans;
		if (ans >= len)
			return len;
	}
	return ans;
}

int main() {
	string necklace;
	cin >> len >> necklace;
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		ans = max(ans, count(necklace, i));
	}
	cout << ans;
	return 0;
}