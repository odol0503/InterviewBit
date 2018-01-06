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
void RotateMatrix(vector<vector<int> > &A);

int main()
{
	vector<vector<int>> A = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<int> ans;
	int ans2;
	bool ans3;
	string ret;
	RotateMatrix(A);
	return 0;
}