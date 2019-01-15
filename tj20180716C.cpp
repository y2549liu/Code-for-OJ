#include <bits/stdc++.h>
using namespace std;

string s[4];
string Map[14] = { "0","A","2","3","4","5","6","7","8","9","10","J","Q","K" };

int DFS(int num[], int len) {
	if (len == 1)
		return (num[0] == 24);

	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			//choose two different number,then merge them
			int newNum[4],cnt=0,x=num[i],y=num[j];
			//move untouched elements to the new array
			for (int k = 0; k < len; ++k) {
				if (k != i && k != j)
					newNum[cnt++] = num[k];
			}
			newNum[cnt] = x + y;		if (DFS(newNum, len - 1)) return 1;
			newNum[cnt] = x * y;		if (DFS(newNum, len - 1)) return 1;
			//note that final answer 24 is positive, so it means that we could suppose all number in the arithmatic procedure is positive
			newNum[cnt] = abs(x - y);	if (DFS(newNum, len - 1)) return 1;
			//note that the divisor should not be zero
			if (y && x%y == 0) {
				newNum[cnt] = x / y;	if (DFS(newNum, len - 1)) return 1;}
			else if (x && y%x == 0) {
				newNum[cnt] = y / x;	if (DFS(newNum, len - 1)) return 1;}
		}
	}
	return 0;
}

int main() {
	int n[4];
	while (1) {
		for (int i = 0; i < 4; ++i) {
			if ( !(cin >> s[i]) )
				return 0;
			for (int j = 1; j < 14; ++j) {
				if (s[i] == Map[j]) {
					n[i] = j;
					break;
				}
			}
		}
		if (DFS(n, 4))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}