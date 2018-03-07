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

	for (int i = 0; i < len-1; i++)
	{
		float g = (A[i] - A[i+1]) / (float)(B[i] - B[i + 1]);
		int b = B[i] - g * A[i];
		int cnt = 2;

		for (int j = i + 2; j < len; j++)
		{
			if (B[j] == g * A[j] + b) cnt++;
		}

		max_cnt = max(max_cnt, cnt);
	}

	return max_cnt;
}
#else

#endif