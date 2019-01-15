#include <bits/stdc++.h>
using namespace std;


bool cmp(char x,char y) {
	if (abs(x - y) == 'a' - 'A')
		return (x < y);
	if (x >= 'a' && x <= 'z')
		x += 'A' - 'a';
	if (y >= 'a' && y <= 'z')
		y += 'A' - 'a';
	return (x<y);
}


int main() {
	int n;
	char str[20];
	cin >> n;
	while (n--) {
		memset(str, 0, sizeof(str));
		cin >> str;
		int len = strlen(str);
		sort(str, str + len, cmp);
		do {
			cout << str << endl;
		} while (next_permutation(str, str + len, cmp));
	}
	return 0;
}