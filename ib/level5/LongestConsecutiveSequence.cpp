/*************************************************************************************************
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

static void CheckConsecutive(unordered_set<int> &S, int target, bool up, int &len)
{
	if (S.count(target) == 0) return;
	len++;
	S.erase(target);
	CheckConsecutive(S, target + (up ? 1 : -1), up, len);
}

int LongestConsecutive(const vector<int> &A) {
	unordered_set<int> S(A.begin(), A.end());
	int max_len = 0;

	for (auto it = S.begin(); it != S.end(); it++)
	{
		int len = 1;
		if (S.count(*it + 1)) CheckConsecutive(S, *it + 1, true, len);
		if (S.count(*it - 1)) CheckConsecutive(S, *it - 1, false, len);
		max_len = max(max_len, len);
	}

	return max_len;
}
