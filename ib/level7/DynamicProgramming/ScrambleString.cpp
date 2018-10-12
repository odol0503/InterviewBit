/*************************************************************************************************
Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it 
to two non-empty substrings recursively.

Below is one possible representation of s1 = ¡°great¡±:

       great
      /    \
     gr    eat
    / \    /  \
   g   r  e   at
  / \
 a   t

To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node ¡°gr¡± and swap its two children, 
it produces a scrambled string ¡°rgeat¡±.
       rgeat
      /    \
     rg    eat
    / \    /  \
   r   g  e   at
  / \
 a   t

We say that ¡°rgeat¡± is a scrambled string of ¡°great¡±.
Similarly, if we continue to swap the children of nodes ¡°eat¡± and ¡°at¡±, 
it produces a scrambled string ¡°rgtae¡±.

       rgtae
      /    \
     rg    tae
    / \    /  \
   r   g  ta   e
  / \
 t   a

We say that ¡°rgtae¡± is a scrambled string of ¡°great¡±.

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
Return 0/1 for this problem.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
bool isAnagram(string &A, string &B)
{
	map<int, int> MA, MB;
	for (char a : A) MA[a]++;
	for (char b : B) MB[b]++;
	return MA == MB;
}

int rec(string A, string B, int a1, int a2, int b1, int b2, vector<vector<vector<vector<bool>>>> &dp)
{
	if (A == B) return 1;
	if (isAnagram(A, B) == false) return 0;

	if (dp[a1][a2][b1][b2] == false) return 0;

	int len = (int)A.size();
	for (int i = 1; i<len; i++)
	{
		if (rec(A.substr(0, i), B.substr(0, i), a1, a1 + i - 1, b1, b1 + i - 1, dp)
			&& rec(A.substr(i), B.substr(i), a1 + i, a2, b1 + i, b2, dp)) return 1;
		if (rec(A.substr(0, i), B.substr(len - i), a1, a1 + i - 1, b2 - i + 1, b2, dp)
			&& rec(A.substr(i), B.substr(0, len - i), a1 + i, a2, b1, b2 - i + 1, dp)) return 1;
	}

	dp[a1][a2][b1][b2] = false;

	return 0;
}

int ScrambleString(const string A, const string B) {
	if (A.size() != B.size()) return 0;
	int len = (int)A.size();
	vector<vector<vector<vector<bool>>>> dp(len, vector<vector<vector<bool>>>(len, vector<vector<bool>>(len, vector<bool>(len, true))));
	return rec(A, B, 0, A.size() - 1, 0, B.size() - 1, dp);
}
#elif defined(OTHER)
map<pair<string, string>, bool> store;
int solverec(const string &A, const string &B) {

	pair<string, string> pt = make_pair(A, B);
	if (store.find(pt) != store.end()) return store[pt];

	string temp1 = A;
	string temp2 = B;
	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end());
	// cout<<temp1<<" "<<temp2<<endl;

	if (temp1.compare(temp2) != 0) return false;

	// for less than 2 yield it true 
	if (temp1.size() <= 2) return true;

	for (int i = 1; i < A.length(); i++) {
		if (solverec(A.substr(0, i), B.substr(0, i))
			&& solverec(A.substr(i), B.substr(i))) return store[pt] = true;
		if (solverec(A.substr(0, i), B.substr(B.length() - i))
			&& solverec(A.substr(i), B.substr(0, B.length() - i))) return store[pt] = true;
	}
	return store[pt] = false;
}
int ScrambleString(const string A, const string B) {
	// if the string is of length 2 or less and are anagrams it'll 
	// always be true
	// if > 2 we'll have to check the root 
	store.clear();
	int n1 = A.length();
	int n2 = B.length();
	if (n1 != n2) return 0;
	return solverec(A, B);
}

#else
int ScrambleString(const string s1, const string s2) {
	int len = s1.size();
	vector<vector<vector<bool>>> dp(len+1, vector<vector<bool>>(len+1, vector<bool>(len+1, false)));

	for (int i = len - 1; i >= 0; i--) {
		for (int j = len - 1; j >= 0; j--) {
			dp[i][j][1] = (s1[i] == s2[j]);
			for (int l = 2; i + l <= len && j + l <= len; l++) {
				for (int n = 1; n < l; n++) {
					dp[i][j][l] = dp[i][j][l] | (dp[i][j][n] && dp[i + n][j + n][l - n]);
					dp[i][j][l] = dp[i][j][l] | (dp[i][j + l - n][n] && dp[i + n][j][l - n]);
				}
			}
		}
	}
	return dp[0][0][len];
}
#endif