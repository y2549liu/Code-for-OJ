#include <bits/stdc++.h>
using namespace std;
#define maxn 100001
int h[maxn];
int longestDesc[maxn], longestAsc[maxn];
int main() {
	int n = 0;
	int maxDescL = 0, maxAscL = 0;
	longestDesc[0] = 0x7fffffff;
	longestAsc[0] = 0;
	while (cin >> h[++n]) {
		//�����������
		if (h[n] <= longestDesc[maxDescL])
			longestDesc[++maxDescL] = h[n];
		else if (h[n] > longestDesc[1])
			longestDesc[1] = h[n];
		else {
			int start = 1, end = maxDescL, mid;
			// �ҵ���һ������С��Ԫ��
			while (start < end) {
				mid = (start + end) / 2;
				if (longestDesc[mid] >= h[n])
					start = mid + 1;
				else
					end = mid;
			}
			longestDesc[start] = h[n];
		}
		//�����������
		if (h[n] > longestAsc[maxAscL])
			longestAsc[++maxAscL] = h[n];
		else if (h[n] <= longestAsc[1])
			longestAsc[1] = h[n];
		else {
			int start = 1, end = maxAscL, mid;
			// �ҵ���һ���������Ԫ��
			while (start < end) {
				mid = (start + end) / 2;
				if (longestAsc[mid] < h[n])
					start = mid + 1;
				else
					end = mid;
			}
			longestAsc[start] = h[n];
		}
	}
	cout << maxDescL << endl << maxAscL;
	return 0;
}