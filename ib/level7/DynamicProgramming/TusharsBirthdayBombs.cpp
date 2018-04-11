/*************************************************************************************************
Largest area of rectangle with permutations

Given a binary grid i.e. a 2D grid only consisting of 0¡¯s and 1¡¯s, find the area of
the largest rectangle inside the grid such that all the cells inside the chosen rectangle
should have 1 in them. You are allowed to permutate the columns matrix i.e.
you can arrange each of the column in any order in the final grid.
Please follow the below example for more clarity.

Lets say we are given a binary grid of 3 * 3 size.
1 0 1
0 1 0
1 0 0

At present we can see that max rectangle satisfying the criteria mentioned in the problem
is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it.
Now since we are allowed to permutate the columns of the given matrix,
we can take column 1 and column 3 and make them neighbours.
One of the possible configuration of the grid can be:
1 1 0
0 0 1
1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column
is column 2 from the original given grid. Now, we can see that if we calculate the max
area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case.
Hence 2 will be the answer in this case.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

#ifdef OWN
void kick(int A, vector<int> &B, int pos, vector<int> &list, vector<int> &ret)
{
	for (int i = pos; i<(int)B.size(); i++)
	{
		if (A - B[i] < 0)
		{
			if (list.size() > ret.size()) ret.assign(list.begin(), list.end());
			continue;
		}
		list.push_back(i);
		kick(A - B[i], B, i, list, ret);
		list.pop_back();
	}
}

vector<int> TusharsBirthdayBombs(int A, vector<int> &B) {
	vector<int> list;
	vector<int> ret;
	kick(A, B, 0, list, ret);
	int max_len = 0;
	int max_idx = -1;
	return ret;
}
#else

#endif