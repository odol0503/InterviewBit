/*************************************************************************************************
Jump Game Array
Given an array of non-negative integers, you are initially positioned 
at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).
A = [3,2,1,0,4], return 0 ( false ).
Return 0/1 for this problem
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int JumpGameArray(vector<int> &A) {
	int ret = 0;
	int len = (int)A.size();
	int reach = 0;
	if (len == 1) return 1;
	for (int i = 0; i<len && reach >= i; i++)
	{
		reach = max(reach, A[i] + i);
		if (reach > len - 1) return 1;
	}
	return 0;
}
#else
int JumpGameArray(vector<int> &A)
{
	int n = A.size();
	int minIndexPossible = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		bool isPossibleFromThisIndex = false;
		if (i + A[i] >= minIndexPossible) {
			isPossibleFromThisIndex = true;
			minIndexPossible = i;
		}
		if (i == 0) return isPossibleFromThisIndex;
	}
	return true;
}
#endif