/*************************************************************************************************
Window String
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window 
in S should be at least N.

Example :
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window 
( with minimum start index ).
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

#define OWN

#ifdef OWN
string MinWindow(string A, string B) {
	int len = (int)A.size();
	int num = (int)B.size();
	int min_len = INT_MAX;
	string ret;
	int BMap[256];
	set<int> SMap;

	for (int i = 0; i<256; i++)
	{
		BMap[i] = 0;
	}

	for (int i = 0; i<num; i++)
	{
		BMap[B[i]]++;
		SMap.insert(B[i]);
	}

	int start = 0;
	int end = 0;

	while (start <= end && end < len)
	{
		if (SMap.count(A[end]))
		{
			if (num > 0)
			{
				if (BMap[A[end]] > 0) num--;
				BMap[A[end]]--;

				while (num == 0)
				{
					int gap = end - start + 1;
					if (min_len > gap)
					{
						min_len = gap;
						ret = A.substr(start, min_len);
					}

					if (SMap.count(A[start]))
					{
						if (BMap[A[start]] >= 0) num++;
						BMap[A[start]]++;
					}
					while (SMap.count(A[++start]) == 0);
				}
			}
		}
		end++;
	}

	return ret;
}
#else
string MinWindow(string S, string T) {
	if (S.length() < T.length()) return "";
	unordered_map<char, int> counts;
	for (int i = 0; i < T.length(); i++) {
		if (counts.find(T[i]) == counts.end()) {
			counts[T[i]] = 1;
		}
		else {
			counts[T[i]]++;
		}
	}
	int start = 0;
	int length = 0;
	int total = 0;
	for (int head = 0, tail = 0; tail < S.length(); tail++) {
		auto itTail = counts.find(S[tail]);
		if (counts.find(S[tail]) == counts.end()) {
			// If this character is not present in T at all, 
			// we don't care about this character. 
			continue;
		}
		counts[S[tail]]--;
		// We check if the current character represented by tail caused
		// a character to be included which is relevant to T and is still
		// in deficit. 
		// For example, if T has 3 As, then the first 3 A are relevant to us
		// but the 4th one is not. 
		if (counts[S[tail]] >= 0) {
			total++;
		}
		// check if we have all characters in T covered. 
		if (total == T.size()) {
			// Now move the head pointer till popping out those characters 
			// still makes sure that all characters in T are covered. 
			while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
				if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
				head++;
			}
			// Now [head - 1, tail] is a valid substring. Update the answer. 
			if (length == 0 || tail - head + 1 < length) {
				length = tail - head + 1;
				start = head;
			}
		}
	}
	return S.substr(start, length);
}
#endif