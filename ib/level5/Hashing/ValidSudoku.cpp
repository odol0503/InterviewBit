/*************************************************************************************************
Valid Sudoku

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
The Sudoku board could be partially filled, where empty cells are filled with the character ¡®.¡¯.

The input corresponding to the above configuration :
["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

#ifdef OWN
static int RowHash[9][9];
static int ColHash[9][9];
static int BlockHash[3][3][9];

static bool CheckValid(int row, int col, char val)
{
	if (RowHash[row][val-'1'] || ColHash[col][val - '1'] || BlockHash[row / 3][col / 3][val - '1']) return false;
	return true;
}

int IsValidSudoku(const vector<string> &A) {
	vector<string> B(A);

	memset(RowHash, 0x00, sizeof(RowHash));
	memset(ColHash, 0x00, sizeof(ColHash));
	memset(BlockHash, 0x00, sizeof(BlockHash));

	for (int i = 0; i < (int)A.size(); i++)
	{
		for (int j = 0; j < (int)A.size(); j++)
		{
			if (A[i][j] != '.')
			{
				if (CheckValid(i, j, A[i][j]) == false) return 0;

				RowHash[i][A[i][j] - '1'] = 1;
				ColHash[j][A[i][j] - '1'] = 1;
				BlockHash[i/3][j/3][A[i][j] - '1'] = 1;
			}
		}
	}
	return 1;
}
#else
int IsValidSudoku(const vector<string> &board) {
	bool r[9][9], c[9][9], s[3][3][9];
	memset(r, false, sizeof(r));
	memset(c, false, sizeof(c));
	memset(s, false, sizeof(s));
	int number;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] > '0' && board[i][j] <= '9') {
				number = board[i][j] - '1';
				if (r[i][number]) return false;
				r[i][number] = true;
				if (c[j][number]) return false;
				c[j][number] = true;
				if (s[i / 3][j / 3][number]) return false;
				s[i / 3][j / 3][number] = true;
			}
		}
	}
	return true;
}
#endif