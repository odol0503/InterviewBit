/*************************************************************************************************
Subset

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
[],
[1],
[1, 2],
[1, 2, 3],
[1, 3],
[2],
[2, 3],
[3],
]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
void SubsetHelper(vector<int> &A, int pos, vector<vector<int>> &subsets)
{
	int len = (int)A.size();
	vector<int> sub = subsets.back();

	for (int i = pos; i<len; i++)
	{
		sub.push_back(A[i]);
		subsets.push_back(sub);
		SubsetHelper(A, i + 1, subsets);
		sub.pop_back();
	}
}

vector<vector<int> > Subset(vector<int> &A) {
	vector<vector<int>> ret;
	ret.push_back(vector<int>());
	sort(A.begin(), A.end());
	SubsetHelper(A, 0, ret);
	return ret;
}
#else
void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
	if (index >= S.size()) {
		result.push_back(current);
		return;
	}
	// Ignore the current index.
	generateSubsets(S, index + 1, current, result);

	// Include the current index. 
	current.push_back(S[index]);
	generateSubsets(S, index + 1, current, result);
	current.pop_back();
}

vector<vector<int> > Subset(vector<int> &S) {
	vector<vector<int> > result;
	vector<int> current;
	sort(S.begin(), S.end());
	generateSubsets(S, 0, current, result);
	sort(result.begin(), result.end());
	return result;
}
#endif