/*************************************************************************************************
Colorful Number

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts.
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245.
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence
is different

Example:
N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different.

Output : 1
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
static bool comp(const pair<int, int> &A, const pair<int, int> &B)
{
	if (A.second == B.second)
	{
		return A.first < B.first;
	}
	return (A.second < B.second);
}

vector<int> TwoSum(const vector<int> &A, int B) {
	int len = (int)A.size();
	unordered_multimap<int, int> hash;
	vector<pair<int, int>> ans;

	for (int i = 0; i<len; i++)
	{
		hash.insert({ A[i], i + 1 });
	}

	for (int i = 0; i<len; i++)
	{
		int required = B - A[i];
		auto range = hash.equal_range(required);
		for (auto it = range.first; it != range.second; it++)
		{
			if (i + 1 < it->second) ans.push_back({ i + 1, it->second });
		}
	}

	if (ans.empty()) return vector<int>();

	sort(ans.begin(), ans.end(), comp);
	int idx1 = ans[0].first;
	int idx2 = ans[0].second;
	vector<int> ret({ idx1 , idx2 });

	return ret;
}
#else
vector<int> TwoSum(const vector<int> &num, int target) {

	// map to store the mapping from number to its index. 
	map<int, int> M;
	vector<int> ans;

	for (int i = 0; i < num.size(); i++) {
		int required = target - num[i];
		if (M.find(required) != M.end()) {
			// We have our solution. index1 = M[required], index2 = i + 1 ( 1 based ). 
			ans.push_back(M[required]);
			ans.push_back(i + 1);
			return ans;
		}
		if (M.find(num[i]) == M.end()) {
			// We want to maintain the minimum index at M[num[i]]. i + 1 will 
			// obviously be greater than whats already present.
			M[num[i]] = i + 1;
		}
	}
	return ans;
}
#endif