/*************************************************************************************************
NQueens

The n-queens puzzle is the problem of placing n queens on an n¡¿n chessboard 
such that no two queens attack each other.

N Queens: Example 1
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens¡¯ placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
bool CheckQueen(int A, int row, int col, vector<string> &subset)
{
	for (int i = 0; i<row; i++)
	{
		if (subset[i][col] == 'Q') return false;
		else if (col - row + i >= 0 && subset[i][col - row + i] == 'Q') return false;
		else if (col + row - i<A && subset[i][col + row - i] == 'Q') return false;
	}
	return true;
}

void PlaceQueen(int A, int row, vector<vector<string>> &comb)
{
	if (A == row) return;

	vector<string> sub;
	if (!comb.empty())
	{
		sub = comb.back();
		comb.pop_back();
	}
	else
	{
		sub.resize(A);
		for (int i = 0; i<A; i++)
		{
			for (int j = 0; j < A; j++) sub[i].push_back('.');
		}
	}

	for (int x = 0; x<A; x++)
	{
		if (CheckQueen(A, row, x, sub))
		{
			sub[row][x] = 'Q';
			comb.push_back(sub);
			PlaceQueen(A, row + 1, comb);
			sub[row][x] = '.';
		}
	}
}

vector<vector<string> > NQueens(int A) {
	vector<vector<string>> ret;
	PlaceQueen(A, 0, ret);
	return ret;
}
#else
vector<string> solToStrings(const vector<int>& sol) {
	int n = sol.size();
	vector<string> sol_strings(n);
	for (int i = 0; i < n; ++i) {
		sol_strings[i] = string(n, '.');
		sol_strings[i][sol[i]] = 'Q';
	}
	return sol_strings;
}

bool isAvailable(const vector<int> &solution, int i, int j) {
	for (int k = 0; k < i; ++k) {
		if (j == solution[k] || i + j == k + solution[k] || i - j == k - solution[k]) return false;
	}
	return true;
}

void solveNQueensImpl(int row, vector<int> &solution, vector<vector<string> > &solutions) {
	int n = solution.size();
	if (row == n) {
		solutions.push_back(solToStrings(solution));
		return;
	}
	// For each column...
	for (int j = 0; j < n; ++j) {
		// Skip if there is another queen in this column or diagonals
		if (isAvailable(solution, row, j)) {
			solution[row] = j;
			solveNQueensImpl(row + 1, solution, solutions);
		}
	}
}

vector<vector<string> > NQueens(int n) {
	vector<vector<string> > solutions;
	vector<int> solution(n);
	solveNQueensImpl(0, solution, solutions);
	return solutions;
}
#endif