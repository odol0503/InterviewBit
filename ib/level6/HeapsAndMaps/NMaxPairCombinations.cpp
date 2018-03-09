/*************************************************************************************************
N max pair combinations

Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6),
9    (3+6),
9    (4+5),
8    (2+6)
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <functional>
#include <iostream>
using namespace std;

#define OWN

#ifdef OWN
vector<int> NMaxPairCombinations(vector<int> &A, vector<int> &B) {
	int len = (int)A.size();
	if (len == 1) return vector<int>(A[0] + B[0]);
	
	vector<int> sum;
	vector<int> ret;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int maxA = A[len-1];
	int maxB = B[len-1];
	
	int i = len - 2;
	int j = len - 2;

	ret.push_back(maxA + maxB);

	for (int n = 1; n<len; n++)
	{
		if (maxA + maxB == A[i] + B[i])
		{
			ret.push_back(maxA + maxB);
			ret.push_back(maxA + maxB);
			ret.push_back(maxA + maxB);
			n+=3;
			i--;
			j--;
		}
		else if (maxA + B[j] > A[i] + maxB)
		{
			ret.push_back(maxA + B[j]);
			j--;
		}
		else
		{
			ret.push_back(A[i] + maxB);
			i--;
		}
	}

	return ret;
}
#else
//Sort both the arrays in ascending order.
//Let us take priority queue(heap).
//First max element is going to be the sum of the last two elements of array A and B i.e. (A[n - 1] + B[n - 1]).
//Insert that in heap with indices of both array i.e(n - 1, n - 1).
//Start popping from heap(n - iterations).
//And insert the sum(A[L - 1] + A[R]) and (A[L] + B[R - 1]).
//Take care that repeating indices should not be there in the heap(use map for that).
#endif