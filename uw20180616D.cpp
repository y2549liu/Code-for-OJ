#include <bits/stdc++.h>
using namespace std;
int mp[101][101],n;
int checkGame() {
	int cnt[2] = { 0,0 };
	for (int i = 1; i <= n; ++i) {
		if (mp[i][1] == 0)
			continue;
		bool flag = 1;
		for (int j = 1; j <= n; ++j) {
			if (mp[i][j] != mp[i][1])
			{
				flag = 0; 
				break;
			}
		}
		if (flag)
			++cnt[mp[i][1] - 1];
	}
	for (int i = 1; i <= n; ++i) {
		if (mp[1][i] == 0)
			continue;
		bool flag = 1;
		for (int j = 1; j <= n; ++j) {
			if (mp[j][i] != mp[1][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			++cnt[mp[1][i] - 1];
	}
	if (cnt[0] > cnt[1]) {
		cout << "X WINS\n";
		exit(0);
	}
	else if (cnt[0] < cnt[1]) {
		cout << "O WINS\n";
		exit(0);
	}
	return 0;
}
int main() {
	cin >> n;
	char side; int no;
	int people = 1;
	while (cin >> side >> no) {
		switch(side) {
			int firstAv;
			case 'L':
				//find frist available square
				firstAv = 1;
				while (firstAv < n && mp[no][firstAv]) ++firstAv;
				for (int i = firstAv - 1; i >= 1; --i) 
					mp[no][i + 1] = mp[no][i];
				mp[no][1] = people;
				break;
			case 'R':
				firstAv = n;
				while (firstAv > 1 && mp[no][firstAv]) --firstAv;
				for (int i = firstAv; i < n; ++i)
					mp[no][i] = mp[no][i+1];
				mp[no][n] = people;
				break;
			case 'T':
				firstAv = 1;
				while (firstAv < n && mp[firstAv][no]) ++firstAv;
				for (int i = firstAv - 1; i >= 1; --i)
					mp[i+1][no] = mp[i][no];
				mp[1][no] = people;
				break;
			case 'B':
				firstAv = n;
				while (firstAv > 1 && mp[firstAv][no]) --firstAv;
				for (int i = firstAv; i < n; ++i)
					mp[i][no] = mp[i + 1][no];
				mp[n][no] = people;
				break;
		}
		checkGame();
		people = 3 - people;
	}
	cout << "TIE GAME\n";
	return 0;
}