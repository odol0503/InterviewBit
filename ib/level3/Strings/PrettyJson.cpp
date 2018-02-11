/*************************************************************************************************
Pretty Json

Pretty print a json object using proper indentation.
Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ¡®\t¡¯

Example 1:
Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output :
{
	A:"B",
	C:
	{
		D:"E",
		F:
		{
			G:"H",
			I:"J"
		}
	}
}

Example 2:
Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output :
[
	"foo",
	{
		"bar":
		[
			"baz",
			null,
			1.0,
			2
		]
	}
]

[] and {} are only acceptable braces in this case.
Assume for this problem that space characters can be done away with.
Your solution should return a list of strings, where each entry corresponds to a single line.
The strings should not have ¡°\n¡± character in them.
*************************************************************************************************/
#include <string>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
vector<string> PrettyJSON(string A) {
	int len = (int)A.size();
	vector<string> ret;
	int ind = 0;
	string str;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == '[' || A[i] == '{')
		{
			string temp(ind, '\t');
			if (!str.empty()) ret.push_back(temp + str);
			ret.push_back(temp + string(1, A[i]));
			ind++;
			str.clear();
		}
		else if (A[i] == ']' || A[i] == '}')
		{
			if (!str.empty())
			{
				string temp1(ind, '\t');
				ret.push_back(temp1 + str);
			}
			ind = (--ind < 0 ? 0 : ind);
			string temp2(ind, '\t');
			if (i < len - 1 && A[i + 1] == ',')
			{
				ret.push_back(temp2 + string(1, A[i]) + string(1, A[i + 1]));
				i++;
			}
			else ret.push_back(temp2 + string(1, A[i]));
			str.clear();
		}
		else if (A[i] == ',')
		{
			string temp(ind, '\t');
			ret.push_back(temp + str + string(1, A[i]));
			str.clear();
		}
		else
		{
			str += A[i];
		}
	}

	return ret;
}
#else
vector<string> PrettyJSON(string A) {
	vector<string> ans;
	if (json.length() == 0) return ans;
	// remove all spaces. 
	json.erase(remove(json.begin(), json.end(), ' '), json.end());

	string indent = "";
	string current = "";
	int i = 0, len = json.length();
	while (i < len) {
		current.push_back(json[i]);
		switch (json[i]) {
		case ',':
			ans.push_back(current);
			current = indent;
			i++;
			break;
		case ':':
			i++;
			if (json[i] == '{' || json[i] == '[') {
				ans.push_back(current);
				current = indent;
			}
			break;
		case '{':
		case '[':
			i++;
			ans.push_back(current);
			if (i < len && (json[i] != '}' || json[i] != ']')) {
				indent.push_back('\t');
			}
			current = indent;
			break;
		case '}':
		case ']':
			i++;
			if (i < len && json[i] == ',') break;
			ans.push_back(current);
			if (i < len && (json[i] == '}' || json[i] == ']')) {
				if (!indent.empty()) indent.pop_back();
			}
			current = indent;
			break;
		default:
			i++;
			if (i < len && (json[i] == '}' || json[i] == ']')) {
				ans.push_back(current);
				if (!indent.empty()) indent.pop_back();
				current = indent;
			}
		}
	}
	return ans;
}
#endif