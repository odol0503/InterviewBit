/*************************************************************************************************
Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.
For example,
given strings "12", "10", your answer should be ¡°120¡±.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ).
We will retroactively disqualify such submissions and the submissions will incur penalties.
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
static string Sum(vector<string> l)
{
	int num = (int)l.size();
	string ret;

	for (int i = 0; i < num; i++)
	{
		int j = (int)l[i].size() - 1;
		int k = (int)ret.size() - 1;
		int carry = 0;
		string str;
		while (j >= 0 || k >= 0)
		{
			int temp = carry;
			if (k >= 0) temp += ret[k] - '0';
			if (j >= 0) temp += l[i][j] - '0';
			str.push_back(temp % 10 + '0');
			carry = temp / 10;
			k--; j--;
		}
		if (carry) str.push_back(carry + '0');
		reverse(str.begin(), str.end());
		ret = str;
	}
	return ret;
}

string MultiplyStrings(string A, string B) {
	string ret;
	vector<string> list(A.size(), "");
	
	for (int i = (int)A.size() - 1; i>=0; i--)
	{
		int carry = 0;
		for (int k = (int)A.size() - 1; k > i; k--) list[i].push_back('0');
		for (int j = (int)B.size() - 1; j >= 0; j--)
		{
			int temp = (A[i] - '0') * (B[j] - '0') + carry;
			list[i].push_back(temp % 10 + '0');
			carry = temp / 10;
		}
		if (carry) list[i].push_back(carry + '0');
		reverse(list[i].begin(), list[i].end());
	}

	ret = Sum(list);

	while (ret[0] == '0') ret.erase(ret.begin());
	if (ret.empty()) ret = "0";

	return ret;
}
#else
string MultiplyStrings(string num1, string num2) {
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0)     return "0";

	// will keep the result number in vector in reverse order
	std::vector<int> result(n1 + n2, 0);

	int i_n1 = 0; // index by num1
	int i_n2 = 0; // index by num2

				  // go from right to left by num1
	for (int i = n1 - 1; i >= 0; i--) {
		int carrier = 0;
		int n1 = num1[i] - '0';
		i_n2 = 0;

		// go from right to left by num2
		for (int j = n2 - 1; j >= 0; j--) {
			int n2 = num2[j] - '0';

			int sum = n1 * n2 + result[i_n1 + i_n2] + carrier;
			carrier = sum / 10;
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carrier in next cell
		if (carrier > 0)
			result[i_n1 + i_n2] += carrier;

		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0) i--;

	// if all were '0's - means either both or one of num1 or num2 were '0'
	if (i == -1) return "0";

	// generate the result string
	std::string s = "";
	while (i >= 0) s += std::to_string(result[i--]);

	return s;
}
#endif