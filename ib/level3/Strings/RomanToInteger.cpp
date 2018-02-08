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
	int r[256];
	r['I'] = 1;
	r['V'] = 5;
	r['X'] = 10;
	r['L'] = 50;
	r['C'] = 100;
	r['D'] = 500;
	r['M'] = 1000;

	int ans = 0;

	for (auto a : A)
	{
		if (a == r['M']) 
	}

	return 0;
}
#else
int RomanToInt(string A)
{

}
#endif