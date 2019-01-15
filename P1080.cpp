#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
struct BigInteger {
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;
	BigInteger& clean() { while (!s.back() && s.size()>1)s.pop_back(); return *this; }
	BigInteger(LL num = 0) { *this = num; }
	BigInteger(string s) { *this = s; }
	BigInteger& operator = (long long num) {
		s.clear();
		do {
			s.push_back(num % BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}
	BigInteger& operator = (const string& str) {
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for (int i = 0; i < len; i++) {
			int end = str.length() - i*WIDTH;
			int start = max(0, end - WIDTH);
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return (*this).clean();
	}

	BigInteger operator + (const BigInteger& b) const {
		BigInteger c; c.s.clear();
		for (int i = 0, g = 0; ; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if (i < s.size()) x += s[i];
			if (i < b.s.size()) x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c;
	}
	BigInteger operator - (const BigInteger& b) const {
		assert(b <= *this); // �������ܴ��ڱ�����
		BigInteger c; c.s.clear();
		for (int i = 0, g = 0; ; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = s[i] + g;
			if (i < b.s.size()) x -= b.s[i];
			if (x < 0) { g = -1; x += BASE; }
			else g = 0;
			c.s.push_back(x);
		}
		return c.clean();
	}
	BigInteger operator * (const BigInteger& b) const {
		int i, j; LL g;
		vector<LL> v(s.size() + b.s.size(), 0);
		BigInteger c; c.s.clear();
		for (i = 0; i<s.size(); i++) for (j = 0; j<b.s.size(); j++) v[i + j] += LL(s[i])*b.s[j];
		for (i = 0, g = 0; ; i++) {
			if (g == 0 && i >= v.size()) break;
			LL x = v[i] + g;
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c.clean();
	}
	BigInteger operator / (const BigInteger& b) const {
		assert(b > 0);  // �����������0
		BigInteger c = *this;       // ��:��Ҫ����c.s��(*this).s��vectorһ����
		BigInteger m;               // ����:��ʼ��Ϊ0
		for (int i = s.size() - 1; i >= 0; i--) {
			m = m*BASE + s[i];
			c.s[i] = bsearch(b, m);
			m -= b*c.s[i];
		}
		return c.clean();
	}
	BigInteger operator % (const BigInteger& b) const { //�����������ͬ
		BigInteger c = *this;
		BigInteger m;
		for (int i = s.size() - 1; i >= 0; i--) {
			m = m*BASE + s[i];
			c.s[i] = bsearch(b, m);
			m -= b*c.s[i];
		}
		return m;
	}
	// ���ַ��ҳ�����bx<=m������x
	int bsearch(const BigInteger& b, const BigInteger& m) const {
		int L = 0, R = BASE - 1, x;
		while (1) {
			x = (L + R) >> 1;
			if (b*x <= m) { if (b*(x + 1)>m) return x; else L = x; }
			else R = x;
		}
	}
	BigInteger& operator += (const BigInteger& b) { *this = *this + b; return *this; }
	BigInteger& operator -= (const BigInteger& b) { *this = *this - b; return *this; }
	BigInteger& operator *= (const BigInteger& b) { *this = *this * b; return *this; }
	BigInteger& operator /= (const BigInteger& b) { *this = *this / b; return *this; }
	BigInteger& operator %= (const BigInteger& b) { *this = *this % b; return *this; }

	bool operator < (const BigInteger& b) const {
		if (s.size() != b.s.size()) return s.size() < b.s.size();
		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator >(const BigInteger& b) const { return b < *this; }
	bool operator<=(const BigInteger& b) const { return !(b < *this); }
	bool operator>=(const BigInteger& b) const { return !(*this < b); }
	bool operator!=(const BigInteger& b) const { return b < *this || *this < b; }
	bool operator==(const BigInteger& b) const { return !(b < *this) && !(b > *this); }
};

ostream& operator << (ostream& out, const BigInteger& x) {
	out << x.s.back();
	for (int i = x.s.size() - 2; i >= 0; i--) {
		char buf[20];
		sprintf(buf, "%08d", x.s[i]);
		for (int j = 0; j < strlen(buf); j++) out << buf[j];
	}
	return out;
}

istream& operator >> (istream& in, BigInteger& x) {
	string s;
	if (!(in >> s)) return in;
	x = s;
	return in;
}
struct people {
	LL l, r, mul;
	people() {
		l = r = mul = 0;
	}
	people(LL _l, LL _r) {
		l = _l; r = _r; mul = l*r;
	}
	bool operator<(const people& x)const {
		return mul < x.mul;
	}
}arr[1001];
LL n, l, r;

int main() {
	cin >> n >> l >> r;
	arr[0] = { l,r };
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		arr[i] = { l,r };
	}
	sort(arr + 1, arr + n + 1);
	BigInteger ans = 0, left=arr[0].l;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, left / arr[i].r);
		left *= arr[i].l;
	}
	cout << ans;
	return 0;
}