/* spfa dfs */
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

//有向边
struct Edge {
	int from, to;
	double rate;
};

struct Node {
	/* 边集合 */
	vector<int> edgeList;
};

bool *checked, *visited;

bool DFS(vector<Edge> &edgeArray, vector<Node> &nodeArray, double *exchangeRate, int src)
{
	if (visited[src])
		return 1;
	checked[src] = 1;
	visited[src] = 1;
	for (auto iter = nodeArray[src].edgeList.begin(); iter != nodeArray[src].edgeList.end(); ++iter)
	{
		const Edge& e = edgeArray[*iter];
		if ( exchangeRate[e.to] < exchangeRate[e.from] + e.rate )
		{
			exchangeRate[e.to] = exchangeRate[e.from] + e.rate;
			if (DFS(edgeArray, nodeArray, exchangeRate, e.to))
				return 1;
		}
	}
	visited[src] = 0;
	return 0;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n, m, cnt = 1;
	double rate;
	string src, des;

	while (cin >> n && n )
	{
		map <string, int> currencyMap;
		for (int i = 1; i <= n; i++)
		{
			cin >> src;
			currencyMap[src] = i;
		}
		cin >> m;
		vector<Edge> edgeArray(m + 1);
		vector<Node> nodeArray(n + 1);

		/* 申请空间记得释放 */
		double* exchangeRate = new double[n + 1];*exchangeRate = -100;
		checked = new bool[n + 1]();
		visited = new bool[nodeArray.size()]();

		for (int i = 1; i <= m; ++i)
		{
			cin >> src >> rate >> des;
			if (rate>0) 
				rate = log(rate);
			else rate = -1.0e100;
			nodeArray[currencyMap[src]].edgeList.push_back(i);
			edgeArray[i] = Edge{ currencyMap[src],currencyMap[des],rate};
		}
		bool flag = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (checked[i])
				continue;
			for (int j = 1; j <= n; ++j)
			{
				visited[j] = 0;
				memcpy( exchangeRate+j ,exchangeRate, sizeof (double));
			}
			exchangeRate[i] = 0.0;
			if (DFS(edgeArray, nodeArray, exchangeRate, i))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "Case " << cnt << ": Yes\n";
		else
			cout << "Case " << cnt << ": No\n";
		++cnt;
		delete[]exchangeRate; delete[]checked, delete[] visited;
	}
	return 0;
}