/*************************************************************************************************
4 Sum
Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in the array 
which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Â b ¡Â c ¡Â d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

(-2, -1, 1, 2)
(-2,  0, 0, 2)
(-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR 
(Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

#define OWN

#ifdef OWN
vector<vector<int> > FourSum(vector<int> &A, int B) {
	multimap<int, int> M;
	int len = (int)A.size();
	vector<vector<int>> ret;

	if (len < 4) return ret;

	sort(A.begin(), A.end());
	for (int i = 3; i<len; i++) M.insert({ A[i], i });

	for (int i = 0; i<len - 3; i++)
	{
		for (int j = i + 1; j<len - 2; j++)
		{
			for (int k = j + 1; k<len - 1; k++)
			{
				int r = B - A[i] - A[j] - A[k];
				auto range = M.equal_range(r);
				for (auto it = range.first; it != range.second; it++)
				{
					if (k < it->second)
					{
						vector<int> tmp({ A[i], A[j], A[k], it->first });
						if (find(ret.begin(), ret.end(), tmp) == ret.end())
						{
							ret.push_back(tmp);
						}
					}
				}
			}
		}
	}
	return ret;
}
#else
vector<vector<int> > FourSum(vector<int> &num, int target) {
	sort(num.begin(), num.end());

	int sum = 0;
	vector<vector<int> > ans;
	int sz = num.size();
	// Fix the smallest number in the three integers
	for (int i = 0; i < sz - 3; i++) {
		// Lets make sure that we do not have duplicate triplets. 
		// We skip the duplicate elements as min integer in the triplet. 
		if (i > 0 && num[i] == num[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < sz - 2; j++) {
			if (j > i + 1 && num[j] == num[j - 1]) {
				continue;
			}
			// Now num[i] is the smallest number in the three integers in the solution
			int ptr1 = j + 1, ptr2 = num.size() - 1;
			while (ptr1 < ptr2) {
				sum = num[i] + num[j] + num[ptr1] + num[ptr2];
				if (sum == target) {
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[ptr1]);
					tmp.push_back(num[ptr2]);
					ans.push_back(tmp);
				}
				if (sum > target) {
					ptr2--;
				}
				else if (sum < target) {
					ptr1++;
				}
				else if (sum == target) {
					// In this case, we have a choice of increasing the first pointer, 
					// or decreasing the last pointer. Lets go wiht increasing the first 
					// pointer approach
					// Note that we cannot have duplicate triplets. So we need to skip all 
					// the occurrences of duplicates.
					ptr1++;
					while (ptr1 < ptr2 && num[ptr1] == num[ptr1 - 1]) {
						ptr1++;
					}
				}
			}
		}
	}
	return ans;
}
#endif