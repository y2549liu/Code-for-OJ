/* https://www.luogu.org/problemnew/show/P1003 */
#include <iostream>
#include <cmath>

using namespace std;

struct carpet {
	int x, y, w, d;
};



int main()
{
	int n;
	cin>>n;
	carpet* data;
	data = new carpet[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].x >> data[i].y >> data[i].w >> data[i].d;
	}

	int x, y;
	cin >> x >> y;
	int result = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (x >= data[i].x && y >= data[i].y && x <= data[i].w + data[i].x && y <= data[i].d + data[i].y)
		{
			result = i + 1;
			break;
		}
	}
	cout << result << endl;
	delete[]data;
	return 0;
}