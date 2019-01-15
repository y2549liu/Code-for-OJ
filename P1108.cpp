#include <bits/stdc++.h>
using namespace std;
const int maxn=5001;
int p[maxn], l[maxn], c[maxn], n;
int main() {
	int n,maxl=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		l[i] = 1;
		for (int j = 0; j < i; ++j) 
			if (p[j] > p[i])
				l[i] = max(l[i], l[j] + 1);
		for (int j = 0; j < i; ++j) 
			if (l[i] == l[j] && p[i] == p[j])
				c[j] = 0;
			else if (l[i] == l[j] + 1 && p[i] < p[j])
				c[i] += c[j];
		if (!c[i])
			c[i] = 1;
		maxl = max(maxl, l[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) 
		if (l[i] == maxl)
			sum += c[i];
	cout << maxl<<" "<< sum;
	return 0;
}