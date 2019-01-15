#include <bits/stdc++.h>
using namespace std;
struct party {
	priority_queue<int,vector<int>,greater<int>> money;
}P[3001];
int main() {
	int n, m;
	cin >> n >> m;
	int sup, mon;
	for (int i = 0; i < n; ++i) {
		cin >> sup >> mon;
		P[sup].money.push(mon);
	}
	int now = P[1].money.size();

	struct pr {
		unsigned int size;
		int no;
		bool operator<(const pr &x)const {
			return (size == x.size)?(no<x.no):(size>x.size);
		}
	};
	set<pr> mp;
	for (int i = 2; i <= m; ++i) {
		if (P[i].money.size()) {
			mp.insert({ P[i].money.size(), i });
		}
	}
	if (mp.size() == 0)
	{
		cout << "0";
		return 0;
	}
	int maxsize = mp.begin()->size,ans=0;
	int mincost=0x7fffffff, mingroup;
	while (now <= maxsize) {
		auto iter = mp.begin();
		auto miniter = mp.begin();
		mincost = 0x7fffffff;
		if (++iter==mp.end() || iter->size == maxsize || now==maxsize) {
			--iter;
			while (iter != mp.end()) {
				if (P[iter->no].money.top() < mincost) {
					mincost = P[iter->no].money.top();
					mingroup = iter->no;
					miniter = iter;
				}
				++iter;
			}
			ans += P[mingroup].money.top();
			P[mingroup].money.pop();
			mp.erase(miniter);
			if (P[mingroup].money.size())
				mp.insert({ P[mingroup].money.size(), mingroup });
			++now;
		}
		else {
			iter = mp.begin();
			miniter = mp.begin();
			mincost= P[iter->no].money.top()/2;
			mingroup = iter->no;
			while (iter != mp.end()) {
				if (P[iter->no].money.top() < mincost) {
					mincost = P[iter->no].money.top();
					mingroup = iter->no;
					miniter = iter;
				}
				++iter;
			}
			if (miniter == mp.begin())
				--maxsize;
			ans += P[mingroup].money.top();
			P[mingroup].money.pop();
			mp.erase(miniter);
			if (P[mingroup].money.size())
				mp.insert({ P[mingroup].money.size(), mingroup });
			++now;
		}
	}
	cout << ans;
	return 0;
}