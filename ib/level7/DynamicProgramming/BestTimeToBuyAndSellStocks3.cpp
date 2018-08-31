/*************************************************************************************************
Best Time to Buy and Sell Stocks III

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation :
Day 1 : Buy
Day 2 : Sell
Day 3 : Buy
Day 4 : Sell
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int BestTimeToBuyAndSellStocks3(const vector<int> &A) {
	int num = (int)A.size();
	if (num == 0) return 0;

	vector<int> dp(num);

	int min_val = A[0];
	for (int i = 1; i<num; i++)
	{
		dp[i] = max(dp[i - 1], A[i] - min_val);
		min_val = min(min_val, A[i]);
	}

	int max_val = A[num - 1];
	for (int i = num - 2; i >= 0; i--)
	{
		dp[i] = max(dp[i + 1], max_val - A[i] + dp[i]);
		max_val = max(max_val, A[i]);
	}

	return dp[0];
}
#else
int BestTimeToBuyAndSellStocks3(const vector<int> &prices) {
	// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
	// f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
	//          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
	// f[0, ii] = 0; 0 times transation makes 0 profit
	// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
	if (prices.size() <= 1) return 0;
	int K = 2; // number of max transation allowed
	int maxProf = 0;
	vector<vector<int> > f(K + 1, vector<int>(prices.size(), 0));
	for (int kk = 1; kk <= K; kk++) {
		int tmpMax = f[kk - 1][0] - prices[0];
		for (int ii = 1; ii < prices.size(); ii++) {
			f[kk][ii] = max(f[kk][ii - 1], prices[ii] + tmpMax);
			tmpMax = max(tmpMax, f[kk - 1][ii] - prices[ii]);
			maxProf = max(f[kk][ii], maxProf);
		}
	}

	return maxProf;
}
#endif