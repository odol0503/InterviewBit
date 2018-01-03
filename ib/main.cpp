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

int main()
{
	vector<string> A = { "0.503094", "0.648924", "0.999298" };
	vector<int> ans;
	int ans2;
	ans2 = Triplets(A);
	return 0;
}