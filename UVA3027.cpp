#include <bits/stdc++.h>
using namespace std;
const int maxn = 20001;
int pa[maxn],t, n,a,b;
void init() {
	for (int i = 1; i <= n; ++i)
		pa[i] = i, d[i] = 0;
}
int findpa(const int &x) {
	return  (x == pa[x]) ? 0 : ((abs(x - pa[x])) % 1000) + findpa(pa[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		init();
		char act;
		while (cin >> act && act != 'O') {
			if (act == 'E') {
				cin >> a;
				cout << findpa(a)<<endl;
			}
			else {
				cin >> a >> b;
				pa[a] = b;
			}
		}
	}
	return 0;
}