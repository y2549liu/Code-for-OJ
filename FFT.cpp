#include <bits/stdc++.h>
using namespace std;
	
typedef complex<double> cd;
typedef vector<cd> vcd;
const double pi = 3.14159265358979323846264338327950288419716939;
const int BufferSize = 1 << 16;
char buffer[BufferSize], *head, *tail;
inline char Getchar() {
	if (head == tail) {
		int l = fread(buffer, 1, BufferSize, stdin);
		tail = (head = buffer) + l;
	}
	return *head++;
}
inline int read() {
	int x = 0, f = 1; char c = Getchar();
	for (; !isdigit(c); c = Getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = Getchar()) x = x * 10 + c - '0';
	return x*f;
}
inline void write(int x)
{
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}

/*
vcd is the coefficient 
type=1 DFT
type=-1 ANTI-DFT
*/
void fft(vcd &f, int type) {
	int n = f.size();
	if (n == 1)
		return;
	vcd a1(n>>1), a2(n>>1);
	for (int i = 0; i < n; i += 2) {
		a1[i >> 1] = f[i];
		a2[i >> 1] = f[i + 1];
	}
	fft(a1, type),	fft(a2, type);
	cd wn = polar(1.0, 2.0 * type * pi / n), w = { 1,0 };
	for (int i = 0; i < (n >> 1); ++i, w *= wn) {
		f[i] = a1[i] + w * a2[i];
		f[i+(n>>1)] = a1[i] - w * a2[i];
	}
}
vcd fastPolyMul(vcd &f1,vcd &f2) {
	int n = f1.size();
	fft(f1, 1), fft(f2, 1);
	vcd ans(n);
	for (int i = 0; i < n; ++i)
		ans[i] = f1[i] * f2[i];
	fft(ans, -1);
	for (int i = 0; i < n; ++i) 
		ans[i] /= n;
	return ans;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n=read(), m=read(), k;
	k = pow(2, int(ceil(log2(m + n + 1))));
	vcd f1(k), f2(k);
	for (int i = 0; i <= n; ++i)
		f1[i] = read();
	for (int i = 0; i <= m; ++i)
		f2[i] = read();
	vcd ans = fastPolyMul(f1, f2);
	for (int i = 0; i <= n + m; ++i) 
		write(int(ans[i].real() + 0.5)),putchar(' ');
	return 0;
}