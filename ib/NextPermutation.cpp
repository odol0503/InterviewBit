/*************************************************************************************************
Next Permutation

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
The replacement must be in-place, do not allocate extra memory.
Examples:
1,2,3 ¡æ 1,3,2
3,2,1 ¡æ 1,2,3
1,1,5 ¡æ 1,5,1
20, 50, 113 ¡æ 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void NextPermutation(vector<int> &A) 
{
	int len = static_cast<int>(A.size());

	if (len < 2) return;
	else if (len == 2)
	{
		reverse(A.begin(), A.end());
		return;
	}

	int suffix = 0;
	for (int i = len - 1; i > 0; i--)
	{
		if (A[i - 1] < A[i])
		{
			suffix = i - 1;
			break;
		}
	}

	for (int j = len - 1; j > suffix; j--)
	{
		if (A[suffix] < A[j])
		{
			swap(A[suffix], A[j]);
			break;
		}
	}

	sort(A.begin() + suffix + 1, A.end());
}
