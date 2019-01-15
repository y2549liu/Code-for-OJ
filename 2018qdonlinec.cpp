#include <bits/stdc++.h>
using namespace std;
bool vis[10001][256];
int act[10001][3];
string acdict[5] = { "add","beq","bne","blt","bgt" };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(act, 0, sizeof(act));
		cin >> n;
		string action;
		for (int i = 0; i < n; ++i) {
			cin >> action;
			for (int j = 0; j < 5; ++j) {
				if (action == acdict[j]) {
					act[i][0] = j;
					if (j == 0)
						cin >> act[i][1];
					else
						cin >> act[i][1] >> act[i][2],--act[i][2];
					break;
				}
			}
		}
		int reg = 0, actno=0;
		while (actno < n && !vis[actno][reg]) {
			vis[actno][reg] = 1;
			switch (act[actno][0]) {
				case 0:
					reg = reg + act[actno][1]; ++actno; break;
				case 1:
					actno = (reg == act[actno][1]) ? act[actno][2] : actno + 1; break;
				case 2:
					actno = (reg != act[actno][1]) ? act[actno][2] : actno + 1; break;
				case 3:
					actno = (reg < act[actno][1]) ? act[actno][2] : actno + 1; break;
				case 4:
					actno = (reg > act[actno][1]) ? act[actno][2] : actno + 1; break;
			}
			reg %= 256;
		}
		if (actno == n)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}