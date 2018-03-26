/*************************************************************************************************
Ways to Decode

A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
using namespace std;

#define OWN

#ifdef OWN
static bool IsValid(string A, int &ret)
{
	int len = (int)A.size();

	if (A[0] > '2' && A[1] == '0')
	{
		return false;
	}
	else if (A[0] <= '2' && A[0] != '0' && A[1] <= '6' && A[1] != '0')
	{
		ret += 2;
	}
	else if (A[0] == '0')
	{
		return true;
	}

	return true;
}

int WaysToDecode(string A) {
	int len = (int)A.size();
	int ret = 0;

	if (len == 0 || A[0] == '0') return 0;
	if (len == 1) return 1;

	int i = 0;
	for (; i<len - 1; i++)
	{
		if (!IsValid({ A[i], A[i + 1] }, ret)) return 0;
	}

	if (ret == 0) ret++;

	return ret;
}
#else
int solution[100001];

bool isValid(char ch) {
	return (isdigit(ch) && ch > '0');
}

int ways(string &s, int startIndex) {
	if (startIndex == s.length()) return 1;
	if (!isValid(s[startIndex])) return 0;

	// memoize
	if (solution[startIndex] != -1) return solution[startIndex];

	int answer = 0;
	// 1 digit
	answer += ways(s, startIndex + 1);
	// 2 digit
	if (startIndex < s.length() - 1 && isdigit(s[startIndex + 1]) && ((s[startIndex] - '0') * 10 + s[startIndex + 1] - '0') <= 26) {
		answer += ways(s, startIndex + 2);
	}

	return solution[startIndex] = answer;
}

int WaysToDecode(string s) {
	memset(solution, -1, s.length() * sizeof(int));
	if (s.length() == 0) return 0;
	return ways(s, 0);
}
#endif