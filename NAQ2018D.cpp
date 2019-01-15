#include <bits/stdc++.h>
using namespace std;
int l, w, p; string act;

struct lane {
	int offset, interval, speed;
}arr[11];
bool iscar(int t, int x, int Lane) {
	if (Lane == l)
		return 0;
	lane &L = arr[Lane];
	if (L.speed > 0) {
		int carbef = (t*L.speed + L.offset) % L.interval;
		carbef += floor(double(x - carbef -1) / L.interval)*L.interval;
		return (carbef + L.speed >= x);
	}
	else if (L.speed == 0) {
		return ((x - L.offset) % L.interval == 0);
	}
	else {
		int carbef = (t*L.speed + L.offset) % L.interval;
		carbef += floor(double(x - carbef ) / L.interval)*L.interval + L.interval;
		return (carbef + L.speed <= x);
	}
}
int checkmargin(int x,int y) {
	static bool allowdownexceed = 1;
	if (x<0 || x>=w || (!allowdownexceed && y == l) || y>l ) return -1;
	if (y < l) allowdownexceed = 0;
	return (y <= 0);
}
void squish() {
	puts("squish\n");
	exit(0);
}
void safe() {
	puts("safe\n");
	exit(0);
}
int main() {
	cin >> l >> w;
	for (int i = 0; i < l; ++i) {
		cin >> arr[i].offset >> arr[i].interval >> arr[i].speed;
		if (arr[i].speed >= arr[i].interval) squish();
		if ((i & 1)) arr[i].speed *= -1;
	}
	cin >> p >> act;
	int fx = p, fy = l;
	for (int i = 0; i < act.length(); ++i) {
		char d = act[i];
		if (d == 'U')
			--fy;
		else if (d == 'D')
			++fy;
		else if (d == 'L')
			--fx;
		else if (d == 'R')
			++fx;
		int flag = checkmargin(fx,fy);
		if (flag == 1) safe();
		if (iscar(i, fx, fy)||flag==-1) squish();
	}
	squish();
	return 0;
}