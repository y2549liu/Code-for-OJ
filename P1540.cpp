/*https://www.luogu.org/problemnew/show/P1540 */


#include <iostream>
#include <list>

using namespace std;
int main()
{
	int m, n, word;
	cin >> m >> n;
	list<int> mem;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		int space = mem.size();
		if (space == 0) {
			result++;
			mem.push_back(word);
			continue;
		}
		list<int>::const_iterator iter = mem.begin();
		bool found = false;
		while (iter != mem.end())
		{
			if (*iter == word)
			{
				found = 1;
				break;
			}
			iter++;
		}
		if (!found)
		{
			result++;
			if (space == m)
				mem.pop_front();
			mem.push_back(word);
		}
	}
	cout << result;
	system("pause");
}