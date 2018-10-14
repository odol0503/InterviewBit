/*************************************************************************************************
Unique Binary Search Trees II

Given A, how many structurally unique BST¡¯s (binary search trees) that store values 1...A?

Example :
Given A = 3, there are a total of 5 unique BST¡¯s.
    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int rec(int A)
{
	if (A <= 1) return 1;

	int cnt = 0;
	for (int i = 1; i <= A; i++)
	{
		cnt += (rec(i - 1) * rec(A - i));
	}

	return cnt;
}

int UniqueBinarySearchTrees2(int A) {
	return rec(A);
}
#else
int UniqueBinarySearchTrees2(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;

	vector<int> result(n + 1, 0);

	result[0] = 1;
	result[1] = 1;
	if (n < 2) {
		return result[n];
	}

	for (int i = 2; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			result[i] = result[i] + result[k - 1] * result[i - k];
		}
	}

	return result[n];
}
#endif