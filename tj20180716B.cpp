#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
stack<char> st;
vector<char> ans;
int len;
void DFS(int pushtimes,int poptimes) {
	if (pushtimes == len && poptimes == len) {
		//success
		for (auto i : ans) {
			printf("%c ", i);
		}
		printf("\n");
		return;
	}
	if (pushtimes < len) {
		st.push(s1[pushtimes]);
		ans.push_back('i');
		DFS(pushtimes + 1, poptimes);
		//flash back
		st.pop();
		ans.pop_back();
	}
	if (poptimes < len && poptimes < pushtimes && st.top() == s2[poptimes]) {
		char now = st.top();
		st.pop();
		ans.push_back('o');
		DFS(pushtimes, poptimes + 1);
		//flash back
		st.push(now);
		ans.pop_back();
	}
}


int main() {
	while (cin >> s1 >> s2) {
		len = s1.length();
		printf("[\n");
		DFS(0, 0);
		printf("]\n");
	}
	return 0;
}