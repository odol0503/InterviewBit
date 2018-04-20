/*************************************************************************************************
Noble Integer

Given an integer array, find if an integer p exists in the array such that the number of 
integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int NobleInteger(vector<int> &A)
{
	sort(A.begin(), A.end());

	for (int i = (int)A.size() - 1; i >= 0; i--)
	{
		int num = A.end() - upper_bound(A.begin(), A.end(), A[i]);
		if (A[i] == (int)num) return 1;
	}

	return -1;
}
#else
int NobleInteger(vector<int> &A) {
	sort(A.begin(), A.end());
	int size = A.size();
	for (int i = 0; i<size; i++) {
		while (i + 1<size && A[i] == A[i + 1])
			i++;
		if (A[i] == size - 1 - i)
			return 1;
	}
	return -1;
}
#endif
