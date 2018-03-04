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
vector<vector<int> > Anagrams(const vector<string> &A) {
	int len = (int)A.size();
	vector<vector<int>> ret;
	multimap<string, int> M;
	vector<string> B(A);

	for (int i = 0; i<len; i++)
	{
		sort(B[i].begin(), B[i].end());
		M.insert({ B[i], i + 1 });
	}
	sort(B.begin(), B.end());

	int idx = 0;
	for (int i = 0; i<len; i++)
	{
		if (i<len - 1 && B[i] == B[i + 1]) continue;
		auto range = M.equal_range(B[i]);
		ret.push_back(vector<int>());
		for (auto it = range.first; it != range.second; it++)
		{
			ret[idx].push_back(it->second);
		}
		idx++;
	}

	return ret;
}
#else
vector<vector<int> > Anagrams(const vector<string> &strs) {
	vector<vector<int> > ans;
	map<string, vector<int> > groups;
	for (int i = 0; i < strs.size(); i++) {
		//sort every string and store groups of strings that are anagrams in a map
		string copyString = strs[i];
		sort(copyString.begin(), copyString.end());
		groups[copyString].push_back(i + 1);
	}

	for (map<string, vector<int> >::iterator it = groups.begin(); it != groups.end(); it++) {
		ans.push_back(it->second);
	}
	return ans;
	}
#endif