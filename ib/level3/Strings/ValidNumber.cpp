/*************************************************************************************************
Valid Number

Please Note:
Note: It is intended for some problems to be ambiguous. You should gather all requirements up
front before implementing one.

Please think of all the corner cases and clarifications yourself.
Validate if a given string is numeric.

Examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using ¡°See Expected Output¡±

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem
*************************************************************************************************/
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int ValidNumber(const string A) {
	int i = 0;
	int len = (int)A.size();
	bool bFoundDot = false;
	bool bFoundExp = false;
	bool bFoundSP = false;

	if (len == 0) return 0;

	while (A[i] == ' ') i++;

	if (A[i] == '-' || A[i] == '+') i++;

	if (!isdigit(A[i]) && A[i] != '.') return 0;

	for (; i < len; i++)
	{
		if (!isdigit(A[i]))
		{
			if (A[i] == '.' && !bFoundDot)
			{
				if (bFoundSP) return 0;
				if (i == len - 1 || (i < len - 1) && A[i + 1] == 'e') return 0;
				if (bFoundExp) return 0;
				bFoundDot = true;
				continue;
			}
			else if (A[i] == 'e' && !bFoundExp)
			{
				if (bFoundSP) return 0;
				if ((i < len - 1) && A[i + 1] == '-' || A[i + 1] == '+') i++;
				bFoundExp = true;
				continue;
			}
			else if (A[i] == ' ')
			{
				bFoundSP = true;
				continue;
			}
			else return 0;
		}
		else if (bFoundSP)
		{
			return 0;
		}
	}

	return 1;
}
#else
int ValidNumber(const string S) {
	const char *s = S.c_str();
	int i = 0;

	// skip the whilespaces
	while (s[i] == ' ') {
		i++;
	}
	if (s[i] == '\0') return false;

	// check the significand
	if (s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
	int num_digits, num_points;
	for (num_digits = 0, num_points = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; i++) {
		if (s[i] == '.') {
			num_points++;
		}
		else {
			num_digits++;
		}
	}

	// no more than one point, at least one digit. Should not end with .
	if (num_points > 1 || num_digits < 1 || s[i - 1] == '.')
		return false;

	// check the exponent if exist
	if (s[i] == 'e') {
		i++;
		if (s[i] == '+' || s[i] == '-') i++; // skip the sign

		num_digits = 0;
		while (s[i] >= '0' && s[i] <= '9') {
			i++;
			num_digits++;
		}

		if (num_digits < 1)
			return false;
	}

	// skip the trailing whitespaces
	while (s[i] == ' ') {
		i++;
	}

	return s[i] == '\0';  // must reach the ending \0 of the string
}
#endif