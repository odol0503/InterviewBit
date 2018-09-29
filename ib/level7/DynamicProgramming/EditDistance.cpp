/*************************************************************************************************
Edit Distance

Given two words A and B, find the minimum number of steps required to convert A to B. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example :
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
static int minNum(string A, int idxA, string B, int idxB, vector<vector<int>> &dp)
{
	if (idxA == A.size() && idxB == B.size()) return 0;

	if (A[idxA] == B[idxB]) return minNum(A, idxA + 1, B, idxB + 1, dp);

	if (dp[idxA][idxB]) return dp[idxA][idxB];

	int val1 = INT_MAX;
	int val2 = INT_MAX;
	int val3 = INT_MAX;

	if (idxB < B.size()) val1 = minNum(A, idxA, B, idxB + 1, dp); //insert
	if (idxA < A.size()) val2 = minNum(A, idxA + 1, B, idxB, dp); //delete;
	if (idxA < A.size() && idxB < B.size()) val3 = minNum(A, idxA + 1, B, idxB + 1, dp); // replace;

	dp[idxA][idxB] = min(val1, min(val2, val3)) + 1;
	return dp[idxA][idxB];
}

int EditDistance(string A, string B) {
	vector<vector<int>> dp(A.size() + 10, vector<int>(B.size() + 10, 0));
	return minNum(A, 0, B, 0, dp);
}
#else
int EditDistance(string word1, string word2) {
	// DP talbe, i is the position in word1, and j is the position in word2
	vector<vector<int>> distance(word1.length() + 1, vector<int>(word2.length() + 1, 0));

	// when i or j=0 means empty string, the distance is the length of another string
	for (int i = 0; i < distance.size(); i++) {
		for (int j = 0; j < distance[0].size(); j++) {
			if (i == 0)
				distance[i][j] = j;
			else if (j == 0)
				distance[i][j] = i;
		}
	}

	// if word1[i] == word2[j], then the distance of i and j is the previous i and j
	// otherwise we either replace, insert or delete a char
	// when insert a char to word1 it means we are trying to match word1 at i-1 to word2 at j
	// when delete a char from word1 it equals to insert a char to word2, which
	// means we are trying to match word1 at i to word2 at j-1
	// when replace a char to word1, then we add one step to previous i and j
	for (int i = 1; i < distance.size(); i++) {
		for (int j = 1; j < distance[0].size(); j++) {
			if (word1[i - 1] == word2[j - 1])
				distance[i][j] = distance[i - 1][j - 1];
			else
				distance[i][j] = 1 + min(distance[i - 1][j - 1], min(distance[i - 1][j], distance[i][j - 1]));
		}
	}

	return distance[word1.length()][word2.length()];
}
#endif