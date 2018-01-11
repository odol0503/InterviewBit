/*************************************************************************************************
Maximum Consecutive Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Example :
Input : [1, 10, 5]
Output : 5
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit 
signed integer range.
You may also assume that the difference will not overflow.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int MaxConsecutiveGap(const vector<int> &A)
{
	int len = static_cast<int>(A.size());
	int b_num = len - 1;
	int max_value = *max_element(A.begin(), A.end());
	int min_value = *min_element(A.begin(), A.end());
	float gap = (max_value - min_value) / static_cast<float>(b_num);
	vector<int>max_buf(b_num, INT_MIN);
	vector<int>min_buf(b_num, INT_MAX);

	for (int i = 0; i < len; i++)
	{
		if (A[i] != min_value && A[i] != max_value)
		{
			int idx = static_cast<int>(floor((A[i] - min_value) / gap));
			max_buf[idx] = max(max_buf[idx], A[i]);
			min_buf[idx] = min(min_buf[idx], A[i]);
		}
	}

	int prev = min_value;
	int max_diff = 0;
	for (int i = 0; i < b_num; i++)
	{
		if (max_buf[i] == INT_MIN || min_buf[i] == INT_MAX) continue;
		int diff = min_buf[i] - prev;
		max_diff = max(max_diff, diff);
		prev = max_buf[i];
	}
	
	max_diff = max(max_diff, (max_value - prev));

	return max_diff;
}
#else
int MaxConsecutiveGap(const vector<int> &num) {
	if (num.empty() || num.size() < 2)
		return 0;
	int maxNum = *max_element(num.begin(), num.end());
	int minNum = *min_element(num.begin(), num.end());
	//average gap from minNum to maxNum.
	int gap = (maxNum - minNum - 1) / (num.size() - 1) + 1;

	//number of buckets = num.size() - 1
	vector<int> bucketsMin(num.size() - 1, INT_MAX);
	vector<int> bucketsMax(num.size() - 1, INT_MIN);
	//put into buckets
	for (int i = 0; i < num.size(); i++) {
		if (num[i] != maxNum && num[i] != minNum)
		{
			int buckInd = (num[i] - minNum) / gap;
			bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
			bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
		}
	}
	int maxGap = INT_MIN;
	int previous = minNum;
	for (int i = 0; i < num.size() - 1; i++) {
		if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
			continue;   //empty
						//i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
		maxGap = max(maxGap, bucketsMin[i] - previous);
		previous = bucketsMax[i];
	}
	maxGap = max(maxGap, maxNum - previous);
	return maxGap;
}
#endif