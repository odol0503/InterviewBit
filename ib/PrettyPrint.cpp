/*************************************************************************************************
Pretty Print

Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
Example 2:

Input: A = 3.
Output:

3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
*************************************************************************************************/
#include <vector>
using namespace std;

vector<vector<int>> PrettyPrint(int A) 
{
	vector<vector<int>> B(2 * A - 1, vector<int>(2 * A - 1, 0));
	int tlen = (int)pow(2 * A - 1, 2);
	int len = 2 * A - 1;
	int dir = 0;
	int num = A;
	int x = 0, y = 0;
	for (int i = 0; i<tlen; i++)
	{
		B[y][x] = num;

		switch (dir)
		{
		case 0:
			x++;
			if (x > len - 1 || B[y][x] != 0)
			{
				x--;
				y++;
				dir = 1;
				break;
			}
			break;

		case 1:
			y++;
			if (y > len - 1 || B[y][x] != 0)
			{
				x--;
				y--;
				dir = 2;
				break;
			}
			break;

		case 2:
			x--;
			if (x < 0 || B[y][x] != 0)
			{
				x++;
				y--;
				dir = 3;
				break;
			}
			break;

		case 3:
			y--;
			if (y < 0 || B[y][x] != 0)
			{
				x++;
				y++;
				dir = 0;
				num--;
				break;
			}
			break;
		}
	}
	return B;
}