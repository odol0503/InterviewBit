/*************************************************************************************************
Best Time to Buy and Sell Stocks II

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

Example :

Input : [1 2 3]
Return : 2
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int BestTimeToBuyAndSellStocks2(const vector<int> &A) {
	if (A.empty()) return 0;

	int profit = 0;
	int min_val = A[0];
	for (int i = 1; i<A.size(); i++)
	{
		if (A[i - 1] <= A[i])
		{
			if (i == A.size() - 1) profit += A[i] - min_val;
		}
		else
		{
			profit += A[i - 1] - min_val;
			min_val = INT_MAX;
		}
		min_val = min(min_val, A[i]);
	}

	return profit;
}
#else
int BestTimeToBuyAndSellStocks2(const vector<int> &prices) {
	int total = 0, sz = prices.size();
	for (int i = 0; i < sz - 1; i++) {
		if (prices[i + 1] > prices[i]) total += prices[i + 1] - prices[i];
	}
	return total;
}
#endif