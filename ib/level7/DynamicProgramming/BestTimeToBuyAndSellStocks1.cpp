/*************************************************************************************************
Best Time to Buy and Sell Stocks I

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :
Input : [1 2]
Return :  1
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int BestTimeToBuyAndSellStocks1(const vector<int> &A) {
	if (A.empty()) return 0;
	int ret = 0;
	int min_val = A[0];

	for (int i = 1; i<A.size(); i++)
	{
		ret = max(ret, A[i] - min_val);
		min_val = min(min_val, A[i]);
	}

	return ret;
}
#else
int BestTimeToBuyAndSellStocks3(const vector<int> &prices) {
	int sz = prices.size();
	int maxTillNow = -1000000000, maxGain = 0;
	for (int i = sz - 1; i >= 0; i--) {
		maxGain = max(maxGain, maxTillNow - prices[i]);
		maxTillNow = max(maxTillNow, prices[i]);
	}
	return maxGain;
}
#endif