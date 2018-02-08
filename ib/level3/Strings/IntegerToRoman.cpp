/*************************************************************************************************
Integer To Roman

Please Note:
Another question which belongs to the category of questions which are intentionally stated vaguely.
Expectation is that you will ask for correct clarification or you will state your assumptions 
before you start coding.

Given an integer, convert it to a roman numeral, and return a string corresponding to 
its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :
Input : 5
Return : "V"

Input : 14
Return : "XIV"
Note : This question has a lot of scope of clarification from the interviewer.
Please take a moment to think of all the needed clarifications and see the expected response 
using ¡°See Expected Output¡± For the purpose of this question, 
https://projecteuler.net/about=roman_numerals has very detailed explanations.
*************************************************************************************************/
#include <string>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
string IntToRoman(int A) 
{
	string ans;
	vector<string> list;
	int i = 0;
	while (A)
	{
		string a1, a5, a10;
		if (i == 0) a1 = "I", a5 = "V", a10 = "X";
		else if (i == 1) a1 = "X", a5 = "L", a10 = "C";
		else if (i == 2) a1 = "C", a5 = "D", a10 = "M";
		else if (i == 3) a1 = "M";

		int mod = A % 10;
		A /= 10;
		i++;

		string temp;
		if (mod < 4) for (int j = 0; j < mod; j++) temp += a1;
		else if (mod == 4) temp = a1 + a5;
		else if (mod < 9)
		{
			temp = a5;
			for (int j = 0; j < mod - 5; j++) temp += a1;
		}
		else if (mod == 9) temp = a1 + a10;

		list.push_back(temp);
	}
	reverse(list.begin(), list.end());

	for (auto l : list) ans += l;
	return ans;
}
#else
string IntToRoman(int num)
{
	// 1000, 2000, 3000
	string M[] = { "", "M", "MM", "MMM" };
	// 100, 200, 300, .. 900
	string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	// 10, 20, ... 90
	string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	// 1, 2, ... 9
	string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
}
#endif