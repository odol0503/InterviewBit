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

#define OWN

#ifdef OWN
static int combination(int n, int k)
{
	if (n == 0 || k == 0 || n == k) return 1;
	return combination(n - 1, k) + combination(n - 1, k - 1);
}

vector<int> KthPascalTriangle(int A)
{
	vector<int> ret;

	for (int i = 0; i <= A; i++)
	{
		ret.push_back(combination(A, i));
	}

	return ret;
}
#else
void insert(vector<int> &v, int index, int val) {
	if (index >= v.size()) {
		v.push_back(val);
	}
	else {
		v[index] = val;
	}
}

vector<int> KthPascalTriangle(int rowIndex) {
	vector<int> ans[2];
	int numRows = rowIndex + 1;
	if (numRows <= 0) {
		return ans[0];
	}
	int curRow = 0, prevRow = 1;
	ans[0].push_back(1);
	for (int i = 1; i < numRows; i++) {
		swap(curRow, prevRow);
		insert(ans[curRow], 0, 1);
		for (int j = 0; j < ans[prevRow].size() - 1; j++) {
			insert(ans[curRow], j + 1, ans[prevRow][j] + ans[prevRow][j + 1]);
		}
		insert(ans[curRow], ans[prevRow].size(), 1);
	}
	return ans[curRow];
}
#endif
