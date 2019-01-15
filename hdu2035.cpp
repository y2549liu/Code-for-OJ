#include <bits/stdc++.h>
using namespace std;
const int mod = 1000;
int fpow(int a, int b) {
	return (a==1||b==0)?1:(b==1)?a:(fpow((a*a) % mod, b >> 1) * ((b & 1) ? a : 1))% mod;
}
int main() {
	int a, b;
	while (cin >> a >> b && (a+b)) 
		cout << fpow(a%mod, b) << endl;
	return 0;
}