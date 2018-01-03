/*************************************************************************************************
Triplets with Sum between given range

Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet(a, b, c) such that 1 < a + b + c < 2 .
	Return 1 for true or 0 for false.

	Example :

	Given[0.6, 0.7, 0.8, 1.2, 0.4],

	You should return 1

	as

	0.6 + 0.7 + 0.4 = 1.7

	1<1.7<2

	Hence, the output is 1.

	O(n) solution is expected.

	Note: You can assume the numbers in strings don¡¯t overflow the primitive data type and 
	there are no leading zeroes in numbers.Extra memory usage is allowed.
*************************************************************************************************/
#include <vector>
#include <string>
#include <cfloat>
#include <algorithm>

using namespace std;

int Triplets(vector<string> &A) 
{
	size_t len = A.size();
	vector<float> num(len);
	for (size_t i = 0; i < len; i++)
	{
		num[i] = stof(A[i], 0);
	}

	const float a_hi = 2 / static_cast<float>(3);
	float a_min1 = FLT_MAX, a_min2 = FLT_MAX;
	float b_min1 = FLT_MAX, b_min2 = FLT_MAX;
	float c_min = FLT_MAX;
	float a_max1 = FLT_MIN, a_max2 = FLT_MIN, a_max3 = FLT_MIN;
	float b_max = FLT_MIN;
	for (size_t i = 0; i < len; i++)
	{
		if (num[i] < a_hi)
		{
			if (num[i] < a_min1)
			{
				a_min2 = a_min1;
				a_min1 = num[i];
			}
			else if (num[i] < a_min2)
			{
				a_min2 = num[i];
			}

			if (num[i] > a_max1)
			{
				a_max3 = a_max2;
				a_max2 = a_max1;
				a_max1 = num[i];
			}
			else if (num[i] > a_max2)
			{
				a_max3 = a_max2;
				a_max2 = num[i];
			}
			else if (num[i] > a_max3)
			{
				a_max3 = num[i];
			}
		}
		else if (num[i] > a_hi && num[i] < 1)
		{
			if (num[i] < b_min1)
			{
				b_min2 = b_min1;
				b_min1 = num[i];
			}
			else if (num[i] < b_min2)
			{
				b_min2 = num[i];
			}

			b_max = max(b_max, num[i]);
		}
		else if (num[i] >= 1 && num[i] < 2)
		{
			c_min = min(c_min, num[i]);
		}
	}

	if (a_max1 != FLT_MIN && a_max2 != FLT_MIN && a_max3 != FLT_MIN)
	{
		if (a_max1 + a_max2 + a_max3 > 1) return 1;
	}
	
	if (a_max1 != FLT_MIN && a_max2 != FLT_MIN && b_max != FLT_MIN && a_min1 != FLT_MAX && a_min2 != FLT_MAX && b_min1 != 1.0f)
	{
		if (a_max1 + a_max2 + b_max > 1 && a_min1 + a_min2 + b_min1 < 2) return 1;
	}
	
	if (a_min1 != FLT_MAX && a_min2 != FLT_MAX && c_min != FLT_MAX)
	{
		if (a_min1 + a_min2 + c_min < 2) return 1;
	}
	
	if (a_min1 != FLT_MAX && b_min1 != FLT_MAX && b_min2 != FLT_MAX)
	{
		if (a_min1 + b_min1 + b_min2 < 2) return 1;
	}
	
	if (a_min1 != FLT_MAX && b_min1 != FLT_MAX && c_min != FLT_MAX)
	{
		if (a_min1 + b_min1 + c_min < 2) return 1;
	}

	return 0;
}