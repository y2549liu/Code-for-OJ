#include <bits/stdc++.h>
using namespace std;
int k;
long long qPow(long long b, long long p) {
	if (b == 0)
		return 0;
	if (p == 1)
		return b%k;
	if (p == 0)
		return 1;
	long long ans = qPow(b, p >> 1);
	ans *= ans;
	ans %= k;
	if (p & 1)
		return (b*ans)%k;
	else 
		return ans;
}

int main(){
	long long b, p;
	cin >> b >> p >> k;
	cout << b<< "^"<<p <<" mod "<<k<<"=" << qPow(b, p)%k ;
	return 0;
}