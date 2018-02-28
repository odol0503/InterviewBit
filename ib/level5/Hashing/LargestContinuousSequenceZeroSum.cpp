/*************************************************************************************************
Largest Continuous Sequence Zero Sum

Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<int> LargeSequenceZero(vector<int> &A) {
	int len = (int)A.size();
	int tsum = 0;
	vector<int> ret;
	vector<vector<int>> temp;
	unordered_map<int, int> lsum;

	lsum.insert({ 0, -1 });

	for (int i = 0; i < len; i++)
	{
		tsum += A[i];
		auto val = lsum.find(tsum);
		if (val != lsum.end())
		{
			ret.assign((A.begin() + 1 + val->second), (A.begin() + i + 1));
			temp.push_back(ret);
			continue;
		}
		lsum.insert({ tsum, i });
	}

	int max_len = 0;
	int max_idx = -1;
	for (int i = 0; i < (int)temp.size(); i++)
	{
		if (max_len < (int)temp[i].size())
		{
			max_len = (int)temp[i].size();
			max_idx = i;
		}
	}

	if (max_idx < 0) return vector<int>();

	return temp[max_idx];
}
#else
vector<int> LargeSequenceZero(vector<int> &sequence) {

	int N = sequence.size();
	vector<int> sum;
	if (N == 0)
		return sum; // empty vector

	sum.push_back(sequence[0]);

	for (int i = 1; i < N; ++i) {
		sum.push_back(sequence[i] + sum[i - 1]);
	}

	int start = 0;
	int end = 0;
	map<int, int> hash;
	for (int i = 0; i < N; ++i) {
		if (sum[i] == 0) {
			int temp_start = 0;
			int temp_end = i + 1;
			if (temp_end - temp_start >= end - start) {
				start = temp_start;
				end = temp_end;
			}
		}
		else {
			if (hash.find(sum[i]) != hash.end()) {
				int temp_start = hash[sum[i]] + 1;
				int temp_end = i + 1;
				if (temp_end - temp_start > end - start) {
					start = temp_start;
					end = temp_end;
				}
				else if (temp_end - temp_start == end - start && temp_start < start) {
					start = temp_start;
					end = temp_end;
				}
			}
			else {
				hash[sum[i]] = i;
			}
		}
	}

	vector<int> ans;

	for (int i = start; i < end; ++i) {
		ans.push_back(sequence[i]);
	}

	return ans;
	}
#endif