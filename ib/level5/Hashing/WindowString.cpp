/*************************************************************************************************
Window String
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window 
in S should be at least N.

Example :
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window 
( with minimum start index ).
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
string MinWindow(string A, string B) {
	int len = (int)A.size();
	int num = (int)B.size();
	int min_len = INT_MAX;
	string ret;
	int Bmap[256];
	int Smap[256];

	for (int i = 0; i < 256; i++)
	{
		Bmap[i] = 0;
		Smap[i] = 0;
	}

	for (int i = 0; i < num; i++)
	{
		Bmap[B[i]]++;
	}
	
	for (int i = 0; i < len; i++)
	{

	}

	return ret;
}
#else

#endif