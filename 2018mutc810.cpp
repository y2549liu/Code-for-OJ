#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;

int h[maxn], pickh[maxn], pickno[maxn];
int main() {
	ios::sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int pre = 0xffffffff, cnt=0;
		for (int i = 1; i <= n; ++i) {
			cin >> h[i];
			if (h[i] > pre) {
				pre = h[i];
				//储存当前摘的苹果的编号和高度
				pickno[++cnt] = i;
				pickh[cnt] = h[i];
			}
		}
		//pickno[cnt + 1] = 0x7fffffff;
		//pickh[cnt + 1] = 0x7fffffff;
		for (int i = 1,p,q; i <= m; ++i) {
			cin >> p >> q;
			if (h[p] == q) {
				cout << cnt << endl;
				continue;
			}
			//找到 修改的苹果p 在采摘苹果序列中的位置
			int pos = lower_bound(pickno + 1, pickno + cnt + 1, p)-pickno;
			//该苹果本来被采摘
			if (pickno[pos] == p) {
				//苹果变高，剔除高度<= 它的苹果
				if (q > pickh[pos]) {
					int endpos = upper_bound(pickh + 1, pickh + cnt + 1, q) - pickh;
					cout << cnt - endpos + pos + 1 ;
				}
				else {
					int increase = 0, pre = pickh[pos - 1];
					//这个苹果保留
					if (q > pre) {
						++increase;
						pre = q;
					}
					for (int j = pickno[pos] + 1; j < pickno[pos + 1] && j <= n; ++j) {
						if (h[j] > pre) {
							++increase;
							pre = h[j];
						}
					}
					cout << cnt - 1 + increase;
				}
			}
			//该苹果本来不被采摘
			else {
				//现在被摘
				if (q > pickh[pos - 1]) {
					int endpos = upper_bound(pickh + 1, pickh + 1 + cnt, q) - pickh;
					cout << cnt + pos - endpos + 1;
				}
				// 还是不摘
				else 
					cout << cnt;
			}
			cout << endl;
		}
	}
	return 0;
}