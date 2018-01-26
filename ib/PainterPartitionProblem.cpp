/*************************************************************************************************
Painter's Partition Problem

You have to paint N boards of length {A0, A1, A2, A3 ¡¦ AN-1}. There are K painters available 
and you are also given how much time a painter takes to paint 1 unit of board. 
You have to get this job done as soon as possible under the constraints that any painter will
only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
return minimum time to paint all boards % 10000003
Example

Input :
K : 2
T : 5
L : [1, 10]
Output : 50
*************************************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define OWN

#define MOD 10000003

#ifdef OWN
int Sum(vector<int> &l, int start, int end, int t)
{
	int ret = 0;
	for (int i = start; i <= end; i++)
	{
		ret = (ret + ((long long)l[i] * t) % MOD) % MOD;
	}

	return ret;
}

int Partition(vector<int> &l, int start, int k, int t)
{
	if (k == 1) return Sum(l, start, (int)l.size()-1, t)%MOD;
	if (start == (int)l.size() - 1) return (l[start]*t)%MOD;

	int min_value = INT_MAX;
	for (int i = 0; i < l.size() - 1 - start; i++)
	{
		min_value = min(min_value, max(Sum(l, start, start + i, t), Partition(l, start+i+1, k-1, t)));
	}
	return min_value%MOD;
}

int PainterPartionProblem(int A, int B, vector<int> &C) 
{
	return Partition(C, 0, A, B);
}
#else
bool isPossible(long long _Max, int K, vector<int> &Vec) {

	int _max_ele = *max_element(Vec.begin(), Vec.end());
	if (_max_ele > _Max)
		return false;

	long long Sum = 0;
	int cnt = 1;
	int N = Vec.size();

	for (int i = 0; i < N;) {
		if (Sum + ((long long)Vec[i]) > _Max) {
			Sum = 0;
			cnt++;
		}
		else {
			Sum += ((long long)Vec[i]);
			i++;
		}
	}

	if (cnt <= K)
		return true;
	return false;
}

int PainterPartionProblem(int K, int T, vector<int> &Vec) {
	int N = Vec.size();

	long long end = 0;
	long long start = 0;

	for (int i = 0; i < N; ++i) {
		end += Vec[i];
	}
	long long ans = INT_MAX;
	ans *= INT_MAX;
	while (start <= end) {
		long long mid = (start + end) / 2;
		if (isPossible(mid, K, Vec)) {
			ans = min(ans, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return (ans * (long long)T) % 10000003;
}
#endif