/*************************************************************************************************
All Factors

Given a number N, find all factors of N.

Example:
N = 6
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

#define OWN

#ifdef OWN
vector<int> AllFactors(int A) {
	vector<int> ret;

	ret.push_back(1);
	if (A == 1) return ret;

	int limit = (int)sqrt(A);
	for (int i = 2; i <= limit; i++)
	{
		if (A%i == 0)
		{
			ret.push_back(i);
			if (i != A / i) ret.push_back(A / i);
		}
	}
	ret.push_back(A);
	sort(ret.begin(), ret.end());

	return ret;
}
#else
vector<int> allFactors(int n) {
	vector<int> ans;
	if (n < 2) {
		ans.push_back(n);
		return ans;
	}
	ans.push_back(1);
	ans.push_back(n);
	int upperLimit = (int)(sqrt(n));
	for (int i = 2; i <= upperLimit; i++) {
		if (i < n && n % i == 0) {
			ans.push_back(i);
			if (n / i != i) ans.push_back(n / i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
#endif