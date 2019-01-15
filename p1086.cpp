/* https://www.luogu.org/problemnew/show/P1042 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

template <class T>
int compare(T a, T b)
{
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}

template <class T>
void mySort(T *begin, T *end, int (*cmp)(T a, T b)= compare)
{
	if (begin + 1 >= end) //1项或0项
		return;
	else if (begin + 2 == end)//2项直接比
	{
		if (cmp(begin[0], begin[1]) <= 0)
			return;
		else
		{
			swap(begin[0], begin[1]);
			return;
		}
	}
	//取中间元素为基准
	T key = *((end - begin) / 2 + begin);
	T *head = begin, *tail = end - 1;
	while (head < tail)
	{
		while (head < tail && cmp(*head, key) < 0)
			head++;
		while (head < tail && cmp(*tail, key) > 0 )
			tail--;
		if (head < tail)
		{
			swap(*head, *tail);
			head++;
			tail--;
		}
	}
	if (head == tail)//问题在于 tail==head 时 不知道head和key哪一个大
	{
		mySort(begin, head+1, cmp);
		mySort(tail, end, cmp);
	}
	else
	{
		mySort(begin, head, cmp);
		mySort(head, end, cmp);
	}
}

int main()
{
	int n;
	cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];

	mySort(data, data + n);
	for (int i = 0; i < n; i++)
		cout << data[i]<<' ';
	delete[]data;
	return 0;
}