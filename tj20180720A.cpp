#include <bits/stdc++.h>
using namespace std;

struct client {
	int no, priority;
	bool operator <(const client &x) const {
		return priority < x.priority;
	}
};

int main() {
	ios::sync_with_stdio(false);
	set<client> waitList;
	int code, k, p;
	while (cin >> code && code) {
		if (code == 1) {
			cin >> k >> p;
			waitList.insert({ k,p });
		}
		else{
			if (waitList.size() == 0)
			{
				cout << '0' << endl;
				continue;
			}

			if (code==3) {
				auto iter = waitList.begin();
				cout << iter->no << endl;
				waitList.erase(iter);
			}
			else {
				auto iter = waitList.end();
				iter--;
				cout << iter->no << endl;
				waitList.erase(iter);
			}
		}

	}
	return 0;
}