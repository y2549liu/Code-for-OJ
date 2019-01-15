#include <bits/stdc++.h>
using namespace std;
struct bigNum {
	const int WIDTH = 8, BASE = pow(10, WIDTH); 
	vector <long long> s;
	bigNum(const bigNum &x) {s = x.s;}
	bigNum(long long num = 0) {
		s.clear();
		do {
			s.push_back(num%BASE);
			num /= BASE;
		} while (num>0);
	}
	bigNum(const string& str) {
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for (int i = 0; i<len; i++) {
			int end = str.length() - i*WIDTH;
			int start = max(0, end - WIDTH);
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
	}
	bigNum operator = (const bigNum &x) { s = x.s; return *this; }
	bigNum operator + (const bigNum& b) const {
		bigNum c;
		c.s.clear();
		for (int i = 0, g = 0;; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if (i<s.size()) x += s[i];
			if (i<b.s.size()) x += b.s[i];
			c.s.push_back(x%BASE);
			g = x / BASE;
		}
		return c;
	}
	bigNum operator - (const bigNum& b) const {
		bigNum c;
		c.s.clear();
		int i, g, n = s.size(), m = b.s.size();
		for (i = 0, g = 0; i<n; i++) {
			int x = s[i] - g;
			if (i<m) x -= b.s[i];
			if (x >= 0) g = 0;
			else {
				g = 1;
				x += BASE;
			}
			c.s.push_back(x);
		}
		i = c.s.size() - 1;
		while (c.s[i] == 0 && i) c.s.pop_back(), i--;
		return c;
	}
	bigNum operator * (const bigNum &b) const {
		bigNum c;
		int i, j, n = s.size(), m = b.s.size(), size = m + n;
		c.s.resize(size, 0);
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (i = 0; i<size-1; i++) {
			c.s[i + 1] += c.s[i] / BASE;
			c.s[i] %= BASE;
		}
		while (c.s[i] == 0 && i) c.s.pop_back(), i--;
		return c;
	}
	bigNum operator / (const bigNum& b) const {
		bigNum c, f = 0;
		int n = s.size(), i;
		c.s.resize(n, 0);
		for (i = n - 1; i >= 0; i--) {
			f = f*BASE;
			f.s[0] = s[i];
			while (f >= b) {
				f -= b;
				c.s[i]++;
			}
		}
		i = n - 1;
		while (c.s[i] == 0 && i) c.s.pop_back(), i--;
		return c;
	}
	bigNum operator % (const bigNum &b) const {
		bigNum r = *this / b;
		r = *this - r*b;
		return r;
	}

	bigNum operator += (const bigNum& b) { *this = *this + b; return *this; }
	bigNum operator -= (const bigNum& b) { *this = *this - b; return *this; }
	bigNum operator *= (const bigNum& b) { *this = *this*b; return *this; }
	bigNum operator /= (const bigNum& b) { *this = *this / b; return *this; }
	bigNum operator %= (const bigNum& b) { *this = *this%b; return *this; }

	bool operator < (const bigNum& b) const {
		int n = s.size(), m = b.s.size();
		if (m>n) return 1;
		if (m<n) return 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i]<b.s[i]) return 1;
			if (s[i]>b.s[i]) return 0;
		}
		return 0;
	}
	bool operator > (const bigNum& b) const { return b<*this; }
	bool operator >= (const bigNum& b) const { return !(*this<b); }
	bool operator <= (const bigNum& b) const { return !(b<*this); }
	bool operator == (const bigNum& b) const { return !(*this<b) && !(b<*this); }
	bool operator != (const bigNum& b) const { return (*this<b) || (b<*this); }
};

ostream& operator << (ostream &out, const bigNum& x) {
	out << x.s.back();
	for (int i = x.s.size() - 2; i >= 0; i--) {
		char buf[10];
		sprintf(buf, "%08d", x.s[i]); // change
		for (int j = 0; j<strlen(buf); j++) out << buf[j];
	}
	return out;
}
istream& operator >> (istream &in, bigNum& x) {
	string s;
	if (!(in >> s)) return in;
	x = s;
	return in;
}


int main()
{
	bigNum a = "1000000000000000000000000000000000", b = "2";
	cout << a/b;
	return 0;
}