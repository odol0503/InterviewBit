/*************************************************************************************************
Excel Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*************************************************************************************************/
#include <string>
#include <algorithm>
using namespace std;

string ConvertToTitle(int A)
{
	int num = 'Z' - 'A' + 1;
	int mod = 0;
	string ret;

	while (A > 0)
	{
		mod = (A-1) % num;
		A = (A-1) / num;
		ret.push_back(mod + 'A');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
