/*************************************************************************************************
Letter Phone

Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN6

#ifdef OWN
static vector<vector<char>> button = { { '1' },               //1
									{ 'a', 'b', 'c' },        //2
									{ 'd', 'e', 'f' },        //3
									{ 'g', 'h', 'i' },        //4
									{ 'j', 'k', 'l' },        //5
									{ 'm', 'n', 'o' },        //6
									{ 'p', 'q', 'r', 's' },   //7
									{ 't', 'u', 'v' },        //8
									{ 'w', 'x', 'y', 'z' },   //9
									{ '0' } };                //0

static void Combination(vector<int> &nums, int idx, vector<string> &comb)
{
	int len = (int)nums.size();
	if (len == idx) return;

	string sub;
	if (!comb.empty())
	{
		sub = comb.back();
		comb.pop_back();
	}

	for (int i = 0; i<(int)button[nums[idx]].size(); i++)
	{
		sub.push_back(button[nums[idx]][i]);
		comb.push_back(sub);
		Combination(nums, idx + 1, comb);
		sub.pop_back();
	}
}

vector<string> LetterCombinations(string A) {
	int len = (int)A.size();
	vector<int> nums;
	vector<string> comb;

	for (int i = 0; i<len; i++)
	{
		if (A[i] >= '1' && A[i] <= '9')
		{
			nums.push_back(A[i] - '1');
		}
		else if (A[i] == '0')
		{
			nums.push_back(9);
		}
	}

	Combination(nums, 0, comb);
	return comb;
}
#else
string charmap[10];

void generateHelper(string &current, int index, string &digits, vector<string> &ans) {
	if (index == digits.length()) {
		ans.push_back(current);
		return;
	}
	int digit = digits[index] - '0';
	for (int i = 0; i < charmap[digit].length(); i++) {
		current.push_back(charmap[digit][i]);
		generateHelper(current, index + 1, digits, ans);
		current.pop_back();
	}
	return;
}

vector<string> LetterCombinations(string digits) {
	charmap[0] = "0";
	charmap[1] = "1";
	charmap[2] = "abc";
	charmap[3] = "def";
	charmap[4] = "ghi";
	charmap[5] = "jkl";
	charmap[6] = "mno";
	charmap[7] = "pqrs";
	charmap[8] = "tuv";
	charmap[9] = "wxyz";
	vector<string> ans;
	string current = "";
	generateHelper(current, 0, digits, ans);
	return ans;
}
#endif