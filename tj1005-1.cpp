#include <bits/stdc++.h>
using namespace std;
int main() {
	int m;
	int cash[5] = { 50,20,10,5,1 };
	int n[5];
	while (cin >> m) {
		bool flag = 0;
		for (int i = 0; i < 5; ++i) {
			if (m >= cash[i]) {
				n[i] = m / cash[i];
				if (flag) 
					cout << '+';
				cout << cash[i] << '*' << n[i];
				m %= cash[i];
				flag = 1;
			}
		}
		cout << endl;
	}
	return 0;
}