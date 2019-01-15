#include <bits/stdc++.h>
using namespace std;

struct tp {
	int a, b, c;
	bool operator<(const tp& x) const{
		return(a != x.a) ? (a < x.a) : (b != x.b) ? (b < x.b) : (c < x.c);
	}
	bool operator==(const tp& x)const {
		return (a == x.a) && (b == x.b) && (c == x.c);
	}
	operator vector<int>() {
		vector<int> ans = { a,b,c };
		return ans;
	}
};
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3)
			return ans;
		sort(nums.begin(), nums.end());
		set<tp> mp;
		for (int i = 0; i<nums.size() - 2; ++i) {
			for (int j = i + 1; j<nums.size() - 1; ++j) {
				int now = nums[i] + nums[j];
				if (now> 0 || now+ nums[j] > 0)
					break;
			    auto iter = lower_bound(nums.begin()+j+1, nums.end(), -now);
				if (iter == nums.end() || *iter != -now)
					continue;
				else
					mp.insert({ nums[i],nums[j],-now });
			}
		}
		for (auto i : mp) {
			ans.push_back(vector<int>(i));
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.threeSum(vector<int>{ 1,1,-2 });
	return 0;
}