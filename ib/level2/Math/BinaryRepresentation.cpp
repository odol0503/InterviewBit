/*************************************************************************************************
Binary Representation
Given a number N >= 0, find its representation in binary.

Example:
if N = 6,
binary form = 110
*************************************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

#define OWN

#ifdef OWN
string BinaryRepresentation(int A) {
	string ret;

	if (A == 0) return "0";

	while (A)
	{
		ret.push_back((A % 2) + '0');
		A /= 2;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}
#else
string BinaryRepresentation(int n) {
	string ans;
	if (n == 0) return "0";

	while (n > 0) {
		int rem = n % 2;
		ans.push_back((char)('0' + rem));
		n /= 2;
	}

	reverse(ans.begin(), ans.end());
	return ans;
		}
#endif