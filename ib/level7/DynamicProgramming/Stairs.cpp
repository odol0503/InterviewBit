/*************************************************************************************************
Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example :
Input : 3
Return : 3
Steps : [1 1 1], [1 2], [2 1]
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static void GetNum(int A, int &cnt)
{
	for (int i = 1; i<3; i++)
	{
		int C = A - i;
		if (C == 0)
		{
			cnt++;
			return;
		}
		if (C>0) GetNum(C, cnt);
	}
}

int ClimbStairs(int A) {
	int cnt = 0;
	GetNum(A, cnt);
	return cnt;
}
#else
int ClimbStairs(int n) {
	int ways[n + 1];
	ways[0] = 1;
	ways[1] = 1;
	for (int i = 2; i <= n; i++) ways[i] = ways[i - 1] + ways[i - 2];
	return ways[n];
}
#endif