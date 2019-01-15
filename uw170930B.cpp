#include <bits/stdc++.h>
using namespace std;
struct card {
	int rank, suit;
};

bool foak(vector<card> &hands) {
	int rnk[2] = { hands[0].rank,0 }, cnt[2] = { 1,0 };
	for (int i = 1; i < 5; ++i) {
		if (hands[i].rank == rnk[0])
			++cnt[0];
		else if (cnt[1] == 0) {
			++cnt[1];
			rnk[1] = hands[i].rank;
		}
		else if (hands[i].rank == rnk[1]) 
			++cnt[1];
		else
			return 0;
	}
	return (cnt[0] * cnt[1] == 4);
}
bool fh(vector<card> &hands) {
	int rnk[2] = { hands[0].rank,0 }, cnt[2] = { 1,0 };
	for (int i = 1; i < 5; ++i) {
		if (hands[i].rank == rnk[0])
			++cnt[0];
		else if (cnt[1] == 0) {
			++cnt[1];
			rnk[1] = hands[i].rank;
		}
		else if (hands[i].rank == rnk[1])
			++cnt[1];
		else
			return 0;
	}
	return (cnt[0] * cnt[1] == 6);
}
bool f(vector<card> &hands) {
	for (int i = 1; i < 5; ++i) {
		if (hands[i].suit != hands[0].suit)
			return 0;
	}
	return 1;
}
bool s(vector<card> &hands) {
	int a[5];
	for (int i = 0; i < 5; ++i) 
		a[i] = hands[i].rank;
	sort(a, a + 5);
	for (int i = 1; i < 5; ++i) {
		if (a[i] != a[i - 1] + 1)
			return 0;
	}
	return 1;
}
bool toak(vector<card> &hands) {
	map<int, int> mp;
	for (int i = 0; i < 5; ++i)
		++mp[hands[i].rank];
	for (auto i : mp) {
		if (i.second == 3)
			return 1;
	}
	return 0;
}
bool tp(vector<card> &hands) {
	map<int, int> mp;
	for (int i = 0; i < 5; ++i)
		++mp[hands[i].rank];
	int cnt = 0;
	for (auto i : mp) {
		if (i.second == 2)
			++cnt;
	}
	return (cnt==2);
}
bool op(vector<card> &hands) {
	map<int, int> mp;
	for (int i = 0; i < 5; ++i)
		++mp[hands[i].rank];
	for (auto i : mp) {
		if (i.second == 2)
			return 1;
	}
	return 0;
}
bool sf(vector<card> &hands) {
	return (f(hands) && s(hands));
}
int main() {
	int a, b, cnt[9] = { 0 };
	cin >> a >> b;
	card c1, c2;
	cin >> c1.rank >> c1.suit >> c2.rank >> c2.suit;
	vector<card> vc;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if ((c1.rank == i && c1.suit == j )||( c2.rank == i && c2.suit == j)) {
				continue;
			}
			vc.push_back(card{ i,j });
		}
	}
	for (int i = 0; i < vc.size() - 2; ++i) {
		for (int j = i + 1; j < vc.size() - 1; ++j) {
			for (int k = j + 1; k < vc.size(); ++k) {
				card &c3 = vc[i], &c4 = vc[j], &c5 = vc[k];
				if (sf(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[0];
					continue;
				}
				if (foak(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[1];
					continue;
				}
				if (fh(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[2];
					continue;
				}
				if (f(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[3];
					continue;
				}
				if (s(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[4];
					continue;
				}
				if (toak(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[5];
					continue;
				}
				if (tp(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[6];
					continue;
				}
				if (op(vector<card>{ c1,c2,c3,c4,c5 })) {
					++cnt[7];
					continue;
				}
				else {
					++cnt[8];
				}
			}
		}
	}
	for (int i = 0; i < 9; ++i)
		cout << cnt[i] << " ";
	cout << endl;
	return 0;
}