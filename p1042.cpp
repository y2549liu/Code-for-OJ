/* https://www.luogu.org/problemnew/show/P1042 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

struct gamestatus
{
	int a, b;
};

int main()
{
	gamestatus case11[8000];
	memset(case11, 0, sizeof(case11));
	gamestatus case21[8000];
	memset(case21, 0, sizeof(case21));
	int case11Round=0,case21Round=0;

	char ch;
	while (cin >> ch)
	{
		if (ch == 'E')
			break;
		else if (ch == 'W')
		{
			case11[case11Round].a++;
			case21[case21Round].a++;
		}
		else if (ch == 'L')
		{
			case11[case11Round].b++;
			case21[case21Round].b++;
		}

		if ( (case11[case11Round].a >= 11 || case11[case11Round].b >= 11) && abs(case11[case11Round].a - case11[case11Round].b) > 1)
		{
			case11Round++;
		}
		if ((case21[case21Round].a >= 21 || case21[case21Round].b >= 21) && abs(case21[case21Round].a - case21[case21Round].b) > 1)
		{
			case21Round++;
		}
	}

	for (int i = 0; i <= case11Round; i++)
		cout << case11[i].a << ":" << case11[i].b << endl;
	
	cout << endl;

	for (int i = 0; i < case21Round; i++)
		cout << case21[i].a << ":" << case21[i].b << endl;

	
	cout << case21[case21Round].a << ":" << case21[case21Round].b ;
	return 0;
}