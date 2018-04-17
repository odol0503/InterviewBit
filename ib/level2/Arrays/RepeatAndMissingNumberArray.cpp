/*************************************************************************************************
Repeat and Missing Number Array

Please Note:
There are certain problems which are asked in the interview to also check 
how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly 
and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :
Even though it might not be required in this problem, in some cases, you might be required 
to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is 
to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

Note that in your output A should precede B.

Example:
Input:[3 1 2 5 3]
Output:[3, 4]
A = 3, B = 4
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<int> RepeatAndMissingNumberArray(const vector<int> &A) {
	int64_t len = (int64_t)A.size();
	int64_t osum = (len*(len + 1) / 2);
	int64_t sum = 0;
	int64_t osum2 = 0;
	int64_t sum2 = 0;

	for (int64_t i = 0; i<len; i++)
	{
		sum += A[i];
		osum2 += (i + 1)*(i + 1);
		sum2 += (int64_t)A[i] * A[i];
	}

	int b = (int)(((sum2 - osum2) - (sum - osum)*(sum - osum)) / (2 * (sum - osum)));
	int a = (int)(sum - osum + b);
	vector<int> ret;
	ret.push_back(a);
	ret.push_back(b);
	return ret;
}
#else
vector<int> RepeatAndMissingNumberArray(const vector<int> &V) {
	long long sum = 0;
	long long squareSum = 0;
	long long temp;
	for (int i = 0; i < V.size(); i++) {
		temp = V[i];
		sum += temp;
		sum -= (i + 1);
		squareSum += (temp * temp);
		squareSum -= ((long long)(i + 1) * (long long)(i + 1));
	}
	// sum = A - B
	// squareSum = A^2 - B^2 = (A - B)(A + B)
	// squareSum / sum = A + B
	squareSum /= sum;

	// Now we have A + B and A - B. Lets figure out A and B now. 
	int A = (int)((sum + squareSum) / 2);
	int B = squareSum - A;

	vector<int> ret;
	ret.push_back(A);
	ret.push_back(B);
	return ret;
	}
#endif