/*
http://acm.hdu.edu.cn/showproblem.php?pid=1142
最短路数量 dijkstra DFS 
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

struct Data {
	int dis, cases;
	Data(const int &_dis= INT32_MAX, const int &_cases=0) {dis = _dis; cases = _cases;	}
};
struct DIS {
	int no, dis;
	bool operator > (const DIS& d) const {
		return dis > d.dis;
	}
};
void dijkstra(vector<Edge> &edgeArray, vector<Node> &nodeArray, int *distance, int src)
{
	bool* visited = new bool[nodeArray.size()]();
	priority_queue <DIS, vector<DIS>, greater<DIS>> Q;
	distance[src] = 0;
	Q.push(DIS{ src, 0});
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
				Q.push(DIS{ to, distance[to]});
			}
		}
	}
	delete[] visited;
}

int DFS(vector<Edge> &edgeArray, vector<Node> &nodeArray, int *distance, int *cases, int src=1)
{
	if (cases[src])
		return cases[src];
	else
	{
		int from = src, to;
		for (auto iter = nodeArray[src].edgeList.begin(); iter != nodeArray[src].edgeList.end(); ++iter) {
			Edge &e = edgeArray[*iter];
			to = e.n1^e.n2^from;
			if (distance[to] < distance[from])
				cases[src] += DFS(edgeArray, nodeArray, distance, cases, to);
		}
	}
	return cases[src];
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n, m;
	while (cin >> n  && n)
	{
		cin >> m;
		vector<Edge> edgeArray(m + 1);
		vector<Node> nodeArray(n + 1);
		int *distance = new int[n + 1]();
		memset(distance, 0x7f, (n + 1) * sizeof(int));
		int *cases = new int[n + 1](); cases[2] = 1;
		Edge tmp;
		for (int i = 1; i <= m; i++)
		{
			cin >> tmp;
			nodeArray[tmp.n1].edgeList.push_back(i);
			nodeArray[tmp.n2].edgeList.push_back(i);
			edgeArray[i] = tmp;
		}
		dijkstra(edgeArray, nodeArray, distance, 2);//算出所有点到2的最短路
		cout << DFS(edgeArray, nodeArray, distance, cases, 1) << endl;
		delete[]distance; delete[]cases;
	}
	return 0;
}

istream& operator>>(istream &in, Edge &e)
{
	return in >> e.n1 >> e.n2 >> e.dis;
}
