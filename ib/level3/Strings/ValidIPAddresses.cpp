/*************************************************************************************************
Valid Ip Addresses

Given a string containing only digits, restore it by returning all possible 
valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. 
The numbers cannot be 0 prefixed unless they are 0.

Example:

Given ¡°25525511135¡±,

return [¡°255.255.11.135¡±, ¡°255.255.111.35¡±]. (Make sure the returned strings are sorted in order)
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
bool ValidNum(string A)
{
	int len = (int)A.size();
	if (len > 1 && A[0] < '1' || '9' < A[0]) return false;
	int num = stoi(A);
	if (0 <= num && num <= 255) return true;
	return false;
}

vector<string> RestoreIpAddresses(string A) {
	int len = (int)A.size();
	vector<string> ret;
	
	if (len < 4 || len > 12) return ret;

	for (int i = 0; i < 3 && i<len-2; i++)
	{
		if (!ValidNum(A.substr(0, i+1))) break;
		for (int j = i+1; j < i+4 && j<len-1; j++)
		{
			if (!ValidNum(A.substr(i + 1, j-i))) break;
			for (int k = j+1; k < j+4 && k<len-1; k++)
			{
				if (!ValidNum(A.substr(j + 1, k-j))) break;

				if (ValidNum(A.substr(k + 1)))
				{
					string tempIP(A);
					tempIP.insert(tempIP.begin() + k + 1, '.');
					tempIP.insert(tempIP.begin() + j + 1, '.');
					tempIP.insert(tempIP.begin() + i + 1, '.');
					ret.push_back(tempIP);
				}
			}
		}
	}
	return ret;
}
#else
bool isValid(string s) {
	if (s.size() > 1 && s[0] == '0')
		return false;
	if (stoi(s) <= 255 && stoi(s) >= 0)
		return true;
	else
		return false;
}

vector<string> RestoreIpAddresses(string s) {
	vector<string> ans;
	if (s.size() > 12 || s.size() < 4)
		return ans;

	for (int i = 1; i < 4; i++) {
		string first = s.substr(0, i);
		if (!isValid(first))
			continue;
		for (int j = 1; i + j < s.size() && j < 4; j++) {
			string second = s.substr(i, j);
			if (!isValid(second))
				continue;
			for (int k = 1; i + j + k < s.size() && k < 4; k++) {
				string third = s.substr(i + j, k);
				string fourth = s.substr(i + j + k);
				if (isValid(third) && isValid(fourth)) {
					string current = first + "." + second + "." + third + "." + fourth;
					ans.push_back(current);
				}
			}
		}
	}

	return ans;
}
#endif