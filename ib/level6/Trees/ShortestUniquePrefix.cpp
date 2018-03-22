/*************************************************************************************************
Shortest Unique Prefix

Find shortest unique prefix to represent each word in the list.

Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another. In other words, the representation is always
possible.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifdef OWN
class Trie {
public:
#define NUM 26
	Trie *pNext[NUM];
	int cnt[NUM];

	Trie()
	{
		for (int i = 0; i<NUM; i++)
		{
			pNext[i] = nullptr;
			cnt[i] = 0;
		}
	}

	void Insert(const char *str)
	{
		if (*str == 0) return;
		int idx = str[0] - 'a';

		if (pNext[idx] == nullptr)
		{
			pNext[idx] = new Trie();
		}

		pNext[idx]->Insert(str + 1);
		cnt[idx]++;
	}

	void FindPrefix(const char *str, string &ret)
	{
		int idx = str[0] - 'a';
		ret += str[0];
		if (cnt[idx] != 1)
		{
			pNext[idx]->FindPrefix(str + 1, ret);
		}
	}
};

vector<string> ShortestUniquePrefix(vector<string> &A) {
	vector<string> ret;
	int num = (int)A.size();
	Trie *pT = new Trie();

	for (int i = 0; i<num; i++)
	{
		pT->Insert(A[i].c_str());
	}

	for (int i = 0; i<num; i++)
	{
		string temp;
		pT->FindPrefix(A[i].c_str(), temp);
		ret.push_back(temp);
	}

	return ret;
}
#else
int IDX;
vector<vector<int> > Cnt;
vector<vector<int> > Trie;

void insert(string str)
{
	int len = str.size();
	int root = 0;
	int i = 0;

	while (i < len) {
		int chr = str[i] - 'a';
		if (Trie[root][chr] == -1) {
			++IDX;
			Trie[root][chr] = IDX;
			Cnt[root][chr] = 1;
		}
		else {
			Cnt[root][chr]++;
		}
		root = Trie[root][chr];
		i++;
	}
}

string Query(string str)
{
	int root = 0;
	string ans = "";
	int i = 0;
	int len = str.size();

	while (i < len) {
		int chr = str[i] - 'a';
		ans += str[i];
		if (Cnt[root][chr] == 1)
			return ans;
		root = Trie[root][chr];
		i++;
	}
	return "";
}

vector<string> ShortestUniquePrefix(vector<string> Vec)
{
	int mx_len = 0;
	int N = Vec.size();
	for (int i = 0; i < N; ++i) {
		mx_len = max(mx_len, (int)Vec[i].size());
	}

	Trie.clear();
	Cnt.clear();
	Trie.resize(N * mx_len + 1, vector<int>(27, -1));
	Cnt.resize(N * mx_len + 1, vector<int>(27, -1));
	IDX = 0;

	for (int i = 0; i < N; ++i) {
		insert(Vec[i]);
	}

	vector<string> Ans;
	for (int i = 0; i < N; ++i) {
		string ans = Query(Vec[i]);
		Ans.push_back(ans);
	}

	return Ans;
}
#endif