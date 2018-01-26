#include "pch.h"
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> SpialOrderMatrix(int A);
vector<vector<int>> PascalTriangle(int A);
vector<int> KthPascalTriangle(int A);
vector<vector<int>> AntiDiagonal(vector<vector<int> > &A);
int NobleInteger(vector<int> &A);
vector<int> WaveArray(vector<int> &A);
int Triplets(vector<string> &A);
string LargestNumber(const vector<int> &A);
bool HotelBooking(vector<int> &arrive, vector<int> &depart, int K);
int MaxDistance(const vector<int> &A);
vector<int> MaxUnsortedSubarray(vector<int> &A);
int FindDuplicate(vector<int> &A);
vector<int> PrimeSum(int A);
void RotateMatrix(vector<vector<int> > &A);
void NextPermutation(vector<int> &A);
vector<int> FindPermutation(const string A, int B);
int RepeatNumber(const vector<int> &A);
int MaxConsecutiveGap(const vector<int> &A);

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> MergeIntervals(vector<Interval> &intervals, Interval newInterval);
vector<Interval> MergeOverlappingIntervals(vector<Interval> &A);
void SetMatrixZeros(vector<vector<int> > &A);
int FirstMissingInteger(vector<int> &A);
int HammingDistance(const vector<int> &A);
vector<string> FizzBuzz(int A);
int IsPower(int A);
int TitleToNumber(string A);
string ConvertToTitle(int A);
int IsPalindrome(int A);
int ReverseInt(int A);
int GCD(int A, int B);
int TrailingZeroes(int A);
int FindPermutationRank(string A);
int CoprimeDivisor(int A, int B);
int FindPermutationRank2(string A);
int UniquePaths(int A, int B);
void RearrangeArray(vector<int> &A);
int NumbersOfLengthN(vector<int> &A, int B, int C);
int MatrixMedian(vector<vector<int> > &A);
void qsort(vector<int> &A, int left, int right);
vector<vector<int> > PrettyPrint(int A);
int SqrtInt(int A);
vector<int> SearchRange(const vector<int> &A, int B);
int PainterPartionProblem(int A, int B, vector<int> &C);

TEST(IB, FindDuplicate) {
  vector<int> A = { 442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500 };
  EXPECT_EQ(540, FindDuplicate(A));
}

TEST(IB, NumbersOfLengthN) {
	vector<int> A = { 0, 1, 2, 5 };
	EXPECT_EQ(5, NumbersOfLengthN(A, 2, 21));
}

TEST(IB, MatrixMedian) {
	vector<vector<int>> A = { {1, 3, 5}, {2, 6, 9}, {3, 6, 9} };
	EXPECT_EQ(5, MatrixMedian(A));
	vector<vector<int>> B = { {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3} };
	EXPECT_EQ(2, MatrixMedian(B));
	vector<vector<int>> C = { { 1, 1, 3, 3, 3, 3, 3} };
	EXPECT_EQ(3, MatrixMedian(C));
	vector<vector<int>> D = { {4} , {2}, {5} };
	EXPECT_EQ(4, MatrixMedian(D));
};

TEST(IB, qsort) {
	vector<int> A = { 5, 4, 7, 3, 2, 6 };
	vector<int> B(A);
	sort(B.begin(), B.end());
	qsort(A, 0, (int)A.size() - 1);
	EXPECT_EQ(A, B);
	vector<int> C = { 1, 1, 1, 1, 1, 2 };
	qsort(C, 0, (int)C.size() - 1);
	EXPECT_EQ(C, C);
	vector<int> D = { 9,8,7,6,5,4,3,2,1,0 };
	vector<int> E(D);
	sort(E.begin(), E.end());
	qsort(D, 0, (int)D.size() - 1);
	EXPECT_EQ(D, E);
}
TEST(IB, PrettyPrint) {
	vector<vector<int>> ret = { { 3,3,3,3,3 },{ 3,2,2,2,3 },{ 3,2,1,2,3 },{ 3,2,2,2,3 },{ 3,3,3,3,3 } };
	EXPECT_EQ(ret, PrettyPrint(3));
}

TEST(IB, SqrtInt) {
	//EXPECT_EQ(0, SqrtInt(0));
	//EXPECT_EQ(1, SqrtInt(2));
	EXPECT_EQ(1, SqrtInt(6));
	//EXPECT_EQ(1, SqrtInt(15));
	//EXPECT_EQ(1, SqrtInt(25));
	//EXPECT_EQ(1, SqrtInt(37));
	//EXPECT_EQ(1, SqrtInt(67035753));
	//EXPECT_EQ(1, SqrtInt(930675566));
TEST(IB, SearchRange) {
	EXPECT_EQ(vector<int>({ 3,4 }), SearchRange({ 5, 7, 7, 8, 8, 10 }, 8));
	EXPECT_EQ(vector<int>({ 0, 0 }), SearchRange({ 1 }, 1)); 
	EXPECT_EQ(vector<int>({ 118, 133 }), SearchRange({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }, 10));
	EXPECT_EQ(vector<int>({ 98, 140 }), SearchRange({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }, 3));
}

TEST(IB, PainterPartionProblem) {
	EXPECT_EQ(50, PainterPartionProblem(2, 5, vector<int>({ 1,10 })));
	EXPECT_EQ(9140, PainterPartionProblem(5, 10, vector<int>({ 658, 786, 531, 47, 169, 397, 914 })));
	EXPECT_EQ(8990, PainterPartionProblem(6, 10, vector<int>({ 762, 798, 592, 899, 329 })));
	EXPECT_EQ(8890, PainterPartionProblem(4, 10, vector<int>({ 884, 228, 442, 889 })));
	EXPECT_EQ(9400003, PainterPartionProblem(1, 1000000, vector<int>({ 1000000, 1000000 })));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

