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

#define OWN1

#ifdef OWN1 
static vector<int> Merge(vector<int> &A, vector<int> &B, int &cnt)
{
	vector<int> ret;
	int i = 0;
	int j = 0;

	while (i<(int)A.size() && j<(int)B.size())
	{
		if (A[i] <= B[j])
		{
			ret.push_back(A[i++]);
		}
		else
		{
			cnt += ((int)A.size() - i);
			ret.push_back(B[j++]);
		}
	}

	if (i == (int)A.size())
	{
		for (int j2 = j; j2<(int)B.size(); j2++) ret.push_back(B[j2]);
	}
	else
	{
		for (int i2 = i; i2<(int)A.size(); i2++) ret.push_back(A[i2]);
	}

	return ret;
}

static vector<int> MergeSort(vector<int> &A, int left, int right, int &cnt)
{
	if (left == right) return vector<int>({ A[left] });

	int mid = (left + right) / 2;
	vector<int> temp1 = MergeSort(A, left, mid, cnt);
	vector<int> temp2 = MergeSort(A, mid + 1, right, cnt);

	return Merge(temp1, temp2, cnt);
}

int Inversions(vector<int> &A) {
	int cnt = 0;
	int len = (int)A.size();
	MergeSort(A, 0, len - 1, cnt);
	return cnt;
}
#elif OWN2
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
#elif OWN3
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

#endif