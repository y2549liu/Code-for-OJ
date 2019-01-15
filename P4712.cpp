#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n, last= 0,r;
	double s;
	cin >> n >> s;
	int *data = new int[n+1]();
	for (int i = 1; i <= n; ++i)
	{
		cin >> data[i] >> r;
		if (r > last) {
			//食物种类扩充
			for (int j = last + 1; j <= r; ++j)
				s += data[j];
			last = r;
		}
		//吃
		s -= 5 * data[i];
		if (s < 0)
		{
			printf("-1");
			delete[] data;
			return 0;
		}
	}
	for (int i = last + 1; i <= n; ++i)
		s += data[i];
	printf("%lf", s / 5);
	delete[] data;
	return 0;
}