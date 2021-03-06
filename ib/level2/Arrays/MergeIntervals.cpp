/*************************************************************************************************
Merge Intervals

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#if 0
vector<Interval> MergeIntervals(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> ret;
	int n = static_cast<int>(intervals.size());
	int s = -1;
	int e = -1;

	if (newInterval.start > newInterval.end)
	{
		int temp = newInterval.start;
		newInterval.start = newInterval.end;
		newInterval.end = temp;
	}

	if (n == 0)
	{
		ret.push_back(newInterval);
		return ret;
	}

	int prev_end = 0;
	int i = 0;
	while (i < n)
	{
		if (prev_end < newInterval.start && newInterval.start < intervals[i].start)
		{
			s = newInterval.start;
			break;
		}
		else if (intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)
		{
			s = intervals[i].start;
			break;
		}
		else
		{
			ret.push_back(intervals[i]);
			prev_end = intervals[i++].end;
		}
	}

	while (i < n)
	{
		if (prev_end < newInterval.end && newInterval.end < intervals[i].start)
		{
			e = newInterval.end;
			ret.push_back(Interval(s, e));
			break;
		}
		else if (intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end)
		{
			e = intervals[i++].end;
			ret.push_back(Interval(s, e));
			break;
		}
		prev_end = intervals[i++].end;
	}

	while (i < n)
	{
		ret.push_back(intervals[i++]);
	}

	if (e == -1)
	{
		if (s == -1) ret.push_back(newInterval);
		else ret.push_back(Interval(s, newInterval.end));
	}
	
	return ret;
}
#else
bool doesIntersect(Interval a, Interval b) {
	if (min(a.end, b.end) < max(a.start, b.start)) return false;
	return true;
}

vector<Interval> MergeIntervals(vector<Interval> &intervals, Interval newInterval) {
	int sz = static_cast<int>(intervals.size());
	vector<Interval> result;

	// check corner cases
	// Case : Empty intervals array
	if (sz == 0) {
		result.push_back(newInterval);
		return result;
	}
	// Case : newInterval comes at the beginning or at the end without overlap 
	if (newInterval.start > intervals[sz - 1].end || newInterval.end < intervals[0].start) {
		if (newInterval.end < intervals[0].start) {
			result.push_back(newInterval);
		}
		for (int i = 0; i < sz; i++) {
			result.push_back(intervals[i]);
		}
		if (newInterval.start > intervals[sz - 1].end) {
			result.push_back(newInterval);
		}
		return result;
	}
	for (int i = 0; i < sz; i++) {
		bool intersect = doesIntersect(intervals[i], newInterval);
		if (!intersect) {
			result.push_back(intervals[i]);
			// check if newInterval lies between intervals[i] and intervals[i+1]
			if (i < sz - 1 && newInterval.start > intervals[i].end && newInterval.end < intervals[i + 1].start) {
				result.push_back(newInterval);
			}
			continue;
		}
		// Now we know the interval overlaps. Lets find out how many intervals overlap. 
		int st = i;
		while (i < sz && intersect) {
			i++;
			if (i == sz) intersect = false;
			else {
				intersect = doesIntersect(intervals[i], newInterval);
			}
		}
		i--;
		// Now all intervals from st to i overlap. 
		Interval toInsert(min(newInterval.start, intervals[st].start), max(newInterval.end, intervals[i].end));
		result.push_back(toInsert);
	}
	return result;
}
#endif