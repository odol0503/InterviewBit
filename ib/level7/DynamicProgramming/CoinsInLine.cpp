/*************************************************************************************************
Coins in a Line

There are N coins (Assume N is even) in a line. Two players take turns to take a coin 
from one of the ends of the line until there are no more coins left. 
The player with the larger amount of money wins. Assume that you go first.

Write a program which computes the maximum amount of money you can win.

Example:
suppose that there are 4 coins which have value
1 2 3 4
now you are first so you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so total of your money is 4 + 2 = 6
next/opposite person will get 1 + 3 = 4
so maximum amount of value you can get is 6
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int maxCoin(vector<int> &A, int start, int end, vector<vector<int>> &dp)
{
	if (start >= end) return 0;

	if (dp[start][end] != -1) return dp[start][end];

	int max_val = max((A[start] + min(maxCoin(A, start + 2, end, dp), maxCoin(A, start + 1, end - 1, dp))),
		A[end] + min(maxCoin(A, start + 1, end - 1, dp), maxCoin(A, start, end - 2, dp)));

	dp[start][end] = max_val;

	return max_val;
}

int CoinsInLine(vector<int> &A) {
	int start = 0;
	int end = (int)A.size() - 1;
	vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));

	return maxCoin(A, start, end, dp);
}
#else

#endif