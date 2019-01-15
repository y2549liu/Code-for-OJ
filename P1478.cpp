#include <bits/stdc++.h>
using namespace std;
int n, s, h, b;
struct apple {
	int x, y;
	bool operator< (const apple& x)const {
		return y < x.y;
	}
};
vector<apple> apptree;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> h >> b;
	h += b;
	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x > h)
			continue;
		apptree.push_back({ x,y });
	}
	sort(apptree.begin(),apptree.end());
	int ans=0;
	while (ans < apptree.size() && s >= apptree[ans].y) {
		s -= apptree[ans].y;
		++ans;
	}
	cout << ans << endl;
	return 0;
}