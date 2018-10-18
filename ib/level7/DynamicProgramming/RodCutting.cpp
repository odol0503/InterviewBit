/*************************************************************************************************
Rod Cutting

There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. 
Now, there are M weak points on this rod denoted by positive integer values(all less than N)
A1, A2, ¡¦, AM. You have to cut rod at all these weak points. 
You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. 
Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. 
Return an array denoting the sequence in which you will make cuts. 
If two different sequences of cuts give same cost, return the lexicographically smallest.

Notes:

Sequence a1, a2 ,¡¦, an is lexicographically smaller than b1, b2 ,¡¦, bm, if 
and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be upto 109.
For example,
N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13

So, we return [2, 1, 5].
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int rec(int A, vector<int> &B, int start, int end, vector<int> &arr, map<pair<int, int>, pair<int, vector<int>>> &dp)
{
	if (dp.count({ start, end }))
	{
		for (int a : dp[{start, end}].second) arr.push_back(a);
		return dp[{start, end}].first;
	}

	int min_val = INT_MAX;
	for (int b : B)
	{
		if (start < b && b < end)
		{
			vector<int> temp;
			vector<int> arr1;
			vector<int> arr2;
			int val = end - start + rec(A, B, start, b, arr1, dp) + rec(A, B, b, end, arr2, dp);
			if (min_val > val)
			{
				min_val = val;
				temp.push_back(b);
				for (int a : arr1) temp.push_back(a);
				for (int a : arr2) temp.push_back(a);
				arr = temp;
			}
		}
	}

	if (min_val == INT_MAX) min_val = 0;

	dp[{start, end}] = { min_val, arr };
	return min_val;
}

vector<int> RodCutting(int A, vector<int> B) {
	vector<int> arr;
	map<pair<int, int>, pair<int, vector<int>>> dp;
	rec(A, B, 0, A, arr, dp);
	return arr;
}

#else
typedef long long LL;

//ans vector
vector<int> ans;

//cuts vector
vector<int> ar;

//dp array
vector<vector<LL> > dp;

//parent array
vector<vector<int> > parent;

//solve for dp(l, r)
LL rec(int l, int r) {
	//base case
	if (l + 1 >= r)return 0;

	//for memoisation
	LL &ret = dp[l][r];

	if (ret != -1)return ret;


	ret = LLONG_MAX;
	int bestind;    //stores the best index

	for (int i = l + 1; i<r; i++) {
		//recurrence
		LL p = rec(l, i) + rec(i, r) + (LL)ar[r] - (LL)ar[l];

		//update best
		//note that we choose lexicographically smallest index
		//if multiple give same cost
		if (p<ret) {
			ret = p;
			bestind = i;
		}
	}

	//store parent of (l, r)
	parent[l][r] = bestind;

	return ret;
}

//function for building solution
void back(int l, int r) {
	//base case
	if (l + 1 >= r)return;

	//first choose parent of (l,r)
	ans.push_back(ar[parent[l][r]]);

	//call back recursively for two new segments
	//calling left segment first because we want lexicographically smallest
	back(l, parent[l][r]);
	back(parent[l][r], r);
}

vector<int> RodCutting(int A, vector<int> B) {
	//insert A and 0
	B.push_back(A);
	B.insert(B.begin(), 0);


	int n = B.size();
	ar.clear();
	for (int i = 0; i<n; i++)
		ar.push_back(B[i]);

	//initialise dp array
	dp.resize(n);
	parent.resize(n);
	ans.clear();
	for (int i = 0; i<n; i++) {
		dp[i].resize(n);
		parent[i].resize(n);
		for (int j = 0; j<n; j++)
			dp[i][j] = -1;
	}

	//call recurrence
	LL best = rec(0, n - 1);

	//build solution
	back(0, n - 1);

	return ans;
}

#endif