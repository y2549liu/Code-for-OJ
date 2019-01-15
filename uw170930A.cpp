#include <bits/stdc++.h>
using namespace std;
struct triangle {
	int a[3];
	bool check() {
		return (a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[0] + a[2] > a[1]);
	}
	triangle(int _a, int _b, int _c) {
		a[0] = _a; a[1] = _b; a[2] = _c;
		sort(a, a + 3);
	}
	bool operator<(const triangle &x) const{
		return (a[0] != x.a[0]) ? (a[0] < x.a[0]) : (a[1] != x.a[1]) ? (a[1] < x.a[1]) : (a[2] != x.a[2]) ? (a[2] < x.a[2]) : 0;
	}
	bool operator==(const triangle &x) const {
		return(memcmp(a, x.a, sizeof(a)));
	}
};
int main() {
	int l[5];
	set<triangle> st;
	for (int i = 0; i < 5; ++i)
		cin >> l[i];
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				triangle t = { l[i], l[j], l[k] };
				if (t.check()) {
					st.insert(t);
				}
			}
		}
	}
	cout << st.size();
	return 0;
}