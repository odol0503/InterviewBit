/*************************************************************************************************
Subsets2

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
void SubSet2(vector<int> &A, int idx, vector<vector<int>> &comb)
{
	int len = (int)A.size();
	vector<int> sub;
	int prevSub = -1;

	if (!comb.empty()) sub = comb.back();

	for (int i = idx; i<len; i++)
	{
		if (prevSub == A[i]) continue;
		sub.push_back(A[i]);
		comb.push_back(sub);
		prevSub = A[i];
		SubSet2(A, i + 1, comb);
		sub.pop_back();
	}
}

vector<vector<int> > SubsetsWithDup(vector<int> &A) {
	vector<vector<int>> comb;
	comb.push_back(vector<int>());
	sort(A.begin(), A.end());
	SubSet2(A, 0, comb);
	return comb;
}
#else
void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
	if (index >= S.size()) {
		result.push_back(current);
		return;
	}
	// Find the number of occurence of the element at current index. 
	int curIndex = index + 1;
	while (curIndex < S.size() && S[curIndex] == S[index]) {
		curIndex++;
	}

	// There are curIndex - index number of repeating entries. 
	// Now we loop over the number of entries to include in our subset. 
	for (int i = 0; i <= (curIndex - index); i++) {
		for (int j = 0; j < i; j++) current.push_back(S[index]);
		generateSubsets(S, curIndex, current, result);
		for (int j = 0; j < i; j++) current.pop_back();
	}
}

vector<vector<int> > SubsetsWithDup(vector<int> &S) {
	vector<vector<int> > result;
	vector<int> current;
	sort(S.begin(), S.end());
	generateSubsets(S, 0, current, result);
	sort(result.begin(), result.end());
	return result;
}
#endif