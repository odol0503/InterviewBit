/*************************************************************************************************
Colorful Number

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts.
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245.
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence 
is different

Example:
N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different.

Output : 1
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
int Colorful(int A) {
	string num = to_string(A);
	int size = (int)num.size();
	unordered_set<int> sub;

	for (int len = 1; len <= size; len++)
	{
		for (int i = 0; i < size - len + 1; i++)
		{
			string temp = num.substr(i, len);
			int val = 1;
			for (int j = 0; j < (int)temp.size(); j++)
			{
				val *= temp[j] - '0';
			}
			if (sub.count(val)) return 0;
			sub.insert(val);
		}
	}
	
	return 1;
}
#else
int Colorful(int N) {
	char st[20];
	sprintf(st, "%d", N);
	int len = strlen(st);

	map<long long, bool> Hash;

	for (int i = 0; i < len; ++i) {
		long long mul = 1;
		for (int j = i; j < len; ++j) {
			mul *= (long long)(st[j] - '0');
			if (Hash.find(mul) != Hash.end())
				return 0;
			Hash[mul] = true;
		}
	}

	return 1;
	}
#endif