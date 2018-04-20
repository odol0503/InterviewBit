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

#define OWN

#ifdef OWN
int comp(string a, string b)
{
	return a + b > b + a;
}

string LargestNumber(const vector<int> &A)
{
	int num = (int)A.size();
	vector<string> str;
	string ret;

	for (int i = 0; i<num; i++)
	{
		if (A[i]) str.push_back(to_string(A[i]));
	}

	if (str.size() == 0) return "0";

	sort(str.begin(), str.end(), comp);

	for (auto s : str) ret += s;

	return ret;
}
#else
static bool compareNum(string a, string b) {
	return a + b > b + a;
}

string LargestNumber(const vector<int> &num) {
	string result;
	vector<string> str;
	for (int i = 0; i < num.size(); i++) {
		str.push_back(to_string(num[i]));
	}
	sort(str.begin(), str.end(), compareNum);
	for (int i = 0; i < str.size(); i++) {
		result += str[i];
	}

	int pos = 0;
	while (result[pos] == '0' && pos + 1 < result.size()) pos++;
	return result.substr(pos);
}
#endif