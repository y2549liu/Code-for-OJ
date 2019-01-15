/* dijkstra heap map */
#include <bits\stdc++.h>
using namespace std;


struct Edge {
	int n1, n2, dis;
	friend istream& operator>>(istream& in, Edge &e);
};
istream& operator>>(istream &in, Edge &e)
{
	return in >> e.n1 >> e.n2 >> e.dis;
}
struct Node {
	/* ±ß¼¯ºÏ */
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

	int n = 150, m, cost;
	string src, des;
	while (cin >> m && m!=-1)
	{
		map <string, int> stationMap;
		vector<Edge> edgeArray(m + 1);
		vector<Node> nodeArray(n + 1);
		int *distance = new int[n + 1];
		memset(distance, 0x7F, (n + 1) * sizeof(int));
		int no = 0;
		cin >> src >> des;
		if (src == des)
		{
			for (int i = 1; i <= 3 * m; i++)
				cin >> src;
			cout << "0\n";
			continue;
		}
		stationMap[src] = ++no; stationMap[des] = ++no;
		for (int i = 1; i <= m; i++)
		{
			cin >> src >> des >> cost;
			if (stationMap[src] == 0)
				stationMap[src] = ++no;
			if (stationMap[des] == 0)
				stationMap[des] = ++no;

			nodeArray[stationMap[src]].edgeList.push_back(i);
			nodeArray[stationMap[des]].edgeList.push_back(i);
			edgeArray[i] = Edge{stationMap[src],stationMap[des],cost};
		}

		dijkstra(edgeArray, nodeArray, distance, 1);
		if (distance[2] != 0x7f7f7f7f)
			cout << distance[2] << endl;
		else
			cout << "-1\n";
		delete[]distance;


	}
	return 0;
}