#include <vector>
#include <string>
using namespace std;

vector<vector<int>> SpialOrderMatrix(int A);
vector<vector<int>> PascalTriangle(int A);
vector<int> KthPascalTriangle(int A);
vector<vector<int>> AntiDiagonal(vector<vector<int> > &A);
int NobleInteger(vector<int> &A);
vector<int> WaveArray(vector<int> &A);
int Triplets(vector<string> &A);
string LargestNumber(const vector<int> &A);
bool HotelBooking(vector<int> &arrive, vector<int> &depart, int K);
int MaxDistance(const vector<int> &A);
vector<int> MaxUnsortedSubarray(vector<int> &A);
int FindDuplicate(vector<int> &A);
vector<int> PrimeSum(int A);

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> MergeIntervals(vector<Interval> &intervals, Interval newInterval);

int main()
{
#if 0
	vector<Interval> A = {
		Interval(6037774, 6198243), Interval(6726550, 7004541), Interval(8842554, 10866536), Interval(11027721, 11341296), Interval(11972532, 14746848),
		Interval(16374805, 16706396), Interval(17557262, 20518214), Interval(22139780, 22379559), Interval(27212352, 28404611), Interval(28921768, 29621583),
		Interval(29823256, 32060921), Interval(33950165, 36418956), Interval(37225039, 37785557), Interval(40087908, 41184444), Interval(41922814, 45297414),
		Interval(48142402, 48244133), Interval(48622983, 50443163), Interval(50898369, 55612831), Interval(57030757, 58120901), Interval(59772759, 59943999),
		Interval(61141939, 64859907), Interval(65277782, 65296274), Interval(67497842, 68386607), Interval(70414085, 73339545), Interval(73896106, 75605861),
		Interval(79672668, 84539434), Interval(84821550, 86558001), Interval(91116470, 92198054), Interval(96147808, 98979097), Interval(36210193, 61984219) };
	Interval B = { Interval(36210193, 61984219) };
#else
	vector<Interval> A = { Interval(3, 5), Interval(8, 10) };
	Interval B = { Interval(1, 12) };
#endif
	vector<int> ans;
	int ans2;
	bool ans3;
	string ret;
	vector<Interval>ret2;
	ret2 = MergeIntervals(A, B);
	return 0;
}