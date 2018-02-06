/*************************************************************************************************
Count And Say
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.

Example:
if n = 2,
the sequence is 11.
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
string CountAndSay(int A)
{
	string ret;
	
	A -= 1;

	if (A >= 0) ret.push_back('1');
	else return ret;

	for (int num = 0; num < A; num++)
	{
		int len = (int)ret.size();
		string temp;

		for (int i = 0; i < len; i++)
		{
			int cnt = 1;

			for (int j = i + 1; j < len; j++)
			{
				if (ret[i] == ret[j])
				{
					cnt++;
					i++;
					continue;
				}
				break;
			}
			temp += to_string(cnt);
			temp += ret[i];
		}

		ret = temp;
	}

	return ret;
}
#else
string CountAndSay(int A)
{
	if (n == 0) return "";
	if (n == 1) return "1";

	string prev = "1";
	string current = prev;

	for (int seqNum = 2; seqNum <= n; seqNum++) {    // run from starting to generate second string

		current.clear();
		//cheack all digits in the string
		for (int j = 0; j < prev.length(); j++) {

			int count = 1; // we have at least 1 occourence of each digit

						   // get the number of times same digit occurred (be carefull with the end of the string)
			while ((j + 1 < prev.length()) && (prev[j] == prev[j + 1])) {
				count++;
				j++;        // we need to keep increasing the index inside of the string
			}

			// add to new string "count" + "digit itself"
			current.append(to_string(count) + prev[j]);
		}

		// save temporary result
		prev = current;
	}

	return current;
}
#endif