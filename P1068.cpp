/* https://www.luogu.org/problemnew/show/P1068 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct candidate
{
	int no, score;
	
	bool operator<(const candidate &_cand) const
	{
		if (score < _cand.score)
			return 1;
		else if (score == _cand.score)
			return no > _cand.no;
		else
			return 0;
	}
};



int main()
{ 
	int n, m, minScore;
	cin >> n >> m;
	int no, score;
	priority_queue<candidate> q;

	for (int i = 0; i < n; i++)
	{
		cin >> no>> score;
		q.push({ no,score });
	}
	m *= 3;
	m /= 2;
	
	candidate *buffer = new candidate[n];
	int total = 0;
	for (int i = 0; i < m-1; i++)
	{
		buffer[total] = q.top();
		q.pop();
		total++;
	}
	score = q.top().score;
	buffer[total] = q.top();
	q.pop();
	total++;
	while (q.top().score == score && !(q.empty()))
	{
		buffer[total] = q.top();
		q.pop();
		total++;
	}
	cout << score << ' ' << total << endl;
	for (int i = 0; i < total; i++)
	{
		cout << buffer[i].no << ' ' << buffer[i].score << endl;
	}
	delete[] buffer;
	return 0;
}