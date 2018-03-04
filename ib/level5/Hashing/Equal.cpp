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
vector<int> Equal(vector<int> &A) {
	int len = (int)A.size();
	multimap<int, int> M;
	vector<int> ret;

	for (int i = 0; i<len; i++) M.insert({ A[i], i });

	for (int i = 0; i<len - 3; i++)
	{
		for (int j = i + 1; j<len; j++)
		{
			for (int k = i + 1; k<len - 1; k++)
			{
				if (k == j) continue;

				int r = A[i] + A[j] - A[k];
				auto range = M.equal_range(r);
				for (auto it = range.first; it != range.second; it++)
				{
					if (i < it->second && j != it->second && k < it->second)
					{
						ret.push_back(i);
						ret.push_back(j);
						ret.push_back(k);
						ret.push_back(it->second);
						return ret;
					}
				}

			}
		}
	}
	return ret;
}
#else
vector<int> Equal(vector<int> &vec)
{
	int N = vec.size();
	// With every sum, we store the lexicographically first occuring pair of integers. 
	map<int, pair<int, int> > Hash;
	vector<int> Ans;

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {

			int Sum = vec[i] + vec[j];

			if (Hash.find(Sum) == Hash.end()) {
				Hash[Sum] = make_pair(i, j);
				continue;
			}

			pair<int, int> p1 = Hash[Sum];
			if (p1.first != i && p1.first != j && p1.second != i && p1.second != j) {
				vector<int> ans;
				ans.push_back(p1.first);
				ans.push_back(p1.second);
				ans.push_back(i);
				ans.push_back(j);

				if (Ans.size() == 0) Ans = ans;
				else {
					// compare and assign Ans
					bool shouldReplace = false;
					for (int i1 = 0; i1 < Ans.size(); i1++) {
						if (Ans[i1] < ans[i1]) break;
						if (Ans[i1] > ans[i1]) {
							shouldReplace = true;
							break;
						}
					}
					if (shouldReplace) Ans = ans;
				}
			}
		}
	}

	return Ans;
}
#endif