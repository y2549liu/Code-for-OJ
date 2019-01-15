#include <bits/stdc++.h>
using namespace std;
int n;
set<int> box;
#define delta 2000
int Data[2*delta+1];

void BFS() {
	memset(Data, 0x7f, sizeof(Data));
	queue<int> Q;
	for (auto i : box) {
		Data[i + delta] = 1;
		Q.push(i+ delta);
	}
	while (!Q.empty() ) {
		int now = Q.front(); Q.pop();
		for (auto i : box) {
			int next = now + i;
			if (abs(next) <= delta && Data[next] == 0x7f7f7f7f){
				Data[next] = Data[now] + 1;
				Q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		box.insert(tmp);
	}
	BFS();
	if (Data[delta] == 0x7f7f7f7f)
		Data[delta] = -1;
	cout << Data[2000] << endl;
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
int n;
set<int> box;
#define delta 4000
int dp[2*delta+10];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		box.insert(tmp);
	}
	//the task is imposible only if all cards are positive or negative
	if (box.count(0)) {
		printf("1\n");
		return 0;
	}
	else if (*box.begin() > 0 || *box.rbegin() < 0) {
		printf("-1\n");
		return 0;
	}
	memset(dp, 0x7f, sizeof(dp));
	for (auto i : box) {
		dp[i + delta] = 1;
		if (i>0)
			for (int j = i; j <= 2 * delta; ++j) {
				dp[j] = min(dp[j], dp[j - i] + 1);
			}
		else
			for (int j = 2*delta + i; j >= 0; --j) {
				dp[j] = min(dp[j], dp[j - i] + 1);
			}
	}
	cout << dp[delta] << endl;
	return 0;
}
*/