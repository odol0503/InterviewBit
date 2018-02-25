/*************************************************************************************************
Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡¦ , ak) must be in non-descending order. (ie, a1 ¡Â a2 ¡Â ¡¦ ¡Â ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ¡¦ 
(a1 = b1 AND a2 = b2 AND ¡¦ ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

#ifdef OWN
static void Comb(vector<int> &A, int B, int C, vector<vector<int>> &subset)
{
	int len = (int)A.size();
	vector<int> sub;

	if (!subset.empty())
	{
		sub = subset.back();
		subset.pop_back();
	}

	for (int i = C; i<len; i++)
	{
		int val = B - A[i];
		if (val >= 0)
		{
			sub.push_back(A[i]);
			subset.push_back(sub);
			if (val == 0) return;
			Comb(A, val, i, subset);
			sub.pop_back();
		}
		else return;
	}
}

vector<vector<int> > CombinationSum(vector<int> &A, int B) {
	vector<vector<int>> subset;
	unordered_set<int> s;
	int len = (int)A.size();
	s.reserve(len);
	for (int i = len-1; i >= 0; i--)
	{
		if (s.count(A[i])) A.erase(A.begin() + i);
		else s.insert(A[i]);
	}

	sort(A.begin(), A.end());
	Comb(A, B, 0, subset);
	return subset;
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
	for (int i = index; i < candidates.size(); i++) {
		current.push_back(candidates[i]);
		currentSum += candidates[i];

		doWork(candidates, i, current, currentSum, target, ans);

		current.pop_back();
		currentSum -= candidates[i];
	}
}

vector<vector<int> > CombinationSum(vector<int> &candidates, int target) {
	vector<int> current;
	vector<vector<int> > ans;
	sort(candidates.begin(), candidates.end());
	vector<int> uniqueCandidates;
	for (int i = 0; i < candidates.size(); i++) {
		if (i == 0 || candidates[i] != candidates[i - 1]) {
			uniqueCandidates.push_back(candidates[i]);
		}
	}
	doWork(uniqueCandidates, 0, current, 0, target, ans);
	return ans;
}
#endif