/*************************************************************************************************
Merge Overlapping Intervals

Given a collection of intervals, merge all overlapping intervals.
For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#ifdef OWN
bool OverLapping(Interval A, Interval B)
{
	if (min(A.end, B.end) < max(A.start, B.start)) return false;
	return true;
}

bool CompInterval(Interval A, Interval B)
{
	return A.start < B.start;
}

vector<Interval> MergeOverlappingIntervals(vector<Interval> &A)
{
	vector<Interval> ret;
	int len = static_cast<int>(A.size());

	sort(A.begin(), A.end(), CompInterval);

	Interval temp;
	bool overlapped = false;
	for (int i = 0; i < len; i++)
	{
		if (overlapped == false)
		{
			temp.start = A[i].start;
			temp.end = A[i].end;
		}

		if (i != len - 1
			&& OverLapping(temp, A[i + 1]))
		{
			if (overlapped == false) temp.start = A[i].start;
			temp.end = max(temp.end, A[i+1].end);
			overlapped = true;
			continue;
		}

		if (overlapped == true)
		{
			ret.push_back(Interval(temp));
			overlapped = false;
			continue;
		}

		ret.push_back(A[i]);
	}

	return ret;
}
#else
bool myCmp(Interval a, Interval b) {
	return a.start < b.start;
}

vector<Interval> MergeOverlappingIntervals(vector<Interval> &intervals)
{
	if (intervals.size() < 2) {
		return intervals;
	}
	sort(intervals.begin(), intervals.end(), myCmp);
	int first = 0;
	for (int second = 1; second < intervals.size(); second++) {
		// There is overlap in intervals at first and second position.
		if (intervals[second].start <= intervals[first].end) {
			// We merge the second interval into the first one and modify the first interval to reflect it. 
			intervals[first].end = max(intervals[second].end, intervals[first].end);
		}
		else {
			// No overlap between first and second. Move forward. 
			++first;
			intervals[first].start = intervals[second].start;
			intervals[first].end = intervals[second].end;
		}
	}
	intervals.erase(intervals.begin() + first + 1, intervals.end());
	return intervals;
}
#endif