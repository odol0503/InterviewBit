/*************************************************************************************************
Shortest common superstring

Given a set of strings. Find the length of smallest string which
has all the strings in the set as substring

Constraints:
1) 1 <= Number of strings <= 18
2) Length of any string in the set will not exceed 100.

Example:
Input: [¡°abcd¡±, ¡°cdef¡±, ¡°fgh¡±, ¡°de¡±]
Output: 8 (Shortest string: ¡°abcdefgh¡±)
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
void merge(string &A, string &B, int overLen, string &M, bool reverse)
{
	if (reverse)
	{
		if (A.size() <= overLen) M = B;
		M = B + A.substr(overLen, string::npos);
	}
	else
	{
		if (B.size() <= overLen) M = A;
		M = A + B.substr(overLen, string::npos);
	}
}

int getOverLen(string &A, string &B, string &M, bool &reverse)
{
	for (int i = 0; i<B.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j<A.size(); j++)
		{
			if (i + j == B.size() || B[i + j] != A[j]) break;
			cnt++;
			if (i + j == B.size() - 1 || j == A.size() - 1)
			{
				reverse = true;
				return cnt;
			}
		}
	}

	for (int i = 0; i<A.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j<B.size(); j++)
		{
			if (i + j == A.size() || A[i + j] != B[j]) break;
			cnt++;
			if (i + j == A.size() - 1 || j == B.size() - 1)
			{
				reverse = false;
				return cnt;
			}
		}
	}

	return 0;
}

int ShortestCommonSuperstring(vector<string> &A) {
	int num = (int)A.size();
	int x, y;
	string M;

	while (num > 1)
	{
		int maxLen = 0;
		bool rev = false;
		for (int i = 0; i < num; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				string str;
				bool reverse = false;
				int overLen = getOverLen(A[i], A[j], str, reverse);
				if (maxLen < overLen)
				{
					maxLen = overLen;
					x = i;
					y = j;
					rev = reverse;
				}
			}
		}

		if (maxLen == 0)
		{
			x = 0;
			y = 1;
		}

		merge(A[x], A[y], maxLen, M, rev);
		//cout << "(" << x << ", " << y << ", " << maxLen << ") "; 
		A[x] = M;
		//cout << M << "|";
		A.erase(A.begin() + y);
		num--;
	}

	//cout << A[0] << " ";
	return A[0].size();
}
#else
#define INF 1<<20
#define N 18

//Set the global variables
int targetMask;
int nonOverlapLen[N + 2][N + 2];
int dp[N][(1 << N) + 10];

// This can be done faster using KMP algorithm
//and some preprocessing
int combineString(vector<string> &words, int a, int b) {
	/*
	Let's say s1 = words[a] and s1 = words[b].

	If we append string s2 to the solution, then as string s1 is already
	added, we would need to add only the characters of string words[b] that are
	not overlapping with the solution.
	lenToADD = len(s2)-len(suffix of s1 which is also a prefix of s2);

	e.g.: s1 = "lara", s2 = "raghav"
	Now in the previous step, we added s1 to solution and let's say our solution
	at the time looks like "brilara" [made from strings "brila" and "lara"],
	if we add "raghav" to the solution, the only characters to be added are "ghav"
	and new solution = "brilaraghav"
	*/

	//Only 1 string in the mask 
	if (a == -1) {
		return words[b].size();
	}

	//Check if already calculated the ans
	if (nonOverlapLen[a][b] != -1) {
		return nonOverlapLen[a][b];
	}

	//Calculate the answer if not already calculated
	for (int i = 0; i<words[a].size(); ++i) {
		bool suffix = true;
		for (int j = 0; j<words[b].size() && i + j<words[a].size() && suffix; ++j) {
			if (words[a][i + j] != words[b][j]) suffix = false;
		}

		if (suffix) {
			int overlap = words[a].size() - i;
			nonOverlapLen[a][b] = words[b].size() - overlap;
			return nonOverlapLen[a][b];
		}
	}

	nonOverlapLen[a][b] = words[b].size();
	return nonOverlapLen[a][b];
}

//Main function to find the optimal solution
int findOptimal(vector<string> &words, int last, int mask) {
	//mask --> Set of strings that are considered for the solution.
	//last --> String that we added into the mask the last time
	//dp[i][mask] --> optimal answer for set of strings corresponding to mask(1's in mask) if the
	// last added string in mask is i-th string

	if (mask == targetMask) {
		//We considered all strings into the solution
		dp[last + 1][mask] = 0;
		return dp[last + 1][mask];
	}

	//Check if we solved this sub problem before
	if (dp[last + 1][mask] != -1) {
		return dp[last + 1][mask];
	}

	// Calculate the answer if not already calculated
	int ans = INF;

	for (int i = 0; i<words.size(); ++i) {
		//Check if i-th word is already considered or not
		if (!((mask >> i) & 1)) {
			ans = min(ans, findOptimal(words, i, mask | (1 << i)) + combineString(words, last, i));
		}
	}

	//Memoization step
	dp[last + 1][mask] = ans;

	return ans;
}

int ShortestCommonSuperstring(vector<string>& A) {
	int n = A.size();

	// Check the strings which are completely overlapping with some other string
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (i != j && A[i].find(A[j]) != string::npos) A[j] = "";
		}
	}

	//Make a new vector of only the strings which are not completely overlapping
	//with some other string

	vector<string> newA;
	for (int i = 0; i<n; i++) {
		if (A[i] != "") newA.push_back(A[i]);
	}

	//initialize the required arrays
	memset(nonOverlapLen, -1, sizeof(nonOverlapLen));
	memset(dp, -1, sizeof(dp));

	//Set the mask initially to all 0's
	int mask = 0;

	//Set the target mask
	targetMask = (1 << newA.size()) - 1;

	//Find the length of optimal solution
	int ans = findOptimal(newA, -1, mask);

	return ans;
}
#endif