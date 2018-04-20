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

#define OWN

#ifdef OWN
vector<int> WaveArray(vector<int> &A) 
{
	sort(A.begin(), A.end());
	int len = (int)A.size();
	for (int i = 0; i<(len&(~0x01)); i += 2)
	{
		swap(A[i], A[i + 1]);
	}

	return A;
}
#else
vector<int> WaveArray(vector<int> Vec) {
	sort(Vec.begin(), Vec.end());
	int N = Vec.size();
	for (int i = 0; i < N - 1; i += 2) {
		swap(Vec[i], Vec[i + 1]);
	}
	return Vec;
}
#endif
