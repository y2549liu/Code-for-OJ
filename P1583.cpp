/* https://www.luogu.org/problemnew/show/P1583 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct fans
{
	int no, score;
	bool operator>(const fans &f) const
	{
		if (score > f.score)
			return 1;
		else if ((score == f.score) && (no < f.no))
			return 1;
		else return 0;
	}
};


bool cmp(fans a, fans b)
{
	return a > b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int E[10];
	for (int i = 0; i < 10; i++)
		cin >> E[i];

	fans *data = new fans[n+1];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].score;
		data[i].no = i + 1;
	}
	sort(data, data + n, cmp);
	for (int i = 0; i < n; i++)
	{
		data[i].score += E[i % 10];
	}
	sort(data, data + n, cmp);
	for (int i = 0; i < k; i++)
	{
		cout << data[i].no<<' ';
	}
	delete[] data;
	return 0;
}