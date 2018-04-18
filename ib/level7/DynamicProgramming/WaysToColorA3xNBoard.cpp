/*************************************************************************************************
Ways to color a 3xN Board

Given a 3Xn board, find the number of ways to color it using at most 4 colors such 
that no two adjacent boxes have same color. Diagonal neighbors are not treated as adjacent boxes.
Output the ways%1000000007 as the answer grows quickly.

1<= n < 100000

Example:
Input: n = 1
Output: 36
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <array>

using namespace std;

#define OWN2

#define MOD 1000000007LL

#ifdef OWN1
static bool checkValid(int i, int j, int color, vector<vector<int>> &board)
{
	if (i > 0 && board[i - 1][j] == color) return false;
	if (j > 0 && board[i][j - 1] == color) return false;
	return true;
}

static int getEmpty(vector<vector<int>> &board, int A, int i1, int j1, int &i2, int &j2)
{
	if (i1 == 2)
	{
		i2 = 0;
		j2 = j1 + 1;
	}
	else
	{
		i2 = i1 + 1;
		j2 = j1;
	}

	return 1;
}

static int getCnt(int A, int i, int j, vector<vector<int>> &board)
{
	int cnt = 0;

	for (int c = 1; c <= 4; c++)
	{
		if (checkValid(i, j, c, board) == false) continue;

		board[i][j] = c;

		if (i == 2 && j == A - 1)
		{
			cnt++;
			continue;
		}

		int i2 = 0, j2 = 0;
		getEmpty(board, A, i, j, i2, j2);
		cnt = (cnt + getCnt(A, i2, j2, board)) % MOD;
		board[i][j] = -1;
	}

	return cnt;
}

int WaysToColorA3xNBoard(int A) {
	int cnt = 0;
	vector<vector<int>> board(3, vector<int>(A, -1));
	return getCnt(A, 0, 0, board);
}
#elif defined(OWN2)
#define MOD 1000000007LL

class Triplet
{
public:
	int a;
	int b;
	int c;

	Triplet(int a, int b, int c):a(a), b(b), c(c) { }
};

void make1stCol(vector<Triplet*> &C)
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (i != j)
			{
				for (int k = 0; k<4; k++)
				{
					if (j != k)
					{
						C.push_back(new Triplet(i, j, k));
					}
				}
			}
		}
	}
}

bool checkValid(const Triplet *A, const Triplet *B)
{
	if (A->a != B->a && A->b != B->b && A->c != B->c)
	{
		return true;
	}
	return false;
}

int WaysToColorA3xNBoard(int A) {
	vector<Triplet*> C;

	make1stCol(C);

	if (A == 1) return (int)C.size();

	map<Triplet*, long long> M1;
	map<Triplet*, long long> M2;
	for (int i = 0; i < (int)C.size(); i++)
	{
		M1[C[i]] = 1;
		M2[C[i]] = 0;
	}

	int clen = (int)C.size();

	for (int i = 1; i < A; i++)
	{
		for (auto it1 = M1.begin(); it1 != M1.end(); it1++)
		{
			for (auto it2=M2.begin(); it2!=M2.end(); it2++)
			{
				if (checkValid(it1->first, it2->first))
				{
					M2[it2->first] = (M2[it2->first] + it1->second) % MOD;
				}
			}
		}

		M1.swap(M2);
		for (auto it = M2.begin(); it != M2.end(); it++) it->second = 0;
	}

	long long sum = 0;
	for (auto it=M1.begin(); it!=M1.end(); it++)
	{
		sum = (sum + it->second) % MOD;
	}

	return (int)sum;
}
#else
#define mod 1000000007
#define ll long long

struct triplet {
	int x, y, z;
};

vector<triplet> trip;  //vector of 36 triplets

void fillTriplets() {
	//trip vector contain the triplets of color that can be used to paint a certain column
	trip.clear();
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			for (int k = 0; k<4; k++) {
				if (i != j && j != k) trip.push_back({ i,j,k });
			}
		}
	}
}

int dp[4][4][4][100005];
bool isCompatible(const triplet& t1, const triplet& t2) {
	//check if triplets t1 and t2 are compatible
	if (t1.x == t2.x || t1.y == t2.y || t1.z == t2.z) {
		return 0;
	}
	return 1;
}

int Solution::solve(int n) {
	fillTriplets();
	if (n <= 0) return -1;

	//Bottom-up dp
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j<36; j++) {
			if (i == 1) dp[trip[j].x][trip[j].y][trip[j].z][i] = 1;
			else {
				ll temp = 0;

				for (int k = 0; k<36; k++) {
					if (isCompatible(trip[j], trip[k])) {
						temp += dp[trip[k].x][trip[k].y][trip[k].z][i - 1];
						temp %= mod;
					}
				}
				dp[trip[j].x][trip[j].y][trip[j].z][i] = temp;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i<trip.size(); i++) {
		ans = (ans + dp[trip[i].x][trip[i].y][trip[i].z][n]) % mod;
	}
	int res = ans;

	return ans;
}
#endif