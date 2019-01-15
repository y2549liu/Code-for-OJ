#include <bits\stdc++.h>

using namespace std;


struct coord {
	double x, y, z;
	void get() {
		cin >> x >> y >> z;
	}
};

template<class T>
T square(const T &a)
{
	return move(a*a);
}

const double r = square(40000 / (2 * 3.141592653589793));

int main()
{
	int k, n;
	double a,b, c, side, hypotenuse, d,l;
	while (cin >> k >> n && k && n)
	{
		int cnt = 0;
		coord *satellite = new coord[k](), *hurricane = new coord[n]();
		for (int i = 0; i < k; i++)
			satellite[i].get();
		for (int i = 0; i < n; i++)
		{
			hurricane[i].get();
			for (int j = 0; j < k; j++)
			{
				a = hurricane[i].x - satellite[j].x;
				b = hurricane[i].y - satellite[j].y;
				c = hurricane[i].z - satellite[j].z;
				/*
				l = (a*a + b*b + c*c);

				hypotenuse = square(satellite[j].x) + square(satellite[j].y) + square(satellite[j].z);
				side = square(a *  hurricane[i].x + b *  hurricane[i].y + c *  hurricane[i].z ) / l;
				d = hypotenuse - side;
				if (d >= r)
				{
					++cnt;
					break;
				}
				
				else*/ if ( a*hurricane[i].x + b*hurricane[i].y + c*hurricane[i].z <=0 )
				{
					++cnt;
					break;
				}
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}