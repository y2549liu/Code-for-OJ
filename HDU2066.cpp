/*
http://acm.hdu.edu.cn/showproblem.php?pid=2544
最短路
*/
#include <bits/stdc++.h>

using namespace std;

//无向图
struct Edge {
	int n1, n2, dis;
	friend istream& operator>>(istream& in, Edge &e);
};
struct Node {
	/* 边集合 */
	vector<int> edgeList;
};

struct DIS {
	int no, dis;
	bool operator > (const DIS& d) const {
		return dis > d.dis;
	}
};

void dijkstra(vector<Edge> &edgeArray, vector<Node> &nodeArray, int *distance, const vector<int> &neighbour)
{
	bool* visited = new bool[nodeArray.size()]();
	priority_queue <DIS, vector<DIS>, greater<DIS>> Q;
	for (auto iter = neighbour.begin(); iter != neighbour.end(); ++iter)
	{
		distance[*iter] = 0;
		Q.push(DIS{ *iter,0 });
	}
	int from, to; Edge e;
	while (!Q.empty()) {
		DIS cur = Q.top(); Q.pop();
		from = cur.no;
		if (visited[cur.no])
			continue;
		else
			visited[cur.no] = true;

		for (auto iter = nodeArray[cur.no].edgeList.begin(); iter != nodeArray[cur.no].edgeList.end(); ++iter)
		{
			e = edgeArray[*iter];
			to = e.n1^e.n2^from;
			if (distance[to] > distance[from] + e.dis)
			{
				distance[to] = distance[from] + e.dis;
				Q.push(DIS{ to,distance[to] });
			}
		}
	}
	delete[] visited;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int t, s, d, n = 1005;
	while (cin >> t >> s >> d)
	{
		vector<Edge> edgeArray(t + 1);
		vector<Node> nodeArray(n + 1);
		int *distance = new int[n + 1];
		vector<int> neighbour(s);
		memset(distance, 0x7F, (n + 1) * sizeof(int));
		Edge tmp;
		for (int i = 1; i <= t; ++i)
		{
			cin >> tmp;
			nodeArray[tmp.n1].edgeList.push_back(i);
			nodeArray[tmp.n2].edgeList.push_back(i);
			edgeArray[i] = tmp;
		}
		for (int i = 0; i < s; ++i)
		{
			cin >> neighbour[i];
		}
		dijkstra(edgeArray, nodeArray, distance, neighbour);
		int result = INT32_MAX, des;
		for (int i = 0; i < d; ++i)
		{
			cin >> des;
			result = min(distance[des], result);
		}
		cout << result<<endl;
		delete[]distance;
	}
	return 0;
}

istream& operator>>(istream &in, Edge &e)
{
	return in >> e.n1 >> e.n2 >> e.dis;
}
