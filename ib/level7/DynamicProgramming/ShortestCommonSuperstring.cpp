/*************************************************************************************************
Shortest common superstring

Given a set of strings. Find the length of smallest string which
has all the strings in the set as substring

Constraints:
1) 1 <= Number of strings <= 18
2) Length of any string in the set will not exceed 100.

Example:
Input: [¡°abcd¡±, ¡°cdef¡±, ¡°fgh¡±, ¡°de¡±]
Output: 8 (Shortest string: ¡°abcdefgh¡±)
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
static int getLen(vector<string> &A, vector<int> idx)
{
	int num = (int)A.size();
	string str = A[idx[0]];

	for (int n=1; n<(int)idx.size(); n++)
	{
		int i = idx[n];
		int len1 = (int)str.size();

		for (int j = 0; j<len1; j++)
		{
			if (str.compare(j, string::npos, A[i], 0, len1 - j) == 0)
			{
				str += A[i].substr(len1-j);
				break;
			}

			if (j == len1 - 1) str += A[i];
		}
	}

	return (int)str.size();
}

int nextPermute(vector<int> &idx)
{
	int ret = 0;
	int num = (int)idx.size();

	for (int i = num - 1; i > 0; i--)
	{
		if (idx[i - 1] < idx[i])
		{
			int j = num - 1;
			while (idx[i - 1] > idx[j]) j--;
			swap(idx[i - 1], idx[j]);
			reverse(idx.begin() + i, idx.end());
			ret = 1;
			break;
		}
	}

	return ret;
}

int ShortestCommonSuperstring(vector<string> &A) {
	int num = (int)A.size();

	if (num == 0) return 0;
	if (num == 1) return (int)A[0].size();

	vector<int> idx(num);
	iota(idx.begin(), idx.end(), 0);

	int min_len = INT_MAX;
	do
	{
		min_len = min(min_len, getLen(A, idx));
	} while (nextPermute(idx));

	return min_len;
}
#else

#endif