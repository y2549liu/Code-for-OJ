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
				//���浱ǰժ��ƻ���ı�ź͸߶�
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
			//�ҵ� �޸ĵ�ƻ��p �ڲ�ժƻ�������е�λ��
			int pos = lower_bound(pickno + 1, pickno + cnt + 1, p)-pickno;
			//��ƻ����������ժ
			if (pickno[pos] == p) {
				//ƻ����ߣ��޳��߶�<= ����ƻ��
				if (q > pickh[pos]) {
					int endpos = upper_bound(pickh + 1, pickh + cnt + 1, q) - pickh;
					cout << cnt - endpos + pos + 1 ;
				}
				else {
					int increase = 0, pre = pickh[pos - 1];
					//���ƻ������
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
			//��ƻ������������ժ
			else {
				//���ڱ�ժ
				if (q > pickh[pos - 1]) {
					int endpos = upper_bound(pickh + 1, pickh + 1 + cnt, q) - pickh;
					cout << cnt + pos - endpos + 1;
				}
				// ���ǲ�ժ
				else 
					cout << cnt;
			}
			cout << endl;
		}
	}
	return 0;
}