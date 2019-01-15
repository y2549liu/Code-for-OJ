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

void dijkstra(vector<Edge> &edgeArray, vector<Node> &nodeArray, int *distance, int src)
{
	struct DIS {
		int no, dis;
		bool operator > (const DIS& d) const {
			return dis > d.dis;
		}
	};
	bool* visited = new bool[nodeArray.size()]();
	priority_queue <DIS, vector<DIS>, greater<DIS>> Q;
	distance[src] = 0;
	Q.push(DIS{ src,0 });
	int from, to; Edge e;
	while (!Q.empty()) {
		DIS cur = Q.top(); Q.pop();
		from = cur.no;
		if (visited[cur.no])
			continue;
		else
			visited[cur.no] = true;
		vector<int>::const_iterator iter = nodeArray[cur.no].edgeList.begin();
		
		for (; iter != nodeArray[cur.no].edgeList.end(); ++iter)
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
	
	int n, m;
	while (cin >> n >> m  && n && m)
	{
		vector<Edge> edgeArray(m + 1);
		vector<Node> nodeArray(n + 1);
		int *distance = new int[n + 1]; 
		memset(distance, 0x7F, (n + 1) * sizeof(int));
		Edge tmp;
		for (int i = 1; i <= m; i++)
		{
			cin >> tmp;
			nodeArray[tmp.n1].edgeList.push_back(i);
			nodeArray[tmp.n2].edgeList.push_back(i);
			edgeArray[i] = tmp;
		}
		int src, des;
		cin >> src >> des;
		dijkstra(edgeArray, nodeArray, distance, src);
		if (distance[des] != 0x7f7f7f7f)
			cout << distance[des] << endl;
		else
			cout << "-1\n";
		delete[]distance;
	}
	return 0;
}

istream& operator>>(istream &in, Edge &e)
{
	return in >> e.n1 >> e.n2 >> e.dis;
}
