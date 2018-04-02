/*************************************************************************************************
Ways to form Max Heap

Max Heap is a special kind of complete binary tree in which for every node the value present 
in that node is greater than the value present in it¡¯s children nodes. 
If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:
How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :
Heap has to be a complete binary tree ( A complete binary tree is a binary tree 
in which every level, except possibly the last, is completely filled, 
and all nodes are as far left as possible. )

Every node is greater than all its children
Let us take an example of 4 distinct integers. 
Without loss of generality let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :
     4
    /  \
   3   2
  /
 1
    4
   /  \
  2   3
 /
1
    4
   /  \
  3   1
 /
2
These are the only possible 3 distinct max heaps possible for 4 distinct elements.
Implement the below function to return the number of distinct Max Heaps 
that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007
Input Constraints : n <= 100
NOTE: Note that even though constraints are mentioned for this problem, 
for most problems on InterviewBit, constraints are intentionally left out. 
In real interviews, the interviewer might not disclose constraints 
and ask you to do the best you can do.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <iostream>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007

long long Fact(int A)
{
	long long val = 1;
	for (long long i = 2; i <= A; i++)
	{
		val = (val * i) % MOD;
	}
	return val;
}

long long Combination(int A, int B)
{
	return Fact(A) / ((Fact(A - B) * Fact(B)) % MOD);
}

int WaysToFormMaxHeap(int A) {
	int h = 0;
	if (A < 2) return 1;
	int temp = A;
	while (temp > 1)
	{
		temp /= 2;
		h++;
	}

	int m = pow(2, h);
	int p = A - (m - 1);
	int L = 0;

	if (p < m / 2)
	{
		L = m - 1 - (m / 2 - p);
	}
	else
	{
		L = m - 1;
	}

	return (int)(Fact(A - 1) / ((Fact(L) * Fact(A - 1 - L)) % MOD))*WaysToFormMaxHeap(L)*WaysToFormMaxHeap(A - 1 - L);
}
#else

#endif