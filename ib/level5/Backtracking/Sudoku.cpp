/*************************************************************************************************
Sudoku
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'
You may assume that there will be only one unique solution.

A sudoku puzzle,
and its solution numbers marked in red.

Example :
For the above given diagrams, the corresponding input to your program will be
[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to
[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static int RowHash[9][9];
static int ColHash[9][9];
static int BlockHash[3][3][9];

static bool CheckValid(int row, int col, char val)
{
	if (RowHash[row][val - '1'] || ColHash[col][val - '1'] || BlockHash[row / 3][col / 3][val - '1']) return false;
	return true;
}

static bool GetEmptyPos(const vector<vector<char> > &A, int &row, int &col)
{
	int len = (int)A.size();
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<len; j++)
		{
			if (A[i][j] == '.')
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

static int Sudoku(vector<vector<char> > &A)
{
	int row, col;
	if (GetEmptyPos(A, row, col) == false)
	{
		return 1;
	}

	for (char i = '1'; i <= '9'; i++)
	{
		if (CheckValid(row, col, i))
		{
			A[row][col] = i;
			RowHash[row][i - '1'] = 1;
			ColHash[col][i - '1'] = 1;
			BlockHash[row / 3][col / 3][i - '1'] = 1;
			if (Sudoku(A)) return 1;
			A[row][col] = '.';
			RowHash[row][i - '1'] = 0;
			ColHash[col][i - '1'] = 0;
			BlockHash[row / 3][col / 3][i - '1'] = 0;
		}
	}
	return 0;
}

void SolveSudoku(vector<vector<char> > &A) {

	memset(RowHash, 0x00, sizeof(RowHash));
	memset(ColHash, 0x00, sizeof(ColHash));
	memset(BlockHash, 0x00, sizeof(BlockHash));

	for (int i = 0; i < (int)A.size(); i++)
	{
		for (int j = 0; j < (int)A.size(); j++)
		{
			if (A[i][j] != '.')
			{
				RowHash[i][A[i][j] - '1'] = 1;
				ColHash[j][A[i][j] - '1'] = 1;
				BlockHash[i / 3][j / 3][A[i][j] - '1'] = 1;
			}
		}
	}

	Sudoku(A);
}
#else
int rowhash[9][9], colhash[9][9], blockhash[3][3][9];

bool solveSudoku(vector<vector<char> > &board, int position) {
	if (position >= 9 * 9) {
		return true;
	}
	int row = position / 9, col = position % 9;
	if (board[row][col] != '.') {
		return solveSudoku(board, position + 1);
	}
	for (int num = 0; num < 9; num++) {
		if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {
			// Include num in the solution 
			board[row][col] = '1' + num;
			rowhash[row][num] = 1;
			colhash[col][num] = 1;
			blockhash[row / 3][col / 3][num] = 1;
			if (solveSudoku(board, position + 1)) return true;
			// Reset
			board[row][col] = '.';
			rowhash[row][num] = 0;
			colhash[col][num] = 0;
			blockhash[row / 3][col / 3][num] = 0;
		}
	}
	return false;
}

void SolveSudoku(vector<vector<char> > &board) {
	memset(rowhash, 0, sizeof(rowhash));
	memset(colhash, 0, sizeof(colhash));
	memset(blockhash, 0, sizeof(blockhash));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				int num = board[i][j] - '1';
				rowhash[i][num] = 1;
				colhash[j][num] = 1;
				blockhash[i / 3][j / 3][num] = 1;
			}
		}
	}
	solveSudoku(board, 0);
}
#endif