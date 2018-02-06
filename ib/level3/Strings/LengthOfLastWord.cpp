/*************************************************************************************************
Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Given s = "Hello World",
return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions.
Make sure you only traverse the string once.
*************************************************************************************************/
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int LengthOfLastWord(const string A) 
{
	int len = (int)A.size();
	int cnt = 0;
	bool firstSP = true;
	
	for (int i = len - 1; i >= 0; i--)
	{
		if (A[i] != ' ')
		{
			firstSP = false;
			cnt++;
		}
		else if (firstSP == false && A[i] == ' ')
		{
			return cnt;
		}
	}

	return cnt;
}
#else
int LengthOfLastWord(const string A)
{
	int i = A.length() - 1;
	while (i >= 0 && A[i] == ' ') {
		i--;
	}
	int res = 0;
	while (i >= 0) {
		if (A[i] == ' ') {
			return res;
		}
		res++;
		i--;
	}
	return res;
}
#endif