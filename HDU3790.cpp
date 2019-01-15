/* http://acm.hdu.edu.cn/showproblem.php?pid=3790 */
/* spfa */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstdlib>
#include <string.h>
using namespace std;
#define MAXN 1000
#define MAXE 100000;

#pragma GCC optimize (2)
#pragma G++ optimize (2)

struct Node {
	vector<int> edgeList;
};

struct Data
{
	Data() { dis = INT32_MAX; cost = INT32_MAX; }
	int dis, cost;
};

struct Edge {
	int from, to, dis, cost;
	Edge() {}
	Edge(int f, int t, int d, int c) {
		from = f; to = t; dis = d; cost = c;
	}
	friend istream& operator>>(istream& in, Edge &e);
};
/*
// STRUCT TEMPLATE greater
template<class _Ty = void>
struct greater
{	
	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator> to operands
		return (_Left > _Right);
	}
};
*/

void dijk(vector<Edge> &edgeArray , vector<Node> &nodeEdge, vector<Data> &dataArray ,int src=0)
{
	struct DIS {
		int no, dis;
		bool operator>(const DIS& d) const
			{return dis > d.dis;}
	};
	int *visited =new int[nodeEdge.size()] ;
	memset(visited, 0, nodeEdge.size() *sizeof (int));
	priority_queue<DIS,vector<DIS>,greater<DIS> > Q;
	Q.push(DIS{ src,0 });
	dataArray[src].dis = 0;
	dataArray[src].cost = 0;
	int from,to;
	while (! Q.empty())
	{
		DIS cur = Q.top();	Q.pop();
		if (visited[cur.no])
			continue;
		else
			visited[cur.no] = 1;
		for (int i = 0; i < nodeEdge[cur.no].edgeList.size(); i++)
		{
			
			Edge &edge= edgeArray[nodeEdge[cur.no].edgeList[i]]; 
			from =cur.no;
			to = edge.to ^ edge.from ^from;
			if ((dataArray[from].dis + edge.dis < dataArray[to].dis)
				|| 
				( dataArray[cur.no].dis + edge.dis == dataArray[to].dis
					&&dataArray[from].cost + edge.cost < dataArray[to].cost ) )
			{
				dataArray[to].dis = dataArray[from].dis + edge.dis;
				dataArray[to].cost = dataArray[from].cost + edge.cost;
				Q.push(DIS{ to ,dataArray[to].dis });
			}
		}
	
	}
	delete[]visited;
}



int main()
{
	int n, m;
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		vector<Edge> edgeArray(m);
		vector<Node> nodeEdge(n);
		vector<Data> dataArray(n);
		int from, to, dis, cost;
		for (int i = 0; i < m; ++i)
		{
			cin >> edgeArray[i];
			--edgeArray[i].from; --edgeArray[i].to;
			nodeEdge[edgeArray[i].from].edgeList.push_back(i);
			nodeEdge[edgeArray[i].to].edgeList.push_back(i);
		}
		int src, des;
		cin >> src >> des;
		--src;
		--des;
		dijk(edgeArray, nodeEdge, dataArray, src);
		cout << dataArray[des].dis << ' ' << dataArray[des].cost << endl;
	}
	return 0;
}

istream & operator>>(istream & in, Edge & e)
{
	 return in >> e.from >> e.to >> e.dis >> e.cost;
}

