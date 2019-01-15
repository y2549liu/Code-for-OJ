/* https://www.luogu.org/problemnew/show/P1088 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n>>m;
	int *data = new int[n+1];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	while (m--)
		next_permutation(data, data + n);
	for (int i = 0; i < n; i++) {
		cout << data[i];
		if (i != n - 1)
			cout << " ";
	}
	delete[]data;
	return 0;
}