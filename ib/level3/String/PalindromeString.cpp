/*************************************************************************************************
Palindrome String

Given a string, determine if it is a palindrome, considering only alphanumeric characters and 
ignoring cases.

Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*************************************************************************************************/
#include <algorithm>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int PalindromeString(string A)
{
	int len = (int)A.size();
	string temp;
	string temp2;

	for (int i = 0; i < len; i++)
	{
		if (!isalnum(A[i])) continue;
		if (A[i] >= 'a' && A[i] <= 'z') temp.push_back(A[i] - 'a' + 'A');
		else temp.push_back(A[i]);
	}

	temp2 = temp;
	reverse(temp2.begin(), temp2.end());

	if (temp == temp2) return 1;
	return 0;
}
#else
int PalindromeString(string A)
{
	int i = 0, j = (int)s.size() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i])) i++;
		while (i < j && !isalnum(s[j])) j--;
		if (toupper(s[i]) != toupper(s[j])) return false;
		i++;
		j--;
	}
	return true;
}
#endif