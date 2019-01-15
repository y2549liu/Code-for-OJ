#include <bits/stdc++.h>
using namespace std;

//suppose width always exceeds length
struct block {
	int w, l, h;
	bool operator<(const block& x)const {
		return (w*l < x.w*x.l);
	}
	bool operator>(const block& x)const {
		return (w> x.w && l>x.l);
	}
};

int main() {
	int n,cnt=0;
	while (cin >> n && n) {
		++cnt;
		int ans=0,a[3];
		set<block> B;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j)
				cin >> a[j];
			sort(a, a + 3);
			B.insert({ a[2],a[1],a[0] });
			B.insert({ a[1],a[0],a[2] });
			B.insert({ a[2],a[0],a[1] });
		}
		vector<block> blocks(B.begin(), B.end());
		vector<int> dp(blocks.size());
		//get the maximun increasing subseqence
		for (int i = 0; i < blocks.size();++i) {
			dp[i] = blocks[i].h;
			for (int j = 0; j < i; ++j) {
				if (blocks[i] > blocks[j]) 
					dp[i] = max(dp[i], dp[j] + blocks[i].h);
			}
			ans = max(ans, dp[i]);
		}
		printf("Case %d: maximum height = %d\n",cnt,ans);
	}
	return 0;
}