/*************************************************************************************************
Roman To Integer

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
Read more details about roman numerals at Roman Numeric System

Example :
Input : "XIV"
Return : 14
Input : "XX"
Output : 20

I	1
V	5
X	10
L	50
C	100
D	500
M	1000
*************************************************************************************************/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#define OWN

#ifdef OWN
int RomanToInt(string A) 
{
	int len = (int)A.size();
	int ans = 0;

	for (int i=0; i<len; i++)
	{
		switch (A[i])
		{
		case 'M':
			ans += 1000;
			break;
		case 'D':
			ans += 500;
			break;
		case 'C':
			if (i < len - 1 && A[i + 1] == 'D' || A[i + 1] == 'M') ans -= 100;
			else ans += 100;
			break;
		case 'L':
			ans += 50;
			break;
		case 'X':
			if (i < len - 1 && A[i + 1] == 'L' || A[i + 1] == 'C') ans -= 10;
			else ans += 10;
			break;
		case 'V':
			ans += 5;
			break;
		case 'I':
			if (i < len - 1 && A[i + 1] == 'V' || A[i+1] == 'X') ans -= 1;
			else ans += 1;
			break;
		}

	}

	return ans;
}
#else
int romanCharToInt(char c) {
	switch (c) {
	case 'I':   return 1;
	case 'V':   return 5;
	case 'X':   return 10;
	case 'L':   return 50;
	case 'C':   return 100;
	case 'D':   return 500;
	case 'M':   return 1000;
	default:    return 0;
	}
}

int RomanToInt(string s)
{
	int num = 0;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		// Does lesser value precede higher value ? 
		if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
			num -= romanCharToInt(s[i]);
		}
		else {
			num += romanCharToInt(s[i]);
		}
	}
	return num;
}
#endif