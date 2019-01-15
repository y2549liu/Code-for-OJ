#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
struct point {
	int no;
	double theta;
	bool operator < (const point& x) const {
		return theta < x.theta;
	}
};

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		double x, y;
		double theta;
		priority_queue<point> Q;
		for (int i = 1; i <= 3*n; ++i) {
			cin >> x >> y;
			x -= 1.23456789;
			y -= 9.87654321;
			theta = acos(x / sqrt(x*x+y*y));
			if (y < 0) 
				theta = 2 * pi - theta;
			Q.push({ i, theta });
		}
		while (Q.size()) {
			cout << Q.top().no<<" ";
			Q.pop();
			cout << Q.top().no << " ";
			Q.pop();
			cout << Q.top().no << "\n";
			Q.pop();
		}
	}
	return 0;
}