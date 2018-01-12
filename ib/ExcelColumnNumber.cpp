/*************************************************************************************************
Excel Column Number

Given a column title as appears in an Excel sheet, return its corresponding column number.
Example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

int TitleToNumber(string A) 
{
	int len = static_cast<int>(A.size());
	int sum = 0;
	int num = 'Z' - 'A' + 1;

	for (int i = 0; i < len; i++)
	{
		sum = (A[i] - 'A' + 1) + num * sum;
	}

	return sum;
}