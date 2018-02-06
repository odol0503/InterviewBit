/*************************************************************************************************
Minimum Characters required to make a String Palindromic

You are given a string. The only operation allowed is to insert characters in the beginning
of the string. How many minimum characters are needed to be inserted to make the string 
a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN6

#ifdef OWN
bool IsPalindrome(string A)
{
	string temp(A);
	reverse(temp.begin(), temp.end());
	if (A == temp) return true;
	return false;
}

int MinimumCharactersPalindromic(string A)
{
	if (IsPalindrome(A)) return 0;

	int cnt = 0;
	int len = (int)A.size();
	string temp(A);

	for (int i = len-1; i >= 0; i--)
	{
		temp.insert(temp.begin() + cnt, A[i]);
		cnt++;
		if (IsPalindrome(temp)) return cnt;
	}

	return -1;
}
#else
int MinimumCharactersPalindromic(string A)
{
	int start = 0, end = A.length() - 1;
	int temp_end = end;
	/*Idea is to find longest palindrome length starting from index 0 . Differece of
	this length from string length is the required value*/
	while (start <= temp_end)
	{
		if (A[start] == A[temp_end])
		{
			start++;
			temp_end--;
		}
		else
		{
			start = 0;
			temp_end = --end;
		}
	}
	return A.length() - (end + 1);
}
#endif