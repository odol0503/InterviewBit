/*************************************************************************************************
Hotel Reviews

Given a set of reviews provided by the customers for different hotels and 
a string containing ¡°Good Words¡±, you need to sort the reviews 
in descending order according to their ¡°Goodness Value¡± (Higher goodness value first). 
We define the ¡°Goodness Value¡± of a string as the number of ¡°Good Words¡± in that string.
Note: Sorting should be stable. If review i and review j have the same ¡°Goodness Value¡± 
then their original order would be preserved.

You are expected to use Trie in an Interview for such problems
Constraints:
1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)

Input:
S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.

Output:
A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews.
V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position 
in the sorted order. (Indexing is 0 based)

Example:
Input:
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]
Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define OWN

#ifdef OWN
static int comp(pair<int, int> A, pair<int, int> B)
{
	return A.first > B.first;
}

vector<int> HotelReviews(string A, vector<string> &B) {
	vector<string> GoodWords;
	char *str = (char*)A.c_str();
	char *ptr = strtok(str, "_");
	while (ptr)
	{
		GoodWords.push_back(ptr);
		ptr = strtok(nullptr, "_");
	}

	vector<vector<string>> Reviews;
	Reviews.resize(B.size());
	for (int i = 0; i<(int)B.size(); i++)
	{
		str = (char*)B[i].c_str();
		ptr = strtok(str, "_");
		while (ptr)
		{
			Reviews[i].push_back(ptr);
			ptr = strtok(nullptr, "_");
		}
	}

	unordered_map<string, int> Rates;
	for (int i = 0; i<(int)GoodWords.size(); i++)
	{
		Rates[GoodWords[i]] = (int)GoodWords.size() - i;
	}

	vector<pair<int, int>> sums;
	for (int i = 0; i<(int)Reviews.size(); i++)
	{
		int s = 0;
		for (int j = 0; j<(int)Reviews[i].size(); j++)
		{
			s += Rates[Reviews[i][j]];
		}
		sums.push_back({ s, i });
	}
	sort(sums.begin(), sums.end(), comp);

	vector<int> ret;
	for (auto s : sums)
	{
		ret.push_back(s.second);
	}
	return ret;
}
#else

#endif