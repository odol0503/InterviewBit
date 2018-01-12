/*************************************************************************************************
FizzBuzz

Given a positive integer N, print all the integers from 1 to N. But for multiples of 3 print
¡°Fizz¡± instead of the number and for the multiples of 5 print ¡°Buzz¡±. Also for number which
are multiple of 3 and 5, prints ¡°FizzBuzz¡±.

Example
N = 5
Return: [1 2 Fizz 4 Buzz]
Note: Instead of printing the answer, you have to return it as list of strings.
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

vector<string> FizzBuzz(int A) 
{
	vector<string> ret;
	for (int i = 1; i <= A; i++)
	{
		if ((i % 3) && (i % 5) == 0)
		{
			ret.push_back("FizzBuzz");
		}
		else if (i % 5 == 0)
		{
			ret.push_back("Buzz");
		}
		else if (i % 3 == 0)
		{
			ret.push_back("Fizz");
		}
		else
		{
			ret.push_back(to_string(i));
		}
	}
	return ret;
}