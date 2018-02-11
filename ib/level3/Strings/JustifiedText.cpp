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
	vector<string> temp;
	vector<string> ret;
	int num = (int)A.size();
	int sum = 0;
	int str_len = 0;

	for (int i = 0; i < num; i++)
	{
		sum += (int)A[i].size() + 1;
		str_len += (int)A[i].size();
		temp.push_back(A[i]);

		if (i < num - 1)
		{
			if (sum + (int)A[i+1].size() > B)
			{
				int sp_len = B - str_len;
				int hole_cnt = ((int)temp.size() == 1 ? 1 : (int)temp.size() - 1);
				int even_sp = sp_len / hole_cnt;
				int remain_sp = sp_len % hole_cnt;
				string str;
				for (int j = 0; j < (int)temp.size(); j++)
				{
					str += temp[j];

					if (temp.size() == 1 || j < temp.size() - 1)
					{
						str += string(even_sp, ' ');
						if (j < remain_sp) str += " ";
					}
				}
				ret.push_back(str);
				temp.clear();
				sum = 0;
				str_len = 0;
			}
		}
		else
		{
			int temp_num = (int)temp.size();
			string str;
			for (int j = 0; j < temp_num-1; j++)
			{
				str += temp[j];
				str += " ";
			}
			str += temp.back();
			int str_len = (int)str.size();
			str += string(B - str_len, ' ');
			ret.push_back(str);
		}
	}
	return ret;
}
#else
vector<string> FullJustify(vector<string> &words, int L) {
	vector<string> res;
	int k = 0, l = 0;
	for (int i = 0; i < words.size(); i += k) {
		for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++) {
			l += words[i + k].size();
		}
		string tmp = words[i];
		for (int j = 0; j < k - 1; j++) {
			if (i + k >= words.size()) tmp += " ";
			else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
			tmp += words[i + j + 1];
		}
		tmp += string(L - tmp.size(), ' ');
		res.push_back(tmp);
	}
	return res;
}
#endif