/*************************************************************************************************
Counting Triangles

You are given an array of N non-negative integers, A0, A1 ,¡¦, AN-1.
Considering each array element Ai as the edge length of some line segment, 
count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. 
Order of choosing the edge lengths doesn¡¯t matter. 
Any triangle formed should have a positive area.

Return answer modulo 10^9 + 7.

For example,
A = [1, 1, 1, 2, 2]
Return: 4
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007LL

int CountingTriangles(vector<int> &A) {
	int len = (int)A.size();
	long long ans = 0;

	sort(A.begin(), A.end());

	for (int i = 0; i <len - 2; i++)
	{
		int k = i + 2;
		for (int j = i + 1; j < len - 1; j++)
		{
			while (k < len && A[i] + A[j] > A[k]) k++;
			ans = (ans + (k - j - 1)) % MOD;
		}
	}
	return (int)ans;
}
#else
int CountingTriangles(vector<int> &A) {
	int N = A.size();
	if (N <= 2) return 0;
	sort(A.begin(), A.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {    // first side
		int k = i + 2;
		for (int j = i + 1; j < N; j++) {    // second side
			for (; (k < N) && (A[i] + A[j] > A[k]); k++);
			ans = ans + (k - 1 - j);    // all indices of between j to k are possible
			if (ans >= 1000000007) ans = ans % 1000000007;
		}
	}
	return ans;
}
//First we sort the array of side lengths.So since Ai < Aj < Ak where i < j < k, 
//therefore it is sufficient to check Ai + Aj > Ak to prove they form a triangle.
//
//Thus for every i and j, we can find the maximum value of k such that the triangle inequality holds.
//Also we can also prove that for every such index i, we only have to 
//increase the value of the k(satisfying the above condition) for every iteration of j from i + 1 to n.
//Therefore, we get a O(n2) solution(Proof of this is left to the reader).
#endif