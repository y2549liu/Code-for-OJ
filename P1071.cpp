#include <bits/stdc++.h>
using namespace std;
void fail(){
	cout << "Failed";
	exit(0);
}
int main() {
	string original, encoded, text, ans="";
	map<char, char> dict,redict;
	cin >> original >> encoded >> text;
	for (int i = 0; i < original.length(); ++i) {
		char ori = original[i], enc = encoded[i];
		if ((dict.count(ori) && dict[ori] != enc) || (redict.count(enc) && redict[enc] != ori)) 
			fail();
		dict[ori] = enc; redict[enc] = ori;
	}
	if (dict.size() != 26)
		fail();
	for (int i = 0; i < text.length(); ++i) {
		if (dict.count(text[i]))
			ans += dict[text[i]];
		else 
			fail();
	}
	cout << ans;
	return 0;
}