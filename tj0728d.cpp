#include <bits/stdc++.h>
using namespace std;
string a, b;
string constructmax(multiset<char> &remain){
	string ans="";
	for (iter=remain.rbegin(); iter != remain.rend(); ++iter) {
		ans += *iter;
	}
	return ans;
}
string constructmin(multiset<char> &remain){
	string ans="";
	for (iter=remain.begin(); iter != remain.end(); ++iter) {
		ans += *iter;
	}
	return ans;
}
string solve(multiset<char> &remain, int index=0) {
	//a, b are of same length
	char ch;
	auto iter = remain.rbegin();
	for (; iter != remain.rend();++iter) {
		if (b[index] >= *iter) {
			ch = *iter;
			remain.erase((++iter).base());
			break;
		}
	}
	string test = "";
	test+=ch;
	if (ch < b[index]) 
		return test+constructmax(remain);
	test+=constructmin(remain);
	string bsub = b.substr(index, b.length() - index);
	int ans = strcmp(test.c_str(), bsub.c_str());
	if (ans == 0) 
		return test;
	else if (ans < 0) 
		return ch + solve(remain, index + 1);
	else {
		remain.insert(ch);
		for (iter = remain.rbegin(); iter != remain.rend(); ++iter) {
			if (*iter < ch)
			{
				ch = *iter;
				remain.erase((++iter).base());
				break;
			}
		}
		test = "";
		test += ch;
		return test+constructmax(remain);
	}
}
int main() {
	cin >> a >> b;
	if (a.length() < b.length()) {
		sort(a.begin(), a.end(), greater<char>());
		cout << a;
		return 0;
	}
	multiset<char> ms;
	for (auto i : a)
		ms.insert(i);
	cout << solve(ms);
	return 0;
}