/*************************************************************************************************
Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
Make sure the combinations are sorted.

To elaborate,
Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
[1,2],
[1,3],
[1,4],
[2,3],
[2,4],
[3,4],
]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
void Combine(int A, int B, int C, vector<vector<int>> &comb)
{
	vector<int> subset;
	if (!comb.empty())
	{
		subset = comb.back();
		if (subset.size() == B) return;
		comb.pop_back();
	}

	for (int i = C; i <= A; i++)
	{
		subset.push_back(i);
		comb.push_back(subset);
		Combine(A, B, i + 1, comb);
		subset.pop_back();
	}
}

vector<vector<int> > Combinations(int A, int B) {
	vector<vector<int>> comb;

	Combine(A, B, 1, comb);

	return comb;
}
#else
void combineHelper(vector<int> &current, int n, int k, vector<vector<int> > &ans) {
	if (k == 0) {
		vector<int> newEntry = current;
		reverse(newEntry.begin(), newEntry.end());
		ans.push_back(newEntry);
		return;
	}
	if (n == 0 || n < k) return;
	// We have 2 options here. We can either include n or not. 
	// Option 1 : Do not include n.
	combineHelper(current, n - 1, k, ans);
	// Option 2 : Include n. 
	current.push_back(n);
	combineHelper(current, n - 1, k - 1, ans);
	current.pop_back();
	return;
		}

vector<vector<int> > Combinations(int n, int k) {
	vector<vector<int> > ans;
	vector<int> current;
	combineHelper(current, n, k, ans);
	sort(ans.begin(), ans.end());
	return ans;
}
#endif