#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> substitute;
set<string> s;
string src, des;

int BFS() {
	queue<pair<string, int>> Q;
	Q.push(make_pair(src, 0));
	while (!Q.empty()) {
		string now = Q.front().first;
		int t = Q.front().second;
		if (now == des)
			return t;
		if (t >= 10)
			return 0;
		
		Q.pop();
		for (auto i : substitute) {
			size_t pos = -1;
			while ((pos=now.find(i.first, pos+1)) != string::npos) {
				string tmp = now;
				tmp.replace(pos, i.first.length(), i.second);
				if (!s.count(tmp)) {
					s.insert(tmp);
					Q.push(make_pair(tmp, t + 1));
				}
			}
		}
	}
	return 0;
}
int main(){
	string t1, t2;
	cin >> src >> des;
	while (cin >> t1 >> t2) {
		substitute.push_back(make_pair(t1, t2));
	}
	int ans = BFS();
	if (ans)
		cout << ans;
	else
		printf("NO ANSWER!");
	return 0;
}