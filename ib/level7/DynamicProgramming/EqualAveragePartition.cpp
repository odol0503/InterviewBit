/*************************************************************************************************
Equal Average Partition

Given an array with non negative numbers, divide the array into two parts such 
that the average of both the parts is equal.
Return both parts (If exist).
If there is no solution. return an empty list.

Example:
Input:
[1 7 15 29 11 9]

Output:
[9 15] [1 7 11 29]

The average of part is (15+9)/2 = 12,
average of second part elements is (1 + 7 + 11 + 29) / 4 = 12

NOTE 1: If a solution exists, you should return a list of exactly 2 lists of integers 
A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B 
( https://en.wikipedia.org/wiki/Lexicographical_order )
NOTE 2: If multiple solutions exist, return the solution where length(A) is minimum. 
If there is still a tie, return the one where A is lexicographically smallest. 
NOTE 3: Array will contain only non negative numbers.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
vector<int> getDiff(vector<int> &A, vector<int> &D)
{
	vector<int> ret(A.begin(), A.end());
	for (int d : D)
	{
		ret.erase(find(ret.begin(), ret.end(), d));
	}

	return ret;
}

int rec(vector<int> &A, int cur, int num, int target, vector<int> &arr, vector<vector<vector<bool>>> &dp)
{
	if (target < 0) return 0;
	if (num == 0)
	{
		if (target == 0) return 1;
		return 0;
	}

	if (dp[cur][target][num - 1] == false) return false;

	for (int i = cur; i<A.size(); i++)
	{
		arr.push_back(A[i]);
		if (rec(A, i + 1, num - 1, target - A[i], arr, dp)) return 1;
		arr.pop_back();
	}

	dp[cur][target][num - 1] = false;

	return 0;
}

vector<vector<int> > EqualAveragePartition(vector<int> &A) {
	vector<vector<int>> ret;
	sort(A.begin(), A.end());
	if (A.size() < 2) return ret;

	int sum = 0;
	for (int a : A) sum += a;

	vector<vector<vector<bool>>> dp(A.size() + 1, vector<vector<bool>>(sum + 1, vector<bool>(A.size() + 1, true)));
	vector<int> arr;
	for (int i = 1; i <= A.size() / 2; i++)
	{
		if ((sum*i) % A.size()) continue;
		int target = sum * i / A.size();
		if (rec(A, 0, i, target, arr, dp)) break;
	}

	if (arr.size() == 0) return ret;
	ret.push_back(arr);
	ret.push_back(getDiff(A, arr));
	return ret;
}
#else
vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
	if (sz == 0) return (sum == 0);
	if (index >= total_size) return false;

	if (dp[index][sum][sz] == false) return false;

	if (sum >= original[index]) {
		res.push_back(original[index]);
		if (possible(index + 1, sum - original[index], sz - 1)) return true;
		res.pop_back();
	}

	if (possible(index + 1, sum, sz)) return true;

	return dp[index][sum][sz] = false;
}

vector<vector<int> > EqualAveragePartition(vector<int> &Vec) {

	/*
	* SUM_of_Set1 / size_of_set1 = SUM_of_Set2 / size_of_set2
	* SUM_of_Set1 = SUM_of_Set2 * (size_of_set1 / size_of_set2)
	*
	* total_sum = Sum_of_Set1 + Sum_of_Set2
	* and size_of_set2 = total_size - size_of_set1
	*
	* Sum_of_Set1 = (total_sum - Sum_of_Set1) * (size_of_set1 / (total_size - size_of_set1))
	* OR on simplifying,
	*   total_sum / Sum_of_Set1 - 1 = (total_size - size_of_set1) / size_of_set1
	*   total_sum / Sum_of_Set1 = total_size / size_of_set1
	*   Sum_of_Set1 / size_of_set1 = total_sum / total_size
	*
	*   Now we can just iterate on size_of_set1, and we would know the required Sum_of_Set1
	*/

	sort(Vec.begin(), Vec.end());
	original.clear();
	original = Vec;
	dp.clear();
	res.clear();

	int total_sum = 0;
	total_size = Vec.size();

	for (int i = 0; i < total_size; ++i)
		total_sum += Vec[i];

	dp.resize(original.size(), vector<vector<bool> >(total_sum + 1, vector<bool>(total_size, true)));

	// We need to minimize size_of_set1. So, lets search for the first size_of_set1 which is possible. 
	for (int i = 1; i < total_size; i++) {
		// Sum_of_Set1 has to be an integer
		if ((total_sum * i) % total_size != 0) continue;
		int Sum_of_Set1 = (total_sum * i) / total_size;
		if (possible(0, Sum_of_Set1, i)) {

			// Ok. Lets find out the elements in Vec, not in res, and return the result.
			int ptr1 = 0, ptr2 = 0;
			vector<int> res1 = res;
			vector<int> res2;
			while (ptr1 < Vec.size() || ptr2 < res.size()) {
				if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
					ptr1++;
					ptr2++;
					continue;
				}
				res2.push_back(Vec[ptr1]);
				ptr1++;
			}

			vector<vector<int> > ans;
			ans.push_back(res1);
			ans.push_back(res2);
			return ans;
		}
	}
	// Not possible.
	vector<vector<int> > ans;
	return ans;
}
#endif