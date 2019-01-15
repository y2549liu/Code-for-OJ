#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int main() {
	string s;
	while (cin >> s && s[0]!='-') {
		int cnto=0, cnte = 0;
		stack<char > st;
		for (int i = 0; i < s.length();++i) {
			if (s[i] == '{') {
				st.push(s[i]);
				++cnto;
				continue;
			}
			if (st.size() && st.top()=='{') 
				--cnto,st.pop();
			else 
				++cnte,st.push(s[i]);
		}
		cout << (cnte)/2 +(cnto)/2 + (cnte&1) + (cnto& 1) << endl;
	}
	return 0;
}