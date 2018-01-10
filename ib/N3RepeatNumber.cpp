/*************************************************************************************************
N / 3 Repeat Number

You¡¯re given a read only array of n integers. Find out if any integer occurs more than n/3 times
in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.
If there are multiple solutions, return any one.
Example :
Input : [1 2 3 1 1]
Output : 1
1 occurs 3 times which is more than 5/3 times.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int RepeatNumber(const vector<int> &A)
{
	int len = static_cast<int>(A.size());
	int slot[2] = { 0, 0 };
	int slot_cnt[2] = { 0, 0 };

	for (int i = 0; i < len; i++)
	{
		if (A[i] == slot[0])
		{
			slot_cnt[0]++;
		}
		else if (A[i] == slot[1])
		{
			slot_cnt[1]++;
		}
		else if (slot_cnt[0] == 0)
		{
			slot[0] = A[i];
			slot_cnt[0]++;
		}
		else if (slot_cnt[1] == 0)
		{
			slot[1] = A[i];
			slot_cnt[1]++;
		}
		else
		{
			slot_cnt[0]--;
			slot_cnt[1]--;
		}
	}

	slot_cnt[0] = slot_cnt[1] = 0;
	for (int i = 0; i < len; i++)
	{
		if (slot[0] == A[i]) slot_cnt[0]++;
		if (slot[1] == A[i]) slot_cnt[1]++;
	}

	if (slot_cnt[0] > len / 3) return slot[0];
	if (slot_cnt[1] > len / 3) return slot[1];

	return -1;
}
#else
struct eleCount {
	int e; // Element
	int c; // Count
};

int RepeatNumber(const vector<int> &V)
{
	if (V.size() == 0) return -1;

	/* Step 1: Create a temporary array (contains element
	and count) of size 2. Initialize count of all
	elements as 0 */
	struct eleCount temp[2];
	temp[0].c = temp[1].c = 0;

	/* Step 2: Process all elements of input array */
	for (int i = 0; i < V.size(); i++) {
		int j;

		/* If arr[i] is already present in
		the element count array, then increment its count */
		if (temp[0].e == V[i] || temp[1].e == V[i]) {
			if (temp[0].e == V[i]) temp[0].c += 1;
			else temp[1].c += 1;
		}
		else {
			/* If arr[i] is not present in temp[] */
			int l;

			/* If there is position available in temp[], then place
			arr[i] in the first available position and set count as 1*/
			if (temp[0].c == 0 || temp[1].c == 0) {
				int index = (temp[0].c == 0) ? 0 : 1;
				temp[index].e = V[i];
				temp[index].c = 1;
			}
			else {
				/* If all the position in the temp[] are filled, then
				decrease count of every element by 1 */
				temp[0].c -= 1;
				temp[1].c -= 1;
			}
		}
	}

	/*Step 3: Check actual counts of potential candidates in temp[]*/
	for (int i = 0; i < 2; i++) {
		// Calculate actual count of elements 
		int ac = 0;  // actual count
		for (int j = 0; j < V.size(); j++)
			if (V[j] == temp[i].e)
				ac++;

		// If actual count is more than n/k, then print it
		if (ac > V.size() / 3) return temp[i].e;
	}
	// Not found
	return -1;
}
#endif
