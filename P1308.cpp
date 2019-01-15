#include <bits/stdc++.h>
using namespace std;
int main() {
	char word[12], passage[1000001];
	cin.getline(word, 12);
	cin.getline(passage, 1000001);
	size_t wLen = strlen(word), pLen = strlen(passage);
	for (int i = 0; i < wLen; ++i) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			word[i] -= 'A' - 'a';
		}
	}
	int firstPos = 0,cnt=0;
	char *start = passage, *end;
	for (int i = 0; i < pLen; ++i) {
		if (passage[i] >= 'A' && passage[i] <= 'Z') {
			passage[i] -= 'A' - 'a';
		}
		else if (passage[i] == ' ') {
			end = passage + i;
			if (end - start == wLen && strncmp(word, start, wLen) == 0) {
				if (!cnt) {
					firstPos = start - passage;
				}
				++cnt;
			}
			start = end + 1;
		}
	}
	if (strncmp(word, start, wLen) == 0) {
		if (!firstPos) {
			firstPos = start - passage;
		}
		++cnt;
	}
	if (cnt) {
		cout << cnt << " " << firstPos;
	}
	else
		cout << "-1";
	return 0;
}