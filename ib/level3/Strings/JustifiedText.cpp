/*************************************************************************************************
Justified Text

Given an array of words and a length L, format the text such that each line has 
exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces бо бо when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots 
on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
vector<string> FullJustify(vector<string> &A, int B) {
	string temp;
	vector<string> ret;
	int num = (int)A.size();
	int len = 0;

	for (int i = 0; i < num; i++)
	{
		len += (int)A[i].size() + 1;
		
		if (len > B)
		{
			--i;
			int cnt = (int)temp.size();
			int spaces = (B % cnt)/(cnt == 1?cnt:(cnt-1));
			int dummy = (B%cnt) & 0x01;
			string str;
			for (int j = 0; j < cnt; j++)
			{
				str += temp[j];
				if (j == 0 && dummy) str += ' ';
				for (int k = 0; k < spaces; k++) str += ' ';
			}

		}
		temp.push_back(A[i]);
	}
	
}
#else
vector<string> FullJustify(vector<string> &A, int B) {
}
#endif