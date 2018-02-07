/*************************************************************************************************
Compare Version Numbers

Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int CompareVersion(string A, string B) {
	string::size_type a = 0, b = 0;
	string::size_type pos1 = 0;
	string::size_type pos2 = 0;
	string val1, val2;

	while (a != string::npos || b != string::npos)
	{
		a = A.find(".", pos1);
		b = B.find(".", pos2);

		if (a == string::npos)
		{
			if (pos1 == string::npos) val1 = "0";
			else val1 = A.substr(pos1, string::npos);
		}
		else val1 = A.substr(pos1, a);

		if (b == string::npos)
		{
			if (pos2 == string::npos) val2 = "0";
			else val2 = B.substr(pos2, string::npos);
		}
		else val2 = B.substr(pos2, b);

		double temp = stold(val1) - stold(val2);
		if (temp < 0) return -1;
		else if (temp > 0) return 1;

		if (a != string::npos) pos1 = a + 1;
		else pos1 = a;

		if (b != string::npos) pos2 = b + 1;
		else pos2 = b;
	}

	return 0;
}
#else
#include <string.h>
int CompareVersion(string A, string B) {
	string C = "", D = "";
	int a = A.size(), b = B.size(), afront = 0, bfront = 0, i;

	//removing 0 from front
	for (i = 0; i<a; i++) {
		if (A[i] != '0') {
			break;
		}
	}
	afront = i;

	for (i = 0; i<b; i++) {
		if (B[i] != '0') {
			break;
		}
	}
	bfront = i;


	// removing zero from end
	for (i = a - 1; i>0; i--) {
		if (A[i] != '0' && A[i] != '.') {
			break;
		}
	}
	a = i + 1;

	for (i = b - 1; i>0; i--) {
		if (B[i] != '0' && B[i] != '.') {
			break;
		}
	}
	b = i + 1;
	int n = 8;
	while (n--) {
		C = ""; D = "";
		for (i = afront; i< a; i++) {
			if (A[i] == '.')
				break;
			C += A[i];
		}
		afront = i + 1;

		for (i = bfront; i< b; i++) {
			if (B[i] == '.')
				break;
			D += B[i];
		}
		bfront = i + 1;

		// std::cout << "C: " << C << '\n';
		// std::cout << "D: " << D << '\n';

		if (C.size() == 0 && D.size() == 0) {
			break;
		}

		if (C.size()>D.size()) {
			// std::cout << 1 << '\n';
			return 1;
		}
		else if (C.size()<D.size()) {
			// std::cout << -1 << '\n';
			return -1;
		}
		else {
			for (i = 0; i<C.size(); i++) {
				if (C[i] > D[i]) {
					// std::cout << 1 << '\n';
					return 1;
				}
				else if (C[i] < D[i]) {
					// std::cout << -1 << '\n';
					return -1;
				}
			}
		}
	}
	// std::cout << "0" << '\n';
	return 0;
}
#endif