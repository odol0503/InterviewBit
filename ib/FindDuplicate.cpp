/*************************************************************************************************
Find Duplicate in Array

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear
time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:
[3 4 1 4 1]
Sample Output:
1
If there are multiple possible answers ( like in the sample case above ), output any one.
If there is no duplicate, output -1
*************************************************************************************************/
#include <vector>
#include <cmath>
using namespace std;

#define OWN

#ifdef OWN
int FindDuplicate(vector<int> &A)
{
	int len = static_cast<int>(A.size());
	int n = len - 1;
	int sr_num = static_cast<int>(ceil(sqrt(n)));
	vector<int>cnt(sr_num, 0);
	
	for (int i = 0; i < len; i++)
	{
		cnt[(A[i]-1) / sr_num]++;
	}

	for (int i = 0; i < sr_num; i++)
	{
		if (cnt[i] > sr_num || (i == n/sr_num && cnt[i] > n%sr_num))
		{
			for (int j = 0; j < cnt.size(); j++) cnt[j] = 0;
			for (int k = 0; k < len; k++)
			{
				if (sr_num*i < A[k] && A[k] <= sr_num*(i + 1))
				{
					cnt[(A[k]-1)% sr_num]++;
				}
			}
			
			for (int x = 0; x < cnt.size(); x++)
			{
				if (cnt[x] > 1)
				{
					return i*sr_num + x + 1;
				}
			}
		}
	}

	return -1;
}
#else
int FindDuplicate(vector<int> &V)
{
	if (V.size() <= 1) return -1;
	int valueRange = V.size() - 1; // 1 to N when the size is N+1.
	int range = sqrt(valueRange);
	if (range * range < valueRange) range++;
	vector<int> count(range + 1, 0);

	for (int i = 0; i < V.size(); i++) 
	{
		count[(V[i] - 1) / range]++;
	}

	int repeatingRange = -1;
	int numRanges = ((valueRange - 1) / range) + 1;
	for (int i = 0; i < numRanges && repeatingRange == -1; i++) 
	{
		if (i < numRanges - 1 || valueRange % range == 0) 
		{
			if (count[i] > range) repeatingRange = i;
		}
		else 
		{
			if (count[i] > valueRange % range) repeatingRange = i;
		}
	}
	if (repeatingRange == -1) return -1;
	for (int i = 0; i < count.size(); i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < V.size(); i++) 
	{
		if ((V[i] - 1) / range == repeatingRange) count[(V[i] - 1) % range]++;
	}
	for (int i = 0; i < range; i++) 
	{
		if (count[i] > 1) 
		{
			return repeatingRange * range + i + 1;
		}
	}
	return -1;
}
#endif