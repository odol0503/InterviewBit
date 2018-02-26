/*************************************************************************************************
Palindrome Partitioning

Given a string s, partition s such that every string of the partition is a palindrome.
Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
[
["a","a","b"]
["aa","b"],
]
Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND ¡¦ len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static bool IsParindrome(string A)
{
	int len = (int)A.size();
	if (len == 1) return true;
	for (int i = 0; i < len / 2; i++)
	{
		if (A[i] != A[len - i - 1]) return false;
	}

	return true;
}

static void Partition(string A, int pos, vector<vector<string>> &comb)
{
	int len = (int)A.size();
	if (len == pos) return;
	vector<string> sub;
	if (!comb.empty())
	{
		sub = comb.back();
		comb.pop_back();
	}

	for (int i = 0; i < len - pos; i++)
	{
		string str = A.substr(pos, i + 1);
		if (IsParindrome(str))
		{
			sub.push_back(str);
			comb.push_back(sub);
			Partition(A, pos + i + 1, comb);
			sub.pop_back();
		}
	}
}

vector<vector<string> > PalindromePartitioning(string A) {
	vector<vector<string>> comb;
	Partition(A, 0, comb);
	return comb;
}
#else
bool isPalindrome(string &str, int s, int e) {
	while (s < e) {
		if (str[s] != str[e])
			return false;
		s++;
		e--;
	}
	return true;
}

void partitionHelper(int i, vector<string> &current, string &s, vector<vector<string> > &ans) {

	if (i == s.length()) {
		// we reached the end of the string.
		// Valid sequence of strings found.
		ans.push_back(current);
		return;
	}

	for (int j = i; j < s.length(); ++j) {
		if (isPalindrome(s, i, j)) {
			current.push_back(s.substr(i, j - i + 1));
			partitionHelper(j + 1, current, s, ans);
			current.pop_back();
		}
	}
}

vector<vector<string> > PalindromePartitioning(string s) {
	vector<vector<string> > ans;
	vector<string> current;
	partitionHelper(0, current, s, ans);
	return ans;
}
#endif