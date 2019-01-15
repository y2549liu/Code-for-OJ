#include <bits/stdc++.h>

using namespace std;
int bucket[51],N,l,maxL=0,minL=0x7fffffff,tot=0;
void dfs(int n,int len,int cur,int remain) {
	if (n == 0){
		cout << len;
		exit(0);
	}
	if (remain == 0) 
		dfs(n - 1, len, maxL, len);
	else for (int i = cur; i >= minL; --i) {
		if (bucket[i]) {
			--bucket[i];
			dfs(n, len, min(i, remain - i), remain - i);
			++bucket[i];
			if (remain == len || remain == i)
				return;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> l;
		if (l > 50) 
			continue;
		++bucket[l];
		maxL = max(maxL, l);
		minL = min(minL, l);
		tot += l;
	}
	for (int i = maxL; i <= (tot << 1); ++i) {
		if (tot%i == 0)
			dfs(tot / i, i, maxL, i);
	}
	cout << tot;
	return 0;
}