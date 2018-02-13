/*************************************************************************************************
3 Sum Zero

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Â b ¡Â c)
The solution set must not contain duplicate triplets. 
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<vector<int> > ThreeSumZero(vector<int> &A) {
	int len = (int)A.size();
	vector<vector<int>> ans;

	sort(A.begin(), A.end());

	for (int i = 0; i < len - 2; i++)
	{
		int j = i + 1;
		int k = len - 1;
		while (j < k)
		{
			int sum = A[i] + A[j] + A[k];
			if (sum == 0)
			{
				vector<int> temp;
				temp.push_back(A[i]);
				temp.push_back(A[j++]);
				temp.push_back(A[k--]);
				if (find(ans.begin(), ans.end(), temp) == ans.end())
					ans.push_back(temp);
			}
			else if (sum > 0) k--;
			else j++;
		}
	}

	return ans;
}
#else
vector<vector<int> > ThreeSumZero(vector<int> &A) {
	sort(num.begin(), num.end());

	int sum = 0;
	vector<vector<int> > ans;
	int sz = num.size();
	// Fix the smallest number in the three integers
	for (int i = 0; i < sz - 2; i++) {
		// Lets make sure that we do not have duplicate triplets. 
		// We skip the duplicate elements as min integer in the triplet. 
		if (i > 0 && num[i] == num[i - 1]) {
			continue;
		}
		// Now num[i] is the smallest number in the three integers in the solution
		int ptr1 = i + 1, ptr2 = num.size() - 1;
		while (ptr1 < ptr2) {
			sum = num[i] + num[ptr1] + num[ptr2];
			if (sum == 0) {
				vector<int> tmp;
				tmp.push_back(num[i]);
				tmp.push_back(num[ptr1]);
				tmp.push_back(num[ptr2]);
				ans.push_back(tmp);
			}
			if (sum > 0) {
				ptr2--;
			}
			else if (sum < 0) {
				ptr1++;
			}
			else if (sum == 0) {
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
	return ans;
}
#endif