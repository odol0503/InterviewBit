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
#include <queue>
#include <set>
#include <functional>
#include <iostream>
using namespace std;

#define OWN

#ifdef OWN
vector<int> NMaxPairCombinations(vector<int> &A, vector<int> &B) {
	int len = (int)A.size();
	if (len == 1) return vector<int>({ A[0] + B[0] });

	int i = len - 1;
	int j = len - 1;

	priority_queue<pair<int, pair<int, int>>> pq;
	set<pair<int, int>> s;
	vector<int> ret;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	pq.push({ A[i] + B[j],{ i, j } });

	for (int k = 0; k<len; k++)
	{
		pair<int, pair<int, int>> temp = pq.top();
		pq.pop();

		ret.push_back(temp.first);

		i = temp.second.first;
		j = temp.second.second;

		if (s.count({ i, j - 1 }) == 0)
		{
			pq.push({ A[i] + B[j - 1],{ i, j - 1 } });
			s.insert({ i, j - 1 });
		}

		if (s.count({ i - 1, j }) == 0)
		{
			pq.push({ A[i - 1] + B[j],{ i - 1, j } });
			s.insert({ i - 1, j });
		}
	}

	return ret;
}
#else
vector<int> NMaxPairCombinations(vector<int> &A, vector<int> &B) {
	priority_queue<pair<int, pair<int, int> > > hp;
	set<pair<int, int> > S;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	hp.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));
	S.insert(make_pair(n - 1, n - 1));

	vector<int> ans;
	int k = n;
	while (k--) {
		pair<int, pair<int, int> > top = hp.top();
		hp.pop();
		ans.push_back(top.first);
		int L = top.second.first;
		int R = top.second.second;

		if (R>0 && L >= 0 && S.find(make_pair(L, R - 1)) == S.end()) {
			hp.push(make_pair(A[L] + B[R - 1], make_pair(L, R - 1)));
			S.insert(make_pair(L, R - 1));
		}
		if (R >= 0 && L>0 && S.find(make_pair(L - 1, R)) == S.end()) {
			hp.push(make_pair(A[L - 1] + B[R], make_pair(L - 1, R)));
			S.insert(make_pair(L - 1, R));
		}
	}
	return ans;
}
#endif