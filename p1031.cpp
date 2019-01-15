/* https://www.luogu.org/problemnew/show/P1031 */

#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{
	int n;
	cin >> n;
	int *data = new int[n];
	int sum=0;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		sum += data[i];
	}
	int avg = sum / n;
	int ans = n - 1;
	sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum += data[i];
		if (sum == (i + 1)*avg)
			ans--;
	}
	cout << ans;
	delete[]data;
	return 0;
}