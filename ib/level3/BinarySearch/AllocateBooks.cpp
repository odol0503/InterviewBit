/*************************************************************************************************
Allocate Books

N number of books are given.
The ith book has Pi number of pages.
You have to allocate books to M number of students so that maximum number of pages alloted 
to a student is minimum. A book will be allocated to exactly one student. 
Each student has to be allocated at least one book. Allotment should be in contiguous order, 
for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:
List of Books
M number of students
Your function should return an integer corresponding to the minimum number.

Example:
P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion :
1) [12] and [34, 67, 90]
Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
2) [12, 34] and [67, 90]
Max number of pages is allocated to student 2 with 67 + 90 = 157 pages
3) [12, 34, 67] and [90]
Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static bool isPossible(vector<int> &A, int B, int page)
{
	int max_value = *max_element(A.begin(), A.end());

	if (max_value > page) return false;

	int students = 1;
	int sum = 0;
	for (int i=0; i<(int)A.size();)
	{
		if (sum + A[i] > page)
		{
			students++;
			sum = 0;
		}
		else
		{
			sum += A[i];
			i++;
		}
	}

	if (students > B) return false;
	return true;
}

int AllocateBooks(vector<int> &A, int B)
{
	if ((int)A.size() < B) return -1;

	int ret;
	int start = 0;
	int end = 0;
	int mid;

	for (auto a : A) end += a;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (isPossible(A, B, mid))
		{
			ret = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	return ret;
}
#else
static bool isPossible(vector<int> &V, int M, int curMin) {
	int studentsRequired = 1;
	int curSum = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] > curMin) return false;
		if (curSum + V[i] > curMin) {
			studentsRequired++;
			curSum = V[i];
			if (studentsRequired > M) return false;
		}
		else {
			curSum += V[i];
		}
	}
	return true;
}

int AllocateBooks(vector<int> &Vec, int M) 
{
	long long sum = 0;
	int N = (int)Vec.size();

	if (N < M)
		return -1;

	for (int i = 0; i < N; ++i) {
		sum += Vec[i];
	}

	long long start = 0;
	long long end = sum, mid;
	int ans = INT_MAX;
	while (start <= end) {
		mid = (start + end) / 2;
		if (isPossible(Vec, M, mid)) {
			ans = min(ans, (int)mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return ans;
}
#endif