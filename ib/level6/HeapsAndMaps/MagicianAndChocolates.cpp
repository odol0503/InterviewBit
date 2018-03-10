/*************************************************************************************************
Magician and Chocolates

Given N bags, each bag contains Ai chocolates. There is a kid and a magician.
In one unit of time, kid chooses a random bag i, eats Ai chocolates,
then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,
K = 3
N = 2
A = 6 5

Return: 14
At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7
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

#define OWN6

#ifdef OWN
#define MOD (int)(1e9+7)

int MagicianAndChocolates(int A, vector<int> &B) {
	long long ret = 0;
	priority_queue<long long> P;
	for (auto b : B) P.push(b);

	for (int i = 0; i<A; i++)
	{
		long long temp = 0;
		temp = P.top();
		ret = (ret + temp) % MOD;
		P.pop();
		P.push(temp / 2);
	}

	return (int)ret;
}
#else
long long int mod = 1000000007;
int MagicianAndChocolates(int A, vector<int> &B) {
	int N = B.size();
	int K = A;
	long long int ans = 0;
	priority_queue<int> heap(B.begin(), B.end());
	while (K--) {
		long long int max_elem = heap.top();
		ans += max_elem;
		ans = ans % mod;
		heap.pop();
		heap.push((int)(max_elem / 2));
	}
	return ans;
}
#endif