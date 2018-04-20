/*************************************************************************************************
Longest Arithmetic Progression

Find longest Arithmetic Progression in an integer array and return its length. More formally, 
find longest sequence of indeces, 0 < i1 < i2 < ・ < ik < ArraySize(0-indexed) such that sequence 
A[i1], A[i2], ・, A[ik] is an Arithmetic Progression. Arithmetic Progression is a sequence 
in which all the differences between consecutive pairs are the same, 
i.e sequence B[0], B[1], B[2], ・, B[m - 1] of length m is an Arithmetic Progression 
if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == ・ == B[m - 1] - B[m - 2].

Examples
1) 1, 2, 3(All differences are equal to 1)
2) 7, 7, 7(All differences are equal to 0)
3) 8, 5, 2(Yes, difference can be negative too)

Samples
1) Input: 3, 6, 9, 12
Output: 4

2) Input: 9, 4, 7, 2, 10
Output: 3(If we choose elements in positions 1, 2 and 4(0-indexed))
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int LongestArithmeticProgression(const vector<int> &A) {
	int ret = 0;
	int len = (int)A.size();

	if (len < 2) return 1;

	for (int i = 0; i < len-2; i++)
	{
		for (int j = i + 1; j < len-1; j++)
		{
			int cnt = 2;
			int diff = A[j] - A[i];
			int temp = A[j];
			for (int k = j + 1; k < len; k++)
			{
				if ((A[k] - temp) == diff)
				{
					cnt++;
					temp = A[k];
				}
			}
			ret = max(ret, cnt);
		}
	}

	return ret;
}
#else
int LongestArithmeticProgression(const vector<int> &A) {
	int n = A.size();
	if (n < 3) return n;

	vector<vector<int> > dp(n, vector<int>(n, -1));
	map<int, int> pos;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = 2;
			int dif = A[j] - A[i];
			int need = 2 * A[i] - A[j];
			if (pos.count(need) == 0) continue;
			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);

		}
		pos[A[i]] = i;
	}

	int ans = 2;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
}
#endif