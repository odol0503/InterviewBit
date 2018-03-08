/*************************************************************************************************
Substring Concatenation

You are given a string, S, and a list of words, L, that are all of the same length.
Find all starting indices of substring(s) in S that is a concatenation of each word 
in L exactly once and without any intervening characters.

Example :
S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define OWN

#ifdef OWN
vector<int> FindSubstring(string A, const vector<string> &B) {
	int len = (int)A.size();
	int num = (int)B.size();
	int wordlen = (int)B[0].size();
	multimap<string, int> M;
	vector<int> ret;

	for (int i = 0; i < len; i++)
	{
		M.clear();
		for (int j = 0; j < num; j++) M.insert({ B[j], 0 });

		for (int j = 0; j < num; j++)
		{
			string str = A.substr(i+ j* wordlen, wordlen);
			if (M.count(str) == 0) break;
			
			auto range = M.equal_range(str);
			for (auto it = range.first; it != range.second; it++)
			{
				if (it->second == 0)
				{
					it->second = 1;
					break;
				}
			}
			
			if (j == num - 1)
			{
				bool bFound = true;
				for (auto it = M.begin(); it != M.end(); it++)
				{
					if (it->second == 0)
					{
						bFound = false;
						break;
					}
				}
				if (bFound) ret.push_back(i);
			}
		}
	}

	return ret;
}
#else
unsigned int myhash(const string &s) {
	unsigned int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret = (ret * 100 + s[i]) % 9999997;
	}
	return ret;
}

bool checkSubstring(const string &S, int j, unordered_multiset<string> L) {
	int lsize = L.size(), wsize = L.begin()->size();
	for (int i = 0; i < lsize; i++) {
		if (L.find(S.substr(j + i * wsize, wsize)) == L.end()) return false;
		L.erase(L.find(S.substr(j + i * wsize, wsize)));
	}
	return true;
}

vector<int> FindSubstring(string S, const vector<string> &L) {
	vector<int> ret;
	if (L.empty()) return ret;
	unsigned int hashsum = 0;
	for (int i = 0; i < L.size(); i++)
		hashsum += myhash(L[i]);

	int wsize = L[0].size(), lsize = L.size();
	for (int i = 0; i < wsize; i++) {
		// In this loop, we will consider all starting positions in S where start % wsize = i.
		vector<unsigned int> hashes;
		int hashsum2 = 0;
		// Calculate the hash of wordsize for all start positions we are considering ( start % wsize = i ) 
		for (int j = i; j < S.size(); j += wsize) {
			hashes.push_back(myhash(S.substr(j, wsize)));
		}
		if (hashes.size() < lsize) continue;
		// Calculare the hashsum of string size lsize * wsize from index i. 
		for (int j = 0; j < lsize; j++) hashsum2 += hashes[j];
		// If hashes are same, very high probability that this is part of our solution. 
		if (hashsum == hashsum2) ret.push_back(i);

		for (int j = lsize; j < hashes.size(); j++) {
			// pop out [i, i + wsize] prefix  and include [j, j+wsize] suffix in our string. 
			// In other words, adding new wsize chars. 
			hashsum2 = hashsum2 - hashes[j - lsize] + hashes[j];
			if (hashsum == hashsum2) ret.push_back(i + (j - lsize + 1) * wsize);
		}
	}

	// check the final result
	unordered_multiset<string> Lset(L.begin(), L.end());
	vector<int> ret2;
	for (int i = 0; i < ret.size(); i++) {
		if (checkSubstring(S, ret[i], Lset))
			ret2.push_back(ret[i]);
	}

	return ret2;
}
#endif