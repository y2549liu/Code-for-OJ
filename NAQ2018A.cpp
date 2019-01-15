#include <bits/stdc++.h>
using namespace std;


int checkline(int *arr1, int * arr2) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (arr1[i] == arr2[j])
				return arr1[i];
		}
	}
	return 0;
}
bool check(set<int> &seq, int **arr) {
	for (int i = 0; i < 5; ++i) {
		int cnt = 0;
		for (int j = 0; j < 5; ++j) {
			if(seq.count(arr[i][j]))
				++cnt;
		}
		if (cnt == 5)
			return 1;
	}
	return 0;
}

int main(){
	int n;
	int a[101][6][6];
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> a[i][j][k];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int l1 = 0; l1 < 5; ++l1) {
				for (int l2 = 0; l2 < 5; ++l2) {
					if (int same=checkline(a[i][l1], a[j][l2])) {
						bool flag = 1;
						set<int> seq;
						for (int u = 0; u < 5; ++u) {
							seq.insert(a[i][l1][u]);
							seq.insert(a[j][l2][u]);
						}
						seq.erase(same);
						for (int k = j + 1; k < n; ++k) {
							if (check(seq, (int**)a[k])) {
								flag = 0;
								break;
							}
						}
						if (flag) {
							cout << i + 1 << " " << j + 1;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "no ties\n";
	return 0;
}

