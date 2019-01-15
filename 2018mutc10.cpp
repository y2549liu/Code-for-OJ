#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
inline LL modadd(LL a, LL b) { return ((a % mod) + (b % mod)) % mod; }
inline LL modsub(LL a, LL b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline LL modmul(LL a, LL b) { return ((a % mod) * (b % mod)) % mod; }
const int MAXN = 4;

template<typename T>
struct matrix
{
	T base[MAXN][MAXN];
	size_t row, line;
	matrix(size_t row, size_t line) {
		this->row = row;
		this->line = line;
	}
	matrix(initializer_list<initializer_list<LL> > l) {
		row = l.size();
		line = l.begin()->size();
		size_t j = 0;
		auto iter1 = l.begin();
		while (iter1 != l.end())
		{
			size_t k = 0;
			auto iter2 = iter1->begin();
			while (iter2 != iter1->end())
			{
				base[j][k] = *iter2;
				iter2++, k++;
			}
			iter1++, j++;
		}
	}
	matrix(const matrix & others) {
		row = others.row;
		line = others.line;
		for (size_t j = 0; j != row; j++)
			for (size_t k = 0; k != line; k++)
				base[j][k] = others[j][k];
	}
	friend matrix operator * (const matrix & lsh, const matrix & rsh) {
		matrix res(lsh.row, rsh.line);
		memset(res.base, 0, sizeof(res.base));
		for (size_t q = 0; q != lsh.line; q++)
			for (size_t j = 0; j != lsh.row; j++)
				if (lsh[j][q])
					for (size_t k = 0; k != rsh.line; k++)
						if (rsh[q][k])
							res[j][k] = modadd(res[j][k], modmul(lsh[j][q], rsh[q][k]));
		return res;
	}
	friend matrix power(matrix a, LL n) {
		matrix res(a.row, a.line);
		memset(res.base, 0, sizeof res.base);
		for (size_t j = 0; j != a.row; j++)
			res[j][j] = 1;
		while (n) {
			if (n & 1)
				res = res * a;
			a = a * a;
			n >>= 1;
		}
		return res;
	}
	friend ostream & operator << (ostream & out, const matrix & rsh) {
		for (size_t j = 0; j != rsh.line * 2 + 1; j++)
			out << "-";
		out << endl;
		for (size_t j = 0; j != rsh.row; j++)
		{
			for (size_t k = 0; k != rsh.line; k++)
				out << "|" << rsh[j][k];
			out << "|" << endl;
		}
		for (size_t j = 0; j != rsh.line * 2 + 1; j++)
			out << "-";
		out << endl;
		return out;
	}
	T * operator[](size_t pos) {
		return base[pos];
	}
	const T * operator[](size_t pos)const {
		return base[pos];
	}
};
int main() {
	int t, a, b, c, d, p, n;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d >> p >> n;
		if (n == 1)
		{
			cout << a << endl;
			continue;
		}
		else if (n == 2)
		{
			cout << b << endl;
			continue;
		}
		if (n <= 100000) {
			LL f1 = a, f2 = b, f3;
			for (int i = 3; i <= n; ++i) {
				f3 = ((f1*c)%mod + (f2*d)%mod + (p/i))%mod;
				//cout << f3 << " ";
				swap(f1, f2); swap(f2, f3);
			}
			cout <<f2<< endl;
		}
		else {
			LL f1 = a, f2 = b, f3;
			matrix<LL> mul = { {d,c,1},{1,0,0},{0,0,1} };
			int i;
			for (i = 3; double(i)<sqrt(p) ; ++i) {
				f3 = ((f1*c) % mod + (f2*d) % mod + (p / i)) % mod;
				swap(f1, f2); swap(f2, f3);
			}
			//                   i-1    i
			matrix<LL> base = { { f2 },{ f1 },{ p/i } };
			for (int j = p/i; j>= p/n; --j) {
				base.base[2][0] = j;
				int start = (p) / (j + 1), end;
				if (j == p / i)
					start = max(start, i-1);
				if (j == 0)
					end = n;
				else
					end = min(p / j,n);
				if (end-start)
					base = power(mul, LL(end - start))*base;
			}
			cout << base.base[0][0] << endl;
		}
	}
	return 0;
}