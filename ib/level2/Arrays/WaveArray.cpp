/*************************************************************************************************
Wave Array

Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example
Given [1, 2, 3, 4]
One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
So, in example case, you will return [2, 1, 4, 3]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

vector<int> WaveArray(vector<int> &A) 
{
	size_t len = A.size();
	vector<int> ans(A);

	sort(ans.begin(), ans.end());

	for (size_t i = 0; i < len - 1; i+=2)
	{
		int temp = ans[i + 1];
		ans[i + 1] = ans[i];
		ans[i] = temp;
	}

	return ans;
}
