/*************************************************************************************************
Rearrange Array

Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:
Input : [1, 0]
Return : [0, 1]
Lets say N = size of the array. Then, following holds true :
All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
void RearrangeArray(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		int new_value = A[A[i]] % A.size();
		A[i] += new_value * A.size();
	}

	for (int j = 0; j < A.size(); j++)
	{
		A[j] /= A.size();
	}
}
#else
void RearrangeArray(vector<int> &Vec)
{
	int N = Vec.size();
	for (int i = 0; i < N; ++i) {
		Vec[i] = Vec[i] + (Vec[Vec[i]] % N) * N;
	}

	for (int i = 0; i < N; ++i) {
		Vec[i] = Vec[i] / N;
	}
}
#endif