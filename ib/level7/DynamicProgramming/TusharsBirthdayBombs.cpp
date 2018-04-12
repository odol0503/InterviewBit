/*************************************************************************************************
Tushar's Birthday Bombs

It¡¯s Tushar¡¯s birthday today and he has N friends. Friends are numbered [0, 1, 2, ¡¦., N-1] 
and i-th friend have a positive strength S(i). Today being his birthday, his friends have 
planned to give him birthday bombs (kicks :P). Tushar¡¯s friends know Tushar¡¯s pain bearing 
limit and would hit accordingly.
If Tushar¡¯s resistance is denoted by R (>=0) then find the lexicographically smallest order of 
friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends
who kicks) doesn¡¯t exceed his resistance capacity and total no. of kicks hit are maximum. 
Also note that each friend can kick unlimited number of times (If a friend hits x times, 
his strength will be counted x times)

Note:
Answer format = Vector of indexes of friends in the order in which they will hit.
Answer should have the maximum no. of kicks that can be possibly hit. If two answer have 
the same no. of kicks, return one with the lexicographically smaller.
[a1, a2, ¡¦., am] is lexicographically smaller than [b1, b2, .., bm] 
if a1 < b1 or (a1 = b1 and a2 < b2) ¡¦ .
Input cases are such that the length of the answer does not exceed 100000.
Example:
R = 11, S = [6,8,5,4,7]
ans = [0,2]
Here, [2,3], [2,2] or [3,3] also give the maximum no. kicks.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

#ifdef OWN
void kick(int A, vector<pair<int, int>> &C, int pos, vector<int> &list, vector<int> &ret)
{
	for (int i = pos; i<(int)C.size(); i++)
	{
		if (A - C[i].second < 0)
		{
			if (list.size() > ret.size()) ret.assign(list.begin(), list.end());
			continue;
		}
		list.push_back(C[i].first);
		kick(A - C[i].second, C, i, list, ret);
		list.pop_back();
	}
}

vector<int> TusharsBirthdayBombs(int A, vector<int> &B) {
	vector<int> list;
	vector<int> ret;
	vector<pair<int, int>> C;

	for (int i = 0; i<(int)B.size(); i++)
	{
		if (B[i] <= A)
		{
			C.push_back({ i, B[i] });
		}
	}

	kick(A, C, 0, list, ret);
	int max_len = 0;
	int max_idx = -1;
	return ret;
}
#elif defined(OWN2)
vector<int> TusharsBirthdayBombs(int A, vector<int> &B) {
	vector<int> ret;
	int min_val = *min_element(B.begin(), B.end());

	for (int i = 0; i<B.size(); i++)
	{
		if (B[i] <= A && (A - B[i]) / min_val + 1 == A / min_val)
		{
			ret.push_back(i);
			A -= B[i];
			i--;
		}
	}

	return ret;
}
#else
#define F first
#define S second

vector<int> TusharsBirthdayBombs(int A, vector<int>& B) {
	// newB -> only those strengths which are useful
	// pair {i,j} -> i = original index of the person, j = strength
	vector<pair<int, int> > newB;

	int prev = INT_MAX;
	for (int i = 0; i<B.size(); i++) {
		if (B[i] < prev) {
			newB.push_back({ i, B[i] });
			prev = B[i];
		}
	}

	int n = newB.size();

	vector<int> ans;

	int R = A;
	int temp = newB[n - 1].second;   //smallest strength
	int i = 0;


	while (i<n) {
		// check if the current person can hit and if he can hit
		// would he change the answer or not
		if (R >= newB[i].S && (1 + (R - newB[i].S) / temp) == R / temp) {
			ans.push_back(newB[i].F);
			R -= newB[i].S;
		}
		else i++;
	}

	return ans;
}
#endif