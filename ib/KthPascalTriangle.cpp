/*************************************************************************************************
Kth Row of Pascal's Triangle

Given an index k, return the kth row of the Pascal¡¯s triangle.

Pascal¡¯s triangle : To generate A[C] in row R, sum up A¡¯[C] and A¡¯[C-1] from previous row R - 1.

Example:
Input : k = 3

Return : [1,3,3,1]
NOTE : k is 0 based. k = 0, corresponds to the row [1].
Note:Could you optimize your algorithm to use only O(k) extra space?
*************************************************************************************************/
#include <vector>
using namespace std;

vector<int> KthPascalTriangle(int A)
{
	int num_row = A + 1;
	vector<int> ans(num_row, 1);

	for (int i = 0; i < num_row; i++)
	{
		for (int j = i-1; j > 0; j--)
		{
			ans[j] = ans[j-1] + ans[j];
		}
	}

	return ans;
}
