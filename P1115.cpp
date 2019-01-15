#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0,ans=-1000000,tmp;
	cin >> n;
	while (n--) {
		cin >> tmp;
		ans = max(ans, tmp);
		if (sum + tmp <= 0)
			sum = 0;
		else 
			ans = max(ans, sum += tmp);
	}
	cout << ans;
	return 0;
}