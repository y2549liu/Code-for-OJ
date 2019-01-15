/* 并查集 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1001;
int father[maxn];
int _rank[maxn];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		father[i] = i;
		_rank[i] = 0;
	}
}

int findFather(int x)
{
	return (father[x] == x) ? x : father[x]=findFather(father[x]);
}

void merge(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if (fx == fy)//已经在同一集合中
		return;
	if (_rank[fx] > _rank[fy])//x集合的深度大，则把y的父亲的父亲设为fx
	{
		father[fy] = fx;
	}
	else if (_rank[fx] < _rank[fy])
	{
		father[fx] = fy;
	}
	else
	{
		father[fy] = fx;
		++_rank[fx];
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		//memset(father, 0, sizeof(father));
		//memset(_rank, 0, sizeof(_rank));
		int m, n,x,y;
		cin >> n >> m;
		init(n+1);
		for (int j = 0; j < m; j++)
		{
			cin >> x >> y;
			merge(x, y);
		}
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			if (father[j] == j)
				ans++;
		}
		cout << ans<<endl;
	}
	return 0;
}