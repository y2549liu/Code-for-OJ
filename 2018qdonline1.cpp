#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << m << " ";
		if (n == m)
			cout << m << endl;
		else
			cout << ceil(double(n + 1) / (n - m +1)) - 1<<endl;

	}
	return 0;
}