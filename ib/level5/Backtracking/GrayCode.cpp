/*************************************************************************************************
Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
void GenerateGrayCode(int A, bool up, vector<int> &cur, vector<vector<int>> &comb)
{
	if (0 == A)
	{
		comb.push_back(cur);
		return;
	}

	if (up)
	{
		for (int i = 0; i < 2; i++)
		{
			cur.push_back(i);
			GenerateGrayCode(A - 1, i == 1 ? false : true, cur, comb);
			cur.pop_back();
		}
	}
	else
	{
		for (int i = 1; i >= 0; i--)
		{
			cur.push_back(i);
			GenerateGrayCode(A - 1, i == 0 ? false : true, cur, comb);
			cur.pop_back();
		}
	}
}

int Bin2Int(vector<int> &bins)
{
	int ans = 0;
	int base = 1;
	for (int i = (int)bins.size() - 1; i >= 0; i--)
	{
		ans = ans + bins[i] * base;
		base *= 2;
	}
	return ans;
}

vector<int> GrayCode(int A) {
	vector<int> ret;
	vector<vector<int>> comb;
	vector<int> cur;

	GenerateGrayCode(A, true, cur, comb);

	for (int i = 0; i<(int)comb.size(); i++)
	{
		ret.push_back(Bin2Int(comb[i]));
	}

	return ret;
}
#else
vector<int> GrayCode(int n) {
	vector<int> result(1, 0);
	for (int i = 0; i < n; i++) {
		int curSize = result.size();
		// push back all element in result in reverse order
		for (int j = curSize - 1; j >= 0; j--) {
			result.push_back(result[j] + (1 << i));
		}
	}
	return result;
}
#endif