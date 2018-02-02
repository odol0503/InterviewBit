#include <vector>
#include <algorithm>
using namespace std;

double MediaArraySameSize(const vector<int> &A, const vector<int> &B)
{
	if (A.size() != B.size()) return -1;
	int len = (int)A.size();

	vector<int> C(A);
	vector<int> D(B);

	while (len > 1)
	{
		len /= 2;
		if (C[len] < D[len])
		{
			C.assign(C.begin() + len, C.end());
			D.assign(D.begin(), D.begin() + len + 1);
		}
		else
		{
			C.assign(C.begin(), C.begin() + len + 1);
			D.assign(D.begin() + len, D.end());
		}
	}

	return (double)((max(C[0], D[0]) + min(C[1], D[1])) / 2.0f);
}