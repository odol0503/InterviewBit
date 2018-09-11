/*************************************************************************************************
Tushar's Birthday Party

As it is Tushar¡¯s Birthday on March 1st, he decided to throw a party to all his friends 
at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish.
A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. 
Find the minimum cost such that all of Tushar¡¯s friends are satisfied (reached their eating capacity).

NOTE:
Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
2 4 6
2 1 3
2 5 3

Output:
14

Explanation:
First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  
Thus, total cost = (5+3)+(3*2)= 14
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
static int rec(int eat, const vector<int> &caps, const vector<int> &costs, vector<int> &dp)
{
	int num = (int)caps.size();
	int min_val = INT_MAX;

	if (eat <= 0) return 0;

	if (dp[eat - 1] != -1) return dp[eat - 1];

	for (int i = 0; i<num; i++)
	{
		int temp = eat - caps[i];
		if (temp >= 0)
		{
			min_val = min(min_val, costs[i] + rec(temp, caps, costs, dp));
		}
	}

	dp[eat - 1] = min_val;
	return min_val;
}

int TusharBirthdayParty(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int num = (int)A.size();
	int ret = 0;
	vector<int> dp(1001, -1);

	for (int i = 0; i<num; i++)
	{
		ret += rec(A[i], B, C, dp);
	}

	return ret;
}
#else
#define INF 10000000

int dp[1005][1005];

int TusharBirthdayParty(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	// vector of pair {dish_items, dish_cost}
	vector<pair<int, int> > dish;
	int n = C.size();
	for (int i = 0; i<n; i++)	dish.push_back(make_pair(B[i], C[i]));

	//maximum capacity among friends
	int m = -1;
	for (int i = 0; i<A.size(); i++) {
		m = max(m, A[i]);
	}

	// dp[highest capacity][no. of dishes]
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			//if capacity of friend is 0
			if (i == 0) dp[i][j] = 0;
			//if no dish is remaining to choose from
			else if (j == 0) dp[i][j] = INF;
			else {
				//if i-th person can eat jth dish
				if (i >= dish[j - 1].first) {
					//As one dish can be taken multiple times, we have used 
					//dp[ i-dish[j-1].first ][ j ] and not dp[ i-dish[j-1].first ][ j-1 ]. 

					dp[i][j] = min(dp[i][j - 1], dp[i - dish[j - 1].first][j] + dish[j - 1].second);
				}
				else dp[i][j] = dp[i][j - 1];
			}
		}
	}

	// Add for each friend independently
	int ans = 0;
	for (int i = 0; i<A.size(); i++) {
		ans += dp[A[i]][n];
	}

	return ans;
}
#endif