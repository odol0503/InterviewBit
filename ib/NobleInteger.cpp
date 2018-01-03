/*************************************************************************************************
Noble Integer

Given an integer array, find if an integer p exists in the array such that the number of 
integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

int NobleInteger(vector<int> &A)
{
	vector<int> ans(A);
	size_t len = ans.size();

	sort(ans.begin(), ans.end());

	for (size_t i = 0; i < len; i++)
	{
		if (ans[i] >= 0)
		{
			if ((i < len - 1 && ans[i] != ans[i + 1]) || i == len - 1)
			{
				if (ans[i] == len - (i + 1)) return 1;
			}
		}
	}

	return -1;
}
