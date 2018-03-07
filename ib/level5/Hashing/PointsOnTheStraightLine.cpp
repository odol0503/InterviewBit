/*************************************************************************************************
Points on the Straight Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :
(1, 1)
(2, 2)
Sample Output :
2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
int MaxPoints(vector<int> &A, vector<int> &B) {
	int len = (int)A.size();
	int max_cnt = 0;

	if (A.size() <= 1) return (int)A.size();

	for (int i = 0; i < len - 1; i++)
	{
		map<double, int> M;
		int same_cnt = 1;
		int local_max = 0;

		for (int j = i + 1; j < len; j++)
		{
			if (B[i] - B[j] == 0 && A[i] - A[j] == 0)
			{
				same_cnt++;
			}
			else if (B[i] - B[j] == 0)
			{
				if (M.count(0) == 0) M[0] = 1;
				else M[0]++;
			}
			else if (A[i] - A[j] == 0)
			{
				if (M.count(DBL_MAX) == 0) M[DBL_MAX] = 1;
				else M[DBL_MAX]++;
			}
			else
			{
				double a = (B[i] - B[j]) / (double)(A[i] - A[j]);
				if (M.count(a) == 0) M[a] = 1;
				else M[a]++;
			}
		}
		
		for (auto it = M.begin(); it != M.end(); it++)
		{
			local_max = max(local_max, it->second);
		}

		max_cnt = max(max_cnt, local_max + same_cnt);
	}

	return max_cnt;
}
#else
int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a < 0) return gcd(-1 * a, b);
	if (b < 0) return gcd(a, -1 * b);
	if (a > b) return gcd(b, a);
	return gcd(b%a, a);
		}

int MaxPoints(vector<int> &X, vector<int> &Y) {
	map<pair<int, int>, int> M;
	int ans = 0;
	for (int i = 0; i < X.size(); i++) {
		M.clear();
		int same = 1, curMax = 0;
		// Try to find all the lines with same slope with points[i] as one end. 
		// Points with the same slope lie on the same line. 
		// We need to make sure we handle divisions by zero in cases like these. 
		// We also need to take care of overlapping points. 
		for (int j = i + 1; j < X.size(); j++) {
			int xdiff = X[i] - X[j];
			int ydiff = Y[i] - Y[j];
			if (xdiff == 0 && ydiff == 0) {
				// Same points 
				same++;
				continue;
			}
			if (xdiff < 0) {
				xdiff *= -1;
				ydiff *= -1;
			}
			int g = gcd(xdiff, ydiff);
			M[make_pair(xdiff / g, ydiff / g)]++;
			curMax = max(curMax, M[make_pair(xdiff / g, ydiff / g)]);
		}
		curMax += same;
		ans = max(ans, curMax);
	}
	return ans;
}
#endif