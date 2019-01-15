#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi mul(const vi &a, const vi &b) {
	vi ans(500);
	for (int i = 0; i < 500; ++i) {
		for (int j = 0; j <= i; ++j) {
			ans[i] += a[j] * b[i - j];
		}
		if (ans[i] >= 10) {
			if (i < 499) 
				ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}
	return move(ans);
}

vi fastPow(const vi &x,const int &exp) {
	if (exp == 1)
		return x;
	vi tmp = fastPow(x, exp / 2);
	if (exp & 1)
		return move(mul(mul(tmp, tmp), x));
	else
		return move(mul(tmp, tmp));
}


int main() {
	int p;
	cin >> p;
	vi x(500);
	x[0] = 2;
	vi ans = fastPow(x, p);
	ans[0] -= 1;
	cout<<ceil(log10(2)*p)<<endl;
	for (int i = 499; i >= 0; --i) {
		cout << ans[i];
		if (i % 50 == 0)
			printf("\n");
	}
	return 0;
}