#include <bits/stdc++.h>
using namespace std;

double k, b;
int main() {
	ios::sync_with_stdio(false);
	while (cin >> k >> b) {
		if (k > 0)
			cout << "Increasing\n";
		else if (k < 0)
			cout << "Decreasing\n";
		else
			cout << "Constant\n";
	}
	return 0;
}