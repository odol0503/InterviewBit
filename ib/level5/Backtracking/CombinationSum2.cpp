/*************************************************************************************************
Combination Sum II

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡¦ , ak) must be in non-descending order. (ie, a1 ¡Â a2 ¡Â ¡¦ ¡Â ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
void CombSum(vector<int> &A, int B, int C, vector<vector<int>> &comb)
{
	int len = (int)A.size();
	vector<int> sub;
	int preSub = -1;

	if (!comb.empty())
	{
		sub = comb.back();
		comb.pop_back();
	}

	for (int i = C; i<len; i++)
	{
		if (preSub == A[i]) continue;

		int val = B - A[i];

		if (val == 0)
		{
			sub.push_back(A[i]);
			comb.push_back(sub);
			return;
		}
		else if (val > 0)
		{
			sub.push_back(A[i]);
			preSub = A[i];
			comb.push_back(sub);
			CombSum(A, val, i + 1, comb);
			sub.pop_back();
		}
		else return;
	}
}

vector<vector<int> > CombinationSum2(vector<int> &A, int B) {
	vector<vector<int>> comb;

	sort(A.begin(), A.end());
	CombSum(A, B, 0, comb);

	return comb;
}
#else
void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
	if (currentSum > target) {
		return;
	}
	if (currentSum == target) {
		ans.push_back(current);
		return;
	}
	if (index >= candidates.size()) {
		return;
	}

	int endIndex;
	for (endIndex = index + 1; endIndex < candidates.size() && candidates[endIndex] == candidates[endIndex - 1]; endIndex++);
	int countIndex = endIndex - index;
	for (int i = 0; i <= countIndex; i++) {
		for (int j = 0; j < i; j++) current.push_back(candidates[index]);
		currentSum += i * candidates[index];
		doWork(candidates, endIndex, current, currentSum, target, ans);
		currentSum -= i * candidates[index];
		for (int j = 0; j < i; j++) current.pop_back();
	}
	}

vector<vector<int> > CombinationSum2(vector<int> &candidates, int target) {
	vector<int> current;
	vector<vector<int> > ans;
	sort(candidates.begin(), candidates.end());
	doWork(candidates, 0, current, 0, target, ans);
	return ans;
}
#endif