/*************************************************************************************************
INVERSIONS

Given an array A, count the number of inversions in the array.
Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j

Example:
A : [2, 4, 1, 3, 5]
Output : 3
as the 3 inversions are (2, 1), (4, 1), (4, 3).
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
using namespace std;

#define OWN

#ifdef OWN
int Inversions(vector<int> &A) {
	int ret = 0;
	multiset<int> S;

	if (A.size() == 0) return 0;

	S.insert(A[0]);

	for (int i = 1; i<(int)A.size(); i++)
	{
		S.insert(A[i]);
		auto it = S.upper_bound(A[i]);
		ret += (int)distance(it, S.end());
	}

	return ret;
}
#else
int Inversions(vector<int> &A) {
	int ret = 0;
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> P;
	vector<int> idx;

	for (int i = 0; i<(int)A.size(); i++)
	{
		P.push({ A[i], i });
	}

	while (!P.empty())
	{
		int cnt = 0;
		pair<int, int> val = P.top();
		for (auto i : idx)
		{
			if (i < val.second) cnt++;
		}
		ret += (val.second - cnt);
		idx.push_back(val.second);
		P.pop();
	}

	return ret;
}
#endif