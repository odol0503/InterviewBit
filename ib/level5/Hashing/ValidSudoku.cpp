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

#endif