/*************************************************************************************************
Atoi
Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions
before you jump into coding.

Implement atoi to convert a string to an integer.

Example :
Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using ¡°See Expected Output¡±.

Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, 
what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int Atoi(const string A) {
	string num;
	int len = (int)A.size();

	int i = 0;
	if (A[0] == '-' || A[0] == '+')
	{
		num.push_back(A[0]);
		i++;
	}

	for (; i<len; i++)
	{
		if (isdigit(A[i]))
		{
			num.push_back(A[i]);
		}
		else break;
	}

	if (num.empty()) return 0;

	double temp = 0;
	long long sign = 1;

	i = 0;
	len = (int)num.size();
	if (num[0] == '-' || num[0] == '+')
	{
		if (len == 1) return 0;
		if (num[0] == '-') sign *= -1;
		i++;
	}

	for (; i < len; i++)
	{
		temp = temp*10 + (A[i]-'0');
	}

	temp = temp * sign;

	if (temp > INT_MAX) return INT_MAX;
	if (temp < INT_MIN) return INT_MIN;
	return (int)temp;
}
#else
int Atoi(const string A) {
	int sign = 1, base = 0, i = 0;
	while (str[i] == ' ') { i++; }
	if (str[i] == '-' || str[i] == '+') {
		sign = (str[i++] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
			if (sign == 1) return INT_MAX;
			else return INT_MIN;
		}
		base = 10 * base + (str[i++] - '0');
	}
	return base * sign;
}
#endif
