/*************************************************************************************************
Add One To Number

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

NOTE: Certain things are intentionally left unclear in this question 
which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0¡¯s before the most significant digit. Or in other words, 
is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0¡¯s before the most significant digit? Or in other words, 
is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes
before the most significant digit.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<int> AddOneToNumber(vector<int> &A)
{
	vector<int> ret;

	int carry = 1;
	for (int i =(int)A.size()-1; i>=0; i--)
	{
		ret.push_back((A[i] + carry) % 10);
		carry = (A[i] + carry) / 10;
	}

	if (carry) ret.push_back(carry);
	while (ret.back() == 0) ret.pop_back();
	reverse(ret.begin(), ret.end());

	return ret;
}
#else
vector<int> AddOneToNumber(vector<int> &digits) {
	reverse(digits.begin(), digits.end());
	vector<int> ans;
	int carry = 1;
	for (int i = 0; i < digits.size(); i++) {
		int sum = digits[i] + carry;
		ans.push_back(sum % 10);
		carry = sum / 10;
	}
	while (carry) {
		ans.push_back(carry % 10);
		carry /= 10;
	}
	while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	reverse(digits.begin(), digits.end());
	return ans;
}
#endif
