#include <bits/stdc++.h>
using namespace std;
#define maxn 1000001
bool isPrime[maxn];
int num[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	memset(isPrime+2, 0x01, (maxn-2)*sizeof(bool)); // 0,1 is not prime
	int p = 2;
	while (p <= m) {
		int i;
		for (i = p<<1 ; i <= m; i += p) 
			isPrime[i] = 0;
		for (i = p + 1; i <= m; ++i)
			if (isPrime[i])
				break;
		p = i;
	}
	for (int i = 1; i <= m; ++i) {
		num[i] = num[i - 1] + isPrime[i];
	}
	int low, high;
	for (int i = 0; i < n; ++i) {
		cin >> low >> high;
		if (high > m || low <1)
			printf("Crossing the line\n");
		else
			printf("%d\n", num[high] - num[low - 1]);
	}
	return 0;
}