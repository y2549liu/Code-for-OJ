#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
	vector<int> v;
	StockSpanner() {
		v.clear();
	}
	int next(int price) {
		v.push_back(price);
		int ans = 0;
		for (int i = v.size() - 1; i >= 0; --i) {
			if (price < v[i])
				break;
			else ++ans;
		}
		return ans;
	}
};
int main() {
	StockSpanner s;
	cout << s.next(32);
	cout << s.next(82); 
	cout << s.next(73); 
	cout << s.next(99);
	cout << s.next(91);

	return 0;
}