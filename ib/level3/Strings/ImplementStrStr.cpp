/*************************************************************************************************
Implement StrStr

Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely.
Expectation is that you will ask for correct clarification or you will state your assumptions 
before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part 
of haystack.

NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int StrStr(const string &A, const string &B) {
	int len1 = (int)A.size();
	int len2 = (int)B.size();
	
	if (len1 == 0 || len2 == 0) return -1;

	for (int i = 0; i < len1; i++)
	{
		if (len2 > len1 - i) return -1;

		for (int j = 0; j < len2; j++)
		{
			if (A[i + j] != B[j]) break;
			if (j == len2-1) return i;
		}
	}

	return -1;
}
#else
int StrStr(const string &haystack, const string &needle) {
	if (needle[0] == '\0') return 0;
	for (int i = 0; haystack[i] != '\0'; i++) {
		bool isMatched = true;
		for (int j = 0; needle[j] != '\0'; j++) {
			// If remaining haystack length is less than needle's length, 
			// we know needle is not present in haystack.
			if (haystack[i + j] == 0) return -1;
			if (haystack[i + j] != needle[j]) {
				isMatched = false;
				break;
			}
		}
		if (isMatched) return i; // Match found
	}
	return -1;
}
#endif