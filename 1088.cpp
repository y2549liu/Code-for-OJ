#include <iostream>
#include <math.h>
using namespace std;

#define max(x,y) ((x)>(y))?(x):(y);
int r, c;
int height[101][101] = { 0 };
int dis[101][101] = { 0 };

 bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= r || y >= c)
		return 0;
	else
		return 1;
}
int abs(int _x)
{
	 return (_x) > 0 ? _x : -_x;
}

int DFS(int x,int y)
{
	if (dis[x][y] > 0)
		return dis[x][y];
	 
	dis[x][y] = 1;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j )
		{
			if ( abs(i+j)==1 &&  height[x][y] > height[x +i][y+j] && check(x+i, y+j))
			{
				dis[x][y] = max(dis[x][y], 1+ DFS(x + i,y + j));
			}
		}
	}
	return dis[x][y];
}


int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> height[i][j];
		}
	}
	int maxresult=0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			maxresult=max(maxresult, DFS(i, j));
		}
	}
	cout << maxresult << endl;
	return 0;
}