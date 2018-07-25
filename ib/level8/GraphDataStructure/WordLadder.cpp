/*************************************************************************************************
Word Ladder I

Given two words (start and end), and a dictionary, find the length of shortest transformation
sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of 
transformation itself.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define OWN5

#ifdef OWN
bool checkLadder(string A, string B)
{
	if (A.size() != B.size()) return false;

	int cnt = 0;
	for (int i = 0; i<A.size(); i++)
	{
		if (A[i] != B[i]) cnt++;
	}

	if (cnt == 1) return true;

	return false;
}

int LadderLength(string start, string end, vector<string> &dictV) {
	if (start == end) return 1;

	int cnt = 1;
	queue<string> Q1;
	queue<string> Q2;

	set<string> S(dictV.begin(), dictV.end());

	Q1.push(start);

	while (Q1.size())
	{
		set<string> temp;
		string val = Q1.front();
		Q1.pop();

		for (auto s : S)
		{
			if (checkLadder(val, s))
			{
				if (end == s)
				{
					return cnt + 1;
				}
				Q2.push(s);
			}
			else
			{
				temp.insert(s);
			}
		}
		S = temp;

		if (Q1.empty())
		{
			cnt++;
			swap(Q1, Q2);
		}
	}

	return 0;
}
#else
int LadderLength(string start, string end, vector<string> &dictV) {
	unordered_set<string> dict(dictV.begin(), dictV.end());
	unordered_map<string, int> distance; // store the distancetance from start to the current word
	queue<string> q; // FIFO for bfs purpose
	distance[start] = 1;
	q.push(start);
	while (!q.empty()) {
		string word = q.front();
		q.pop();
		if (word == end) break;
		for (int i = 0; i < word.size(); i++) {
			for (int j = 0; j < 26; j++) {
				string newWord = word;
				newWord[i] = 'a' + j;
				if (dict.find(newWord) != dict.end() && distance.find(newWord) == distance.end()) {
					distance[newWord] = distance[word] + 1;
					q.push(newWord);
				}
			}
		}
	}
	if (distance.find(end) == distance.end()) return 0; // not found
	return distance[end];
}
#endif