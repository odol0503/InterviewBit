/*************************************************************************************************
Prime Numbers

Given a number N, find all prime numbers upto N ( N included ).

Example:
if N = 7,
all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

#define OWN

#ifdef OWN
vector<int> PrimeNumbers(int A) {
	vector<int> ret;
	vector<bool> board(A - 1, true);

	for (int i = 2; i<A; i++)
	{
		if (board[i]) {
			ret.push_back(i);
			for (int j = i * 2; j<A; j += i) board[j] = false;
		}
	}

	return ret;
}
#else
vector<int> PrimeNumbers(int n) {
	vector<int> ans;
	if (n < 2) {
		return ans;
	}

	int arr[n + 1];
	memset(arr, 0, sizeof(arr));
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			ans.push_back(i);
			for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
		}
	}
	return ans;
}
#endif


