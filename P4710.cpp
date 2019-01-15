#include <bits/stdc++.h>
using namespace std;


int main() {
	double v, theta;
	cin >> v >> theta;
	double vHorizontal=v*sin(theta) , vVertical=v*cos(theta);
	double t = vVertical / 10;
	cout << vVertical*t << " " << 5 * t*t;
	return 0;
}