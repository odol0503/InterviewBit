/*************************************************************************************************
Simplify Directory Path

Given an absolute path for a file (Unix-style), simplify it.

Examples:
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ¡®/¡¯ ( root directory )
Path will not have whitespace characters.
*************************************************************************************************/
#include <stack>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
string SimplifyPath(string A) {
	string ret = "/";
	vector<string> temp;
	stack<string> st;
	int len = (int)A.size();

	string str;
	for (int i = 0; i < len; i++)
	{
		if (i > 0 && A[i] == '/')
		{
			if (str == ".")
			{
				;
			}
			else if (str == "..")
			{
				if (!st.empty()) st.pop();
			}
			else
			{
				if (!str.empty()) st.push(str);
			}
			str.clear();
		}
		else if (A[i] != '/')
		{
			str += A[i];
		}
	}

	if (!str.empty())
	{
		if (str == ".");
		else if (str == "..")
		{
			if (!st.empty()) st.pop();
		}
		else st.push(str);
	}

	while (!st.empty())
	{
		temp.push_back(st.top());
		st.pop();
	}

	reverse(temp.begin(), temp.end());

	for (int i=0; i<(int)temp.size(); i++)
	{
		ret += temp[i];
		if (i < (int)temp.size()-1) ret += '/';
	}

	return ret;
}
#else
string SimplifyPath(string path) {
	vector < string >   nameVect;
	string name;

	path.push_back('/');

	for (int i = 0; i < path.size(); i++) {
		if (path[i] == '/') {
			if (name.size() == 0) continue;
			if (name == "..") {     //special case 1£ºdouble dot£¬pop dir
				if (nameVect.size() > 0) nameVect.pop_back();
			}
			else if (name == ".") {//special case 2:singel dot£¬don`t push
			}
			else {
				nameVect.push_back(name);
			}
			name.clear();
		}
		else {
			name.push_back(path[i]);//record the name
		}
	}

	string result;
	if (nameVect.empty()) return "/";
	for (int i = 0; i < nameVect.size(); i++) {
		result.append("/" + nameVect[i]);
	}
	return result;
}
#endif