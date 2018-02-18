/*************************************************************************************************
Kth Smallest Element in the Array

Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based )
NOTE
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.

Example:
A : [2 1 4 3 2]
k : 3

answer : 2
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define OWN

#ifdef OWN
int NumRange(vector<int> &A, int B, int C) {
	int i = 0;
	int j = 0;
	int sum = 0;
	int count = 0;

	while (i < A.size()) {
		sum = sum + A[j];
		if ((sum >= B) && (sum <= C)) {
			count++;
			j++;
		}
		else if (sum < B) {
			j++;
		}
		else if (sum > C) {
			i++;
			j = i;
			sum = 0;
		}
		if (j == A.size()) {
			sum = 0;
			i++;
			j = i;
		}
	}

	return count;
}
#else
int NumRange(vector<int> &A, int B, int C) {

}
#endif