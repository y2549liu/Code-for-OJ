#include <bits/stdc++.h>
using namespace std;
struct node {
	int u, v, w;
	int next;
}edge[11000];
int head[11000], cnt;
int dp[11000][2], flag[11000], belong[11000][2];

void add(int u, int v, int w)
{
	edge[cnt].u = u; edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void dfs(int u)
{
	if (head[u] == -1)
		return;
	int i, v, k1, k2;
	for (i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].v;
		dfs(v);
		if (dp[v][0] + edge[i].w > dp[u][0])
		{
			dp[u][1] = dp[u][0]; belong[u][1] = belong[u][0];
			dp[u][0] = dp[v][0] + edge[i].w; belong[u][0] = v;
		}
		else if (dp[v][0] + edge[i].w > dp[u][1])
		{
			dp[u][1] = dp[v][0] + edge[i].w; belong[u][1] = v;
		}
	}
}
int main()
{
	int n, u, v, w;
	int i;
	while (scanf("%d", &n))
	{
		memset(flag, 0, sizeof(flag));
		memset(dp, 0, sizeof(dp));
		memset(head, -1, sizeof(head));
		memset(belong, 0, sizeof(belong));
		cnt = 0;
		add(0, 1, 0);
		for (i = 2; i <= n; i++)
		{
			scanf("%d %d", &u, &w);
			add(u, i, w);
		}
		dfs(1);
		queue <int> que;
		que.push(0);
		while (!que.empty())
		{
			u = que.front();
			que.pop();
			for (i = head[u]; i != -1; i = edge[i].next)
			{
				v = edge[i].v;
				if (flag[v])
				{
					if (dp[v][0] + edge[i].w == dp[u][0])
					{
						if (dp[u][1] + edge[i].w > dp[v][0])
						{
							flag[belong[v][0]] = 1;
							dp[v][1] = dp[v][0];
							dp[v][0] = dp[u][1] + edge[i].w;
						}
						else if (dp[u][1] + edge[i].w > dp[v][1])
						{
							flag[belong[v][0]] = 1;
							dp[v][1] = dp[u][1] + edge[i].w;
						}
						else
						{
							flag[belong[v][0]] = 1;
							flag[belong[v][1]] = 1;
						}
					}
					else
					{
						if (dp[u][0] + edge[i].w > dp[v][0])
						{
							flag[belong[v][0]] = 1;
							dp[v][1] = dp[v][0];
							dp[v][0] = dp[u][0] + edge[i].w;
						}
						else if (dp[u][0] + edge[i].w > dp[v][1])
						{
							flag[belong[v][0]] = 1;
							dp[v][1] = dp[u][0] + edge[i].w;
						}
						else
						{
							flag[belong[v][0]] = 1;
							flag[belong[v][1]] = 1;
						}
					}
				}
				else
				{
					if (dp[u][0] + edge[i].w > dp[v][0])
					{
						flag[belong[v][0]] = 1;
						dp[v][1] = dp[v][0];
						dp[v][0] = dp[u][0] + edge[i].w;
					}
					else if (dp[u][0] + edge[i].w > dp[v][1])
					{
						flag[belong[v][0]] = 1;
						dp[v][1] = dp[u][0] + edge[i].w;
					}
					else
					{
						flag[belong[v][0]] = 1;
						flag[belong[v][1]] = 1;
					}
				}
				que.push(v);
			}
		}
		for (i = 1; i <= n; i++)
			printf("%d\n", dp[i][0]);
	}
	return 0;
}
