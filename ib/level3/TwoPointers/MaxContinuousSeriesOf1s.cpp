/*************************************************************************************************
Max Continuous Series of 1s

You are given with an array of 1s and 0s. And you are given with an integer M,
which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input :
Array = {1 1 0 1 1 0 0 1 1 1 }
M = 1

Output :
[0, 1, 2, 3, 4]

If there are multiple possible solutions, return the sequence which has the minimum start index.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<int> MaxOne(vector<int> &A, int B) {
	int len = (int)A.size();
	int max_len = 0;
	vector<int> ret;
	vector<int> pos0;

	for (int i = 0; i < len; i++) if (A[i] == 0) pos0.push_back(i);

	if (pos0.size() == 0)
	{
		for (int i = 0; i < len; i++) ret.push_back(i);
		return ret;
	}

	for (int j = 0; j < B && j < (int)pos0.size(); j++) A[pos0[j]] = 1;

	for (int x = 0; x<(int)pos0.size(); x++)
	{
		for (int i = 0; i<len; i++)
		{
			int j = i;
			for (; j<len && A[j] == 1; j++);
			int temp = j - i;

			if (max_len < temp)
			{
				max_len = temp;
				ret.clear();
				for (int k = i; k < j; k++) ret.push_back(k);
			}
			i = j;
		}

		if (x + B < pos0.size() && B > 0)
		{
			A[pos0[x]] = 0;
			A[pos0[x + B]] = 1;
		}
	}

	return ret;
}
#else
vector<int> MaxOne(vector<int> &A, int B) {
	int N = Vec.size();
	int i = 0;
	int j = 0;
	int max_len = 0;
	int cnt = 0;
	vector<int> ans;

	int ans_start = 0;
	int ans_end = 0;

	while (i < N) {
		if (cnt + (Vec[i] == 0) > M) {
			int temp_len = (i - j); // length from j to i - 1. 
			if (temp_len > max_len) {
				max_len = temp_len;
				ans_start = j;
				ans_end = i - 1;
			}

			while (i >= j && cnt + (Vec[i] == 0) > M) {
				cnt -= (Vec[j] == 0);
				j++;
			}
			cnt += (Vec[i] == 0);
		}
		else {
			cnt += (Vec[i] == 0);
		}

		i++;
	}

	int temp_len = (i - j);
	if (temp_len > max_len) {
		temp_len = max_len;
		ans_start = j;
		ans_end = i - 1;
	}

	for (int ele = ans_start; ele <= ans_end; ele++) {
		ans.push_back(ele);
	}
	return ans;
}
#endif