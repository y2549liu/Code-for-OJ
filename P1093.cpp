#include <bits/stdc++.h>
using namespace std;
struct stu {
	int chn, math, eng, tot, no;
	bool operator<(const stu &x) const{
		if (tot < x.tot)
			return 1;
		else if (tot == x.tot && chn < x.chn)
			return 1;
		else if (tot == x.tot && chn == x.chn)
			return (no > x.no);
		return 0;
	}
};
priority_queue<stu> Q;
int main() {
	int n,c,m,e;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c >> m >> e;
		Q.push({ c,m,e,c + m + e,i });
	}
	for (int i = 0; i < 5;++i) {
		cout << Q.top().no << " "<< Q.top().tot << endl;
		Q.pop();
	}
	return 0;
}