/*************************************************************************************************
Fraction

Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.
Example :
Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
string FractionToDecimal(int A, int B) {
	string ret;
	long long N = (long long)A;
	long long D = (long long)B;
	string num1;
	string num2;
	long long remain = 0;
	int sign = (N*D < 0 ? -1 : 1);

	N = abs(N);
	D = abs(D);

	remain = N % D;
	num1 = to_string(N / D);

	if (remain == 0) return ret = (sign<0? "-" : "") + num1;

	map<long long, int> M;
	while (M.count(remain) == 0 && remain != 0)
	{
		M[remain] = (int)num2.size();
		remain *= 10;
		num2 += to_string(remain / D);
		remain %= B;
	}

	if (M.count(remain))
	{
		num2.insert(num2.begin() + M[remain], '(');
		num2 += ')';
	}

	ret = (sign<0 ? "-" : "") + num1 + "." + num2;

	return ret;
}
#else
string FractionToDecimal(int numerator, int denominator) {
	int64_t n = numerator, d = denominator;
	// zero numerator
	if (n == 0) return "0";

	string res;
	// determine the sign
	if (n < 0 ^ d < 0) res += '-';

	// remove sign of operands
	n = abs(n), d = abs(d);

	// append integral part
	res += to_string((n / d));

	// in case no fractional part
	if (n % d == 0) return res;

	res += '.';

	unordered_map<int, int> map;

	// simulate the division process
	for (int64_t r = n % d; r; r %= d) {

		// meet a known remainder
		// so we reach the end of the repeating part
		if (map.find(r) != map.end()) {
			// insert '(' at the start position where we first saw the remainder
			res.insert(map[r], 1, '(');
			res += ')';
			break;
		}

		// the remainder is first seen
		// remember the current position for it
		map[r] = res.size();

		r *= 10;

		// append the quotient digit
		res.push_back((char)('0' + (r / d)));
	}

	return res;
}
#endif