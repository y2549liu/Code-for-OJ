#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include <bits/stdc++.h>
using namespace std;
int t, n, k;
struct mon {
	int v[5], b[5], sum;
	bool operator<(const mon& x)const {
		return (sum == x.sum)?(rand()&1):(sum<x.sum);
	}
};
struct man {
	int v[5],sum;
	bool operator>=(const mon &x) const {
		for (int j = 0; j < k; ++j)
			if (v[j] < x.v[j])
				return 0;
		return 1;
	}
}M;

const int BUF = 40000000;
char Buf[BUF], *buf = Buf;
const int OUT = 20000000;
char Out[OUT], *ou = Out; int Outn[30], Outcnt;
inline void write(int x) {
	if (!x)*ou++ = 48;
	else {
		for (Outcnt = 0; x; x /= 10)Outn[++Outcnt] = x % 10 + 48;
		while (Outcnt)*ou++ = Outn[Outcnt--];
	}
}
inline void writell(long long x) {
	if (!x)*ou++ = 48;
	else {
		for (Outcnt = 0; x; x /= 10)Outn[++Outcnt] = x % 10 + 48;
		while (Outcnt)*ou++ = Outn[Outcnt--];
	}
}
inline void writechar(char x) { *ou++ = x; }
inline void writeln() { *ou++ = '\n'; }
inline void read(int&a) { for (a = 0; *buf<48; buf++); while (*buf>47)a = a * 10 + *buf++ - 48; }


int main(){
	fread(Buf, 1, BUF, stdin);
	read(t);
	while (t--) {
		read(n), read(k);
		multiset<mon> ms;
		M.sum = 0;
		for (int j = 0; j < k; ++j)
			read(M.v[j]), M.sum += M.v[j];
		mon Mon;
		for (int i = 0; i < n; ++i) {
			Mon.sum = 0;
			for (int j = 0; j < k; ++j)
				read(Mon.v[j]), Mon.sum += Mon.v[j];
			for (int j = 0; j < k; ++j)
				read(Mon.b[j]);
			ms.insert(Mon);
		}
		int cnt = 0;
		for (auto iter = ms.begin(); iter != ms.end();) {
			if (M.sum < iter->sum)
				break;
			if (M >= *iter) {
				for (int j = 0; j < k; ++j)
					M.v[j] += iter->b[j], M.sum += iter->b[j];
				ms.erase(iter);
				++cnt;
				iter = ms.begin();
			}
			else
				++iter;
		}
		cout << cnt << endl;
		for (int j = 0; j < k; ++j)
			cout << M.v[j] << " " ;
		cout << endl;
	}
	return 0;
}