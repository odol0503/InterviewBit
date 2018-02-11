/*************************************************************************************************
Zigzag String

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.
*************************************************************************************************/
#include <string>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
string ZigzagString(string A, int B) {
	if (B <= 1) return A;

	int len = (int)A.size();
	vector<string> temp(B, "");
	string ret;
	int row = 0;

	for (int i = 0; i < len; i++)
	{
		temp[row] += A[i];
		if (i / (B - 1) & 0x01) row--;
		else row++;
	}

	for (int i = 0; i < B; i++)
	{
		ret += temp[i];
	}

	return ret;
}
#else
string ZigzagString(string s, int nRows) {
	if (nRows <= 1)
		return s;

	const int len = (int)s.length();
	string *str = new string[nRows];

	int row = 0, step = 1;
	for (int i = 0; i < len; ++i)
	{
		str[row].push_back(s[i]);

		if (row == 0)
			step = 1;
		else if (row == nRows - 1)
			step = -1;

		row += step;
	}

	s.clear();
	for (int j = 0; j < nRows; ++j)
	{
		s.append(str[j]);
	}

	return s;
}
#endif