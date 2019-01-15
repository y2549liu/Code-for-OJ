/* https://www.luogu.org/problemnew/show/P1781 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n, no;
	string num, result;
	result = "";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (num.size() > result.size() || (num.size() == result.size() && num > result/*×ÖµäÐò±È½Ï*/))
		{
			result = num;
			no = i;
		}
	}
	cout << no << endl << result;
	return 0;
}