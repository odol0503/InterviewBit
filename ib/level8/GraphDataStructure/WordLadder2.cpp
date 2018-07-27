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

#define OWN

#ifdef OWN
struct Graph {
	string val;
	vector<Graph*> node;
	Graph(string str) : val(str) {}
};

bool checkLadder(string A, string B)
{
	if (A.size() != B.size()) return false;

	int cnt = 0;
	for (int i = 0; i<A.size(); i++)
	{
		if (A[i] != B[i]) cnt++;
		if (cnt > 1) return false;
	}

	if (cnt == 0) return false;
	return true;
}

void buildVec(Graph *G, vector<string> &C, string &end, vector<vector<string>> &ret)
{
	if (G->val == end)
	{
		ret.push_back(C);
		return;
	}

	for (auto n : G->node)
	{
		C.push_back(n->val);
		buildVec(n, C, end, ret);
		C.pop_back();
	}
}

vector<vector<string> > findLadders(string start, string end, vector<string> &dict) {
	if (start == end) return vector<vector<string>>({ { start } });
	queue<pair<Graph*, set<string>>> Q1;
	queue<pair<Graph*, set<string>>> Q2;
	set<string> S(dict.begin(), dict.end());
	bool bFound = false;

	Graph *node = new Graph(start);
	Q1.push({ node, S });

	while (Q1.size())
	{
		pair<Graph*, set<string>> P = Q1.front();
		Graph *G = P.first;
		set<string> S2 = P.second;

		S2.erase(G->val);
		Q1.pop();

		for (auto s : S2)
		{
			if (checkLadder(G->val, s))
			{
				Graph *n = new Graph(s);
				G->node.push_back(n);
				Q2.push({ n, S2 });
				if (s == end) bFound = true;
			}
		}

		if (!bFound && Q1.empty()) swap(Q1, Q2);
	}

	if (node->node.empty()) return vector<vector<string>>();

	vector<vector<string>> ret;
	vector<string> C(1, start);
	buildVec(node, C, end, ret);

	return ret;
}
#else
void constructPaths(string start, string &end, unordered_map<string, vector<string> > & parents, vector<string> &current, vector<vector<string> > &answer) {
	if (start == end) {
		answer.push_back(current);
		return;
	}
	for (int i = 0; i < parents[start].size(); i++) {
		current.push_back(parents[start][i]);
		constructPaths(parents[start][i], end, parents, current, answer);
		current.pop_back();
	}
	return;
}

vector<vector<string> > findLadders(string start, string end, vector<string> &dictV) {
	unordered_set<string> dict(dictV.begin(), dictV.end());
	vector<vector<string> > answer;
	unordered_map<string, int> distance; // store the distance from start to the current word
	queue<string> q; // FIFO for bfs purpose
	unordered_map<string, vector<string> > parents;
	swap(start, end); // We do this because we construct the path later from end to start 
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
				if (dict.find(newWord) != dict.end()) {
					if (distance.find(newWord) == distance.end()) { // seen for the first time
						distance[newWord] = distance[word] + 1;
						q.push(newWord);
						parents[newWord].push_back(word);
					}
					else if (distance[newWord] == distance[word] + 1) {
						parents[newWord].push_back(word);
					}
				}
			}
		}
	}
	if (distance.find(end) == distance.end()) return answer; // not found
															 // backtrack and construct all possible paths now that we know possible optimal parents.  
	vector<string> current;
	current.push_back(end);
	constructPaths(end, start, parents, current, answer);
	sort(answer.begin(), answer.end());
	return answer;
}
#endif