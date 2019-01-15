#include <bits/stdc++.h>
using namespace std;

int n;

void trans(int x) {
	if (x == 2) {
		printf("2");
		return;
	}
	for (int i = log2(x); i >= 0; --i) {
		if (x >= (1 << i)) {
			x -= (1 << i);
			if (i >= 2){
				printf("2(");
				trans(i);
				printf(")");
			}
			else if (i == 1) {
				printf("2");
			}
			else if (i == 0) {
				printf("2(0)");
			}
			if (x)
				printf("+");
		}
	}
}

int main() {
	cin >> n;
	trans(n);
	return 0;
}