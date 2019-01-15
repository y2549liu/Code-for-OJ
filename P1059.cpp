/* https://www.luogu.org/problemnew/show/P1059 */

#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{
	int n,tmp,total=0;
	cin >> n;
	bool map[1001] = { 0 };

	while (n)
	{
		cin >> tmp;
		if (map[tmp] == 0)
		{
			map[tmp] = 1;
			total++;
		}
		--n;
	}
	cout << total << endl;
	for (int i = 1; i <= 1000; i++)
	{
		if (map[i])
			cout << i << " ";
	}
	return 0;
}