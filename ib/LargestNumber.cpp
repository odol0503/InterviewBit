/*************************************************************************************************
Largest NumberBookmark Suggest Edit
Given a list of non negative integers, arrange them such that they form the largest number.

For example :

Given[3, 30, 34, 5, 9], the largest formed number is 9534330.

Note : The result may be very large, so you need to return a string instead of an integer.
*************************************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a, string b)
{
	return a + b > b + a;
}

string LargestNumber(const vector<int> &A)
{
	vector<string> str;
	size_t len = A.size();

	for (size_t i = 0; i < len; i++)
	{
		str.push_back(to_string(A[i]));
	}

	sort(str.begin(), str.end(), compare);

	string ret;
	for (size_t i = 0; i < len; i++)
	{
		ret += str[i];
	}

	while (ret.size() > 1)
	{
		if (ret[0] == '0') ret.erase(ret.begin());
		else break;
	}

	return ret;
}