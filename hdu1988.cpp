#include <iostream>
using namespace std;
const int maxn = 30001;
int pa[maxn],dist[maxn],sz[maxn];
void init() {
	for (int i = 0; i < maxn; ++i)
		pa[i] = i, sz[i] = 1;
}

int findPa(int x) {
	if (x == pa[x]) 
		return x;
	int t = pa[x];
	pa[x] = findPa(pa[x]);
	dist[x] += dist[t];
	return pa[x];
}
void merge(int a, int b) {
	int paa = findPa(a), pab = findPa(b);
	if (paa == pab)
		return;
	pa[pab] = paa;
	dist[pab] = sz[paa];
	sz[paa] += sz[pab];
}
void count(int a) {
	int paa = findPa(a);
	cout << sz[paa] - dist[a]-1 << endl;
}

int main() {
	int p,a,b;
	char act;
	cin >> p;
	init();
	for (int i = 0; i < p; i++) {
		cin >> act;
		if (act == 'M') {
			cin >> a >> b;
			merge(a, b);
		}
		else {
			cin >> a;
			count(a);
		}
	}
	return 0;
}
