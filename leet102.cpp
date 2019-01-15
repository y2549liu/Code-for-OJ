#include <bits/stdc++.h>
using namespace std;
/*02
class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int start = 0, count = 0, ans = 0;
		vector<int> type = { tree[0] };
		for (int i = 0; i < tree.size(); ++i) {
			if (type.size() == 1) {
				++count;
				if (tree[i] != type[0]) 
					type.push_back(tree[i]);
			}
			else if (type.size() == 2) {
				if (tree[i] == type[0] || tree[i]==type[1])
					++count;
				else {
					ans = max(ans, count);
					count = 1;
					int j = i - 1;
					while (j >= 0 && tree[j] == tree[i - 1])
						++count,--j;
					type = { tree[i],tree[i - 1] };
				}
			}
		}
		ans = max(ans, count);
		return ans;
	}
};*/
/*03
class Solution {
public:
	const long long mod = 1e9 + 7;
	int sumSubarrayMins(vector<int>& A) {
		int loc[30001][2];
		for (int i = 0; i < A.size(); ++i) {
			int first_num_smaller_no = i - 1;
			while (first_num_smaller_no != -1 && A[first_num_smaller_no]>A[i]) 
				first_num_smaller_no = loc[first_num_smaller_no][0];
			loc[i][0] = first_num_smaller_no;
		}
		for (int i = A.size()-1 ; i >=0 ; --i) {
			int last_num_smaller_no = i + 1;
			while (last_num_smaller_no != A.size() && A[last_num_smaller_no]>=A[i])
				last_num_smaller_no = loc[last_num_smaller_no][1];
			loc[i][1] = last_num_smaller_no;
		}
		long long ans = 0;
		for (int i = 0; i < A.size(); ++i) {
			ans += (i - loc[i][0])*(loc[i][1] - i)*A[i];
			ans %= mod;
		}
		return ans;
	}
};
*/
class Solution {
public:
	int superpalindromesInRange(string L, string R) {
		string pa[100] = { 
			"0",
			"1",
			"4",
			"9",
			"121",
			"484",
			"10201",
			"12321",
			"14641",
			"40804",
			"44944",
			"1002001",
			"1234321",
			"4008004",
			"100020001",
			"102030201",
			"104060401",
			"121242121",
			"123454321",
			"125686521",
			"400080004",
			"404090404",
			"10000200001",
			"10221412201",
			"12102420121",
			"12345654321",
			"40000800004",
			"1000002000001",
			"1002003002001",
			"1004006004001",
			"1020304030201",
			"1022325232201",
			"1024348434201",
			"1210024200121",
			"1212225222121",
			"1214428244121",
			"1232346432321",
			"1234567654321",
			"4000008000004",
			"4004009004004",
			"100000020000001",
			"100220141022001",
			"102012040210201",
			"102234363432201",
			"121000242000121",
			"121242363242121",
			"123212464212321",
			"123456787654321",
			"400000080000004",
			"10000000200000001",
			"10002000300020001",
			"10004000600040001",
			"10020210401202001",
			"10022212521222001",
			"10024214841242001",
			"10201020402010201",
			"10203040504030201",
			"10205060806050201",
			"10221432623412201",
			"10223454745432201",
			"12100002420000121",
			"12102202520220121",
			"12104402820440121",
			"12122232623222121",
			"12124434743442121",
			"12321024642012321",
			"12323244744232321",
			"12343456865434321",
			"12345678987654321",
			"40000000800000004",
			"40004000900040004",
			"1000000002000000001",
			"1000220014100220001",
			"1002003004003002001",
			"1002223236323222001",
			"1020100204020010201",
			"1020322416142230201",
			"1022123226223212201",
			"1022345658565432201",
			"1210000024200000121",
			"1210242036302420121",
			"1212203226223022121",
			"1212445458545442121",
			"1232100246420012321",
			"1232344458544432321",
			"1234323468643234321",
			"4000000008000000004"}; //87
		int s = 0, e = 0;
		for (int i = 0; i < 87; ++i) {
			if (pa[i].length() > L.length())
				s = i;
			else if (pa[i].length() == L.length() && pa[i] >= L)
				s = i;
			if (s)
				break;
		}
		for (int i = 86; i >= 0; --i) {
			if (pa[i].length() < R.length())
				e = i;
			else if (pa[i].length() == R.length() && pa[i] <= R)
				e = i;
			if (e)
				break;
		}
		return e-s+1;
	}
};
int main() {
	Solution s;
	cout << s.superpalindromesInRange("4","1000");
	return 0;
}