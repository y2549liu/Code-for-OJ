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
		//最长不增子序列
		if (h[n] <= longestDesc[maxDescL])
			longestDesc[++maxDescL] = h[n];
		else if (h[n] > longestDesc[1])
			longestDesc[1] = h[n];
		else {
			int start = 1, end = maxDescL, mid;
			// 找到第一个比它小的元素
			while (start < end) {
				mid = (start + end) / 2;
				if (longestDesc[mid] >= h[n])
					start = mid + 1;
				else
					end = mid;
			}
			longestDesc[start] = h[n];
		}
		//最长单增子序列
		if (h[n] > longestAsc[maxAscL])
			longestAsc[++maxAscL] = h[n];
		else if (h[n] <= longestAsc[1])
			longestAsc[1] = h[n];
		else {
			int start = 1, end = maxAscL, mid;
			// 找到第一个比它大的元素
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