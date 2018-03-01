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

int FindDuplicate(vector<int> &A);
TEST(IB, FindDuplicate) {
  vector<int> A = { 442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500 };
  EXPECT_EQ(540, FindDuplicate(A));
}

int NumbersOfLengthN(vector<int> &A, int B, int C);
TEST(IB, NumbersOfLengthN) {
	vector<int> A = { 0, 1, 2, 5 };
	EXPECT_EQ(5, NumbersOfLengthN(A, 2, 21));
}

int MatrixMedian(vector<vector<int> > &A);
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

void qsort(vector<int> &A, int left, int right);
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

vector<vector<int> > PrettyPrint(int A);
TEST(IB, PrettyPrint) {
	vector<vector<int>> ret = { { 3,3,3,3,3 },{ 3,2,2,2,3 },{ 3,2,1,2,3 },{ 3,2,2,2,3 },{ 3,3,3,3,3 } };
	EXPECT_EQ(ret, PrettyPrint(3));
}

int SqrtInt(int A);
TEST(IB, SqrtInt) {
	EXPECT_EQ(0, SqrtInt(0));
	EXPECT_EQ(1, SqrtInt(2));
	EXPECT_EQ(2, SqrtInt(6));
	EXPECT_EQ(3, SqrtInt(15));
	EXPECT_EQ(5, SqrtInt(25));
	EXPECT_EQ(6, SqrtInt(37));
	EXPECT_EQ(8187, SqrtInt(67035753));
	EXPECT_EQ(30506, SqrtInt(930675566));
}

vector<int> SearchRange(const vector<int> &A, int B);
TEST(IB, SearchRange) {
	EXPECT_EQ(vector<int>({ 3,4 }), SearchRange({ 5, 7, 7, 8, 8, 10 }, 8));
	EXPECT_EQ(vector<int>({ 0, 0 }), SearchRange({ 1 }, 1)); 
	EXPECT_EQ(vector<int>({ 118, 133 }), SearchRange({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }, 10));
	EXPECT_EQ(vector<int>({ 98, 140 }), SearchRange({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }, 3));
}

int PainterPartionProblem(int A, int B, vector<int> &C);
TEST(IB, PainterPartionProblem) {
	EXPECT_EQ(50, PainterPartionProblem(2, 5, vector<int>({ 1,10 })));
	EXPECT_EQ(9140, PainterPartionProblem(5, 10, vector<int>({ 658, 786, 531, 47, 169, 397, 914 })));
	EXPECT_EQ(8990, PainterPartionProblem(6, 10, vector<int>({ 762, 798, 592, 899, 329 })));
	EXPECT_EQ(8890, PainterPartionProblem(4, 10, vector<int>({ 884, 228, 442, 889 })));
	EXPECT_EQ(9400003, PainterPartionProblem(1, 1000000, vector<int>({ 1000000, 1000000 })));
}

int AllocateBooks(vector<int> &A, int B);
TEST(IB, AllocateBooks) {
	EXPECT_EQ(113, AllocateBooks(vector<int>({ 12, 34, 67, 90 }), 2));
}

int MatrixSearch(vector<vector<int> > &A, int B);
TEST(IB, MatrixSearch) {
	EXPECT_EQ(1, MatrixSearch(vector<vector<int>>({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} }), 3));
	EXPECT_EQ(0, MatrixSearch(vector<vector<int>>({ { 2, 3, 4, 6 },
													{ 16, 19, 33, 36 },
													{ 37, 38, 38, 41 },
													{ 47, 47, 50, 51 },
													{ 55, 57, 58, 62 },
													{ 63, 65, 66, 66 },
													{ 68, 70, 75, 77 },
													{ 78, 84, 84, 86 },
													{ 86, 87, 88, 92 },
													{ 94, 95, 96, 97 } }), 81));
}

int SearchInsert(vector<int> &A, int B);
TEST(IB, SearchInsert) {
	EXPECT_EQ(2, SearchInsert(vector<int>({ 1,3,5,6 }), 5));
	EXPECT_EQ(1, SearchInsert(vector<int>({ 1,3,5,6 }), 2));
	EXPECT_EQ(4, SearchInsert(vector<int>({ 1,3,5,6 }), 7));
	EXPECT_EQ(0, SearchInsert(vector<int>({ 1,3,5,6 }), 0));
	EXPECT_EQ(0, SearchInsert(vector<int>({ 1 }), 1));
}

int Pow(int x, int n, int d);
TEST(IB, Pow) {
	EXPECT_EQ(2, Pow(2, 3, 3));
	EXPECT_EQ(19, Pow(-1, 1, 20));
}

int RotatedSortedArraySearch(const vector<int> &A, int B);
TEST(IB, RotatedSortedArraySearch) {
	EXPECT_EQ(0, RotatedSortedArraySearch(vector<int>({ 4, 5, 6, 7, 0, 1, 2 }), 4));
}

int RotatedArray(const vector<int> &A);
TEST(IB, RotatedArray) {
	//EXPECT_EQ(0, RotatedArray(vector<int>({ 4, 5, 6, 7, 0, 1, 2 })));
	EXPECT_EQ(350, RotatedArray(vector<int>({ 40342, 40766, 41307, 42639, 42777, 46079, 47038, 47923, 48064, 48083, 49760, 49871, 51000, 51035, 53186, 53499, 53895, 59118, 60467, 60498, 60764, 65158, 65838, 65885, 65919, 66638, 66807, 66989, 67114, 68119, 68146, 68584, 69494, 70914, 72312, 72432, 74536, 77038, 77720, 78590, 78769, 78894, 80169, 81717, 81760, 82124, 82583, 82620, 82877, 83131, 84932, 85050, 85358, 89896, 90991, 91348, 91376, 92786, 93626, 93688, 94972, 95064, 96240, 96308, 96755, 97197, 97243, 98049, 98407, 98998, 99785, 350, 2563, 3075, 3161, 3519, 4176, 4371, 5885, 6054, 6495, 7218, 7734, 9235, 11899, 13070, 14002, 16258, 16309, 16461, 17338, 19141, 19526, 21256, 21507, 21945, 22753, 25029, 25524, 27311, 27609, 28217, 30854, 32721, 33184, 34190, 35040, 35753, 36144, 37342 })));
	EXPECT_EQ(76, RotatedArray(vector<int>({ 60437, 60449, 61231, 61617, 61632, 61722, 61818, 61948, 62943, 62967, 63011, 63823, 65145, 65804, 65818, 66739, 66857, 67595, 69350, 71102, 71899, 72411, 72686, 73517, 74932, 76094, 76343, 76903, 77288, 77426, 77683, 78292, 79165, 79675, 79677, 80362, 80879, 80923, 82952, 83789, 83890, 84804, 85330, 87968, 88540, 89290, 89427, 89757, 89878, 91137, 91955, 92820, 93262, 94680, 95100, 96071, 96280, 96537, 96556, 97945, 98173, 98583, 99869, 76, 426, 1579, 1865, 4324, 4634, 5149, 5348, 7859, 8459, 9818, 10649, 10688, 11072, 11522, 12704, 12954, 13010, 13044, 14013, 14843, 16571, 16725, 16843, 17396, 17397, 17670, 17753, 19722, 20831, 21004, 21501, 21987, 22809, 23801, 24161, 24351, 24772, 24833, 25453, 25847, 25854, 25882, 26732, 28087, 28646, 33173, 33585, 35508, 36471, 37394, 37763, 37817, 41076, 41629, 41693, 41700, 42126, 42509, 42932, 43315, 44765, 45646, 46088, 47469, 47837, 48520, 49249, 49968, 51178, 51998, 52215, 53059, 53066, 53347, 54722, 54910, 55927, 58494, 59801, 60213 })));
	EXPECT_EQ(1396, RotatedArray(vector<int>({ 76961, 77242, 78246, 79428, 80505, 80843, 80894, 81082, 81351, 81591, 81990, 82503, 82983, 83668, 84048, 86502, 87162, 87479, 88720, 90773, 91077, 91095, 91204, 91554, 92323, 93043, 93240, 93357, 93745, 94622, 94742, 96173, 97712, 98000, 98616, 99102, 1396, 1577, 2682, 3644, 4749, 5623, 6522, 7245, 8564, 8675, 9671, 10500, 11276, 12033, 12682, 13977, 14324, 14626, 14804, 15036, 15070, 15656, 15660, 16227, 16436, 17591, 18442, 18674, 18770, 19825, 19904, 20836, 21503, 21666, 21755, 22345, 22580, 24128, 24640, 25200, 25610, 25852, 26424, 26675, 28115, 28433, 29053, 29957, 29975, 30020, 30396, 30567, 31821, 33292, 33319, 34040, 34696, 34781, 35770, 36239, 37460, 37507, 38910, 39310, 39947, 40097, 40170, 40354, 40436, 40670, 44373, 44461, 44790, 45024, 45154, 45526, 45758, 46648, 48852, 51549, 54652, 55102, 55455, 55501, 55690, 56135, 56161, 56509, 56674, 57017, 57571, 57821, 58353, 58904, 58906, 59057, 59119, 59443, 60226, 60687, 60973, 61863, 62346, 62475, 63106, 63254, 65085, 65251, 65472, 65529, 66723, 67327, 68770, 69656, 69867, 70632, 71155, 72148, 72185, 72277, 72440, 73058, 73223, 74078, 75208, 76131, 76214, 76776 })));
	EXPECT_EQ(24, RotatedArray(vector<int>({ 78456, 78522, 78582, 78635, 78954, 78995, 79078, 79098, 79362, 79399, 79404, 79467, 79597, 79818, 80148, 80170, 80200, 80204, 80312, 80526, 80820, 81010, 81045, 81118, 81125, 81127, 81229, 81346, 81348, 81490, 81619, 81752, 81850, 82032, 82047, 82156, 82217, 82541, 82888, 83041, 83112, 83116, 83273, 83274, 83285, 83583, 83684, 83795, 83936, 84043, 84128, 84146, 84277, 84400, 84432, 84761, 84838, 84992, 85076, 85145, 85329, 85403, 85560, 85736, 85976, 86158, 86184, 86441, 86579, 86599, 86700, 86745, 87172, 87632, 87746, 87756, 87773, 87788, 87851, 87935, 88427, 88444, 88585, 88832, 88857, 88913, 89149, 89153, 89167, 89235, 89449, 89510, 89652, 89659, 89672, 89793, 90153, 90184, 90246, 90254, 90332, 90577, 90690, 90745, 90779, 90819, 90882, 90909, 90954, 90968, 91034, 91094, 91235, 91305, 91391, 91503, 91577, 91712, 91822, 91987, 92121, 92126, 92145, 92190, 92205, 92584, 92843, 93000, 93378, 93431, 93723, 94520, 94575, 94582, 94778, 94801, 94994, 95113, 95117, 95284, 95470, 95754, 95835, 96164, 96188, 96237, 96268, 96335, 96449, 96459, 96541, 96548, 96587, 96752, 96793, 96800, 96948, 97018, 97125, 97137, 97169, 97201, 97329, 97434, 97621, 97636, 97862, 98442, 98730, 98807, 98832, 98851, 98894, 99047, 99060, 99526, 99546, 99845, 24, 25, 125, 137, 213, 280, 302, 321, 501, 506, 735, 739, 832, 897, 916, 968, 1214, 1222, 1276, 1375, 1461, 1481, 1860, 2025, 2156, 2199, 2513, 2522, 2836, 2878, 2894, 2912, 2964, 2970, 3268, 3405, 3412, 3798, 3845, 4073, 4173, 4202, 4215, 4374, 4442, 4553, 4572, 4601, 4892, 4907, 5001, 5034, 5497, 5577, 5709, 5850, 6071, 6205, 6307, 6309, 6378, 6654, 6719, 6923, 6975, 7115, 7265, 7290, 7320, 7348, 7437, 7526, 7528, 7553, 8026, 8152, 8271, 8310, 8517, 8870, 9042, 9503, 9528, 9613, 9750, 10035, 10053, 10099, 10121, 10177, 10459, 10538, 10753, 10782, 10835, 10900, 11123, 11245, 11448, 11923, 11979, 12082, 12134, 12360, 12422, 12671, 12830, 12996, 13094, 13362, 13514, 13777, 13805, 13921, 14032, 14165, 14209, 14211, 14390, 14404, 14417, 14553, 14741, 14982, 15068, 15318, 15569, 15576, 15578, 15614, 15709, 15761, 15806, 15870, 15903, 16086, 16434, 16558, 16730, 16905, 16980, 17084, 17183, 17338, 17459, 17491, 17528, 17558, 17642, 17738, 17746, 17876, 17889, 17903, 17994, 18021, 18037, 18229, 18235, 18484, 18509, 18512, 18579, 18658, 18706, 18962, 19120, 19234, 19368, 19475, 19563, 19592, 19595, 19805, 19944, 20333, 20354, 20473, 20512, 20527, 20590, 20610, 20617, 20711, 20787, 20826, 20887, 20920, 20949, 21057, 21101, 21253, 21295, 21510, 21520, 21537, 21559, 21647, 21694, 21773, 21895, 21999, 22117, 22175, 22265, 22367, 22398, 22635, 22669, 22737, 23249, 23348, 23413, 23541, 23589, 23609, 23647, 23840, 23847, 23894, 23920, 24183, 24222, 24305, 24333, 24390, 24393, 24513, 24522, 24686, 24903, 25036, 25073, 25112, 25459, 25464, 25502, 25610, 25954, 26087, 26207, 26242, 26288, 26295, 26377, 26412, 26495, 26861, 26904, 26932, 26981, 26990, 27010, 27050, 27190, 27313, 27317, 27402, 27477, 27518, 28025, 28067, 28151, 28168, 28197, 28313, 28724, 28835, 28967, 29169, 29195, 29279, 29298, 29363, 29639, 29837, 29850, 29868, 30058, 30078, 30084, 30142, 30343, 30423, 30443, 30595, 30606, 30682, 30736, 30835, 30941, 31139, 31296, 31426, 31485, 31519, 31565, 31588, 31751, 31760, 31780, 31802, 31890, 32022, 32026, 32113, 32272, 32679, 32810, 33083, 33544, 33589, 33688, 33748, 33831, 33921, 34111, 34227, 34241, 34358, 34465, 34492, 34519, 34676, 34823, 35038, 35276, 35300, 35400, 35452, 35619, 35768, 35782, 35803, 35806, 35826, 35891, 36030, 36172, 36226, 36349, 36407, 36422, 36543, 36692, 36766, 36920, 36988, 37028, 37205, 37212, 37270, 37344, 37384, 37650, 37744, 37753, 37965, 37984, 38171, 38208, 38356, 38440, 38460, 38679, 38743, 38821, 38832, 38943, 39042, 39088, 39098, 39160, 39366, 39373, 39416, 39496, 39516, 39561, 39604, 40056, 40173, 40459, 40486, 40499, 40531, 40615, 40630, 40814, 40946, 41034, 41357, 41358, 41391, 41471, 41650, 41713, 42198, 42527, 42674, 42774, 42843, 42944, 42952, 42968, 43029, 43043, 43047, 43062, 43065, 43239, 43271, 43360, 43590, 43902, 44007, 44170, 44177, 44198, 44248, 44253, 44309, 44376, 44464, 44469, 44544, 44547, 44551, 44587, 44798, 45011, 45062, 45089, 45175, 45390, 45512, 45666, 45694, 45777, 45877, 45953, 46125, 46150, 46605, 46753, 46781, 47010, 47045, 47526, 47694, 47741, 47785, 47823, 48058, 48572, 48579, 48785, 48872, 48970, 48979, 48984, 48999, 49090, 49242, 49718, 49745, 49846, 50013, 50025, 50236, 50247, 50348, 50419, 50705, 50788, 50896, 50955, 51193, 51231, 51372, 51389, 51403, 51522, 51660, 51730, 51892, 52098, 52168, 52462, 52664, 53018, 53359, 53416, 53458, 53460, 53493, 53502, 53600, 53629, 53671, 53736, 53759, 53800, 53839, 53906, 53946, 54039, 54057, 54333, 54345, 54398, 54554, 54661, 54753, 54824, 55019, 55477, 55638, 55657, 55873, 55877, 55899, 56031, 56380, 56577, 56590, 56804, 56847, 56923, 57065, 57155, 57237, 57245, 57570, 57786, 58194, 58213, 58232, 58441, 58732, 58748, 58840, 58978, 58996, 59027, 59052, 59077, 59133, 59154, 59244, 59583, 59676, 59719, 59865, 59879, 60153, 60650, 60788, 61095, 61213, 61308, 61354, 61388, 61707, 61758, 61894, 61941, 62016, 62047, 62182, 62479, 62487, 62527, 62708, 62865, 62993, 63093, 63101, 63118, 63145, 63263, 63281, 63409, 63421, 63434, 63519, 63695, 63785, 63847, 63892, 63916, 63965, 64114, 64123, 64288, 64433, 64533, 64666, 64723, 65102, 65280, 65400, 66031, 66083, 66190, 66493, 66671, 66676, 66702, 66788, 66901, 66980, 67254, 67332, 67346, 67397, 67637, 67794, 67847, 67955, 68195, 68252, 68351, 68364, 68392, 68420, 68434, 68574, 68616, 68673, 68729, 68794, 68855, 68972, 69002, 69062, 69145, 69206, 69272, 69280, 69361, 69566, 69939, 69985, 70179, 70302, 70390, 70412, 70512, 70640, 70678, 70870, 70935, 70961, 71019, 71269, 71290, 71345, 71353, 71468, 71492, 71600, 71637, 71651, 71827, 72187, 72198, 72279, 72290, 72304, 72321, 72361, 72411, 72537, 72572, 72644, 72662, 72710, 72926, 72993, 73006, 73103, 73184, 73305, 73580, 73871, 73971, 74019, 74317, 74325, 74376, 74388, 74429, 74434, 74530, 74629, 74801, 75013, 75086, 75099, 75173, 75512, 75550, 75605, 75827, 76261, 76278, 76586, 76835, 76878, 77010, 77117, 77123, 77226, 77245, 77369, 77381, 77526, 77559, 77671, 77676, 77689, 78021, 78234, 78324, 78333 })));
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > VerticalOrderTraversal(TreeNode* A);
TEST(IB, VerticalOrderTraversal) {
	TreeNode A(6);
	TreeNode B(3);
	TreeNode C(7);
	A.left = &B;
	A.right = &C;
	B.left = &TreeNode(2);
	B.right = &TreeNode(5);
	C.right = &TreeNode(9);
	EXPECT_EQ(vector<vector<int>>({ {2}, {3}, {6, 5}, {7}, {9} }), VerticalOrderTraversal(&A));
}

double MedianArraySameSize(const vector<int> &A, const vector<int> &B);
TEST(IB, MedianArraySameSize) {
	EXPECT_EQ(10.5, MedianArraySameSize(vector<int>({ 1, 8, 13, 77 }), vector<int>({ 2, 5, 67, 68 })));
	EXPECT_EQ(16, MedianArraySameSize(vector<int>({ 1, 12, 15, 26, 38 }), vector<int>({ 2, 13, 17, 30, 45 })));
	EXPECT_EQ(5.5, MedianArraySameSize(vector<int>({ 1, 2, 3, 4, 5 }), vector<int>({ 6, 7, 8, 9, 10 })));
	EXPECT_EQ(3.5, MedianArraySameSize(vector<int>({ 1, 4, 5 }), vector<int>({ 2, 3, 6 })));
	EXPECT_EQ(1.5, MedianArraySameSize(vector<int>({ 1 }), vector<int>({ 2 })));
	EXPECT_EQ(3.5, MedianArraySameSize(vector<int>({ 1, 8 }), vector<int>({ 2, 5 })));
}

double MedianArray(const vector<int> &A, const vector<int> &B);
TEST(IB, MediaArray) {
	EXPECT_EQ(18.5, MedianArray(vector<int>({ 19, 43 }), vector<int>({ 0, 4, 6, 18, 39, 42 })));
	EXPECT_EQ(2.5, MedianArray(vector<int>({ -50, -42, -38, 1, 4, 9, 16, 33, 47 }), vector<int>({ -44 })));
	EXPECT_EQ(-10.0, MedianArray(vector<int>({ -43, -25, -18, -15, -10, 9, 39, 40 }), vector<int>({ -2 })));
	EXPECT_EQ(10.0, MedianArray(vector<int>({ -37, -9, 10, 19 }), vector<int>({ -29, 18, 46 })));
	EXPECT_EQ(11.0, MedianArray(vector<int>({ -35, 5, 11, 34, 35 }), vector<int>()));
	EXPECT_EQ(20.0, MedianArray(vector<int>(), vector<int>({ 20 })));
	EXPECT_EQ(12.5, MedianArray(vector<int>({ -24, -11, -7, 4, 21, 26 }), vector<int>({ 25, 44 })));
	EXPECT_EQ(-8.5, MedianArray(vector<int>({ -37, -36, -33, -23, 1, 14, 24, 46, 47 }), vector<int>({ -33, -18, 9 })));
	EXPECT_EQ(18.0, MedianArray(vector<int>({ -48, -43, 46 }), vector<int>({ 18, 29 })));
	EXPECT_EQ(14.0, MedianArray(vector<int>({ -34, -18, -12, -3, 12, 16, 20, 31, 44 }), vector<int>({ -27, 25, 38 })));
	EXPECT_EQ(5.0, MedianArray(vector<int>({ -50, -47, -36, -35, 0, 13, 14, 16 }), vector<int>({ -31, 1, 9, 23, 30, 39 })));
	EXPECT_EQ(3.0, MedianArray(vector<int>({ -40, -25, 5, 10, 14, 28, 29, 48 }), vector<int>({ -48, -31, -15, -6, 1, 8 })));
	EXPECT_EQ(11.5, MedianArray(vector<int>({ 0, 23 }), vector<int>()));
	EXPECT_EQ(-20.0, MedianArray(vector<int>({ -50, -41, -40, -19, 5, 21, 28 }), vector<int>({ -50, -21, -10 })));
	EXPECT_EQ(3, MedianArray(vector<int>({ 1, 4, 5 }), vector<int>({ 2, 3 })));
}


int PalindromeString(string A);
TEST(IB, PalindromeString) {
	EXPECT_EQ(1, PalindromeString("A man, a plan, a canal: Panama"));
	EXPECT_EQ(0, PalindromeString("race a car"));
}

string LongestCommonPrefix(vector<string> &A);
TEST(IB, LongestCommonPrefix) {
	EXPECT_EQ("a", LongestCommonPrefix(vector<string>({"abcdefgh", "aefghijk", "abcefgh" })));
}

string CountAndSay(int A);
TEST(IB, CountAndSay) {
	EXPECT_EQ("1", CountAndSay(1));
	EXPECT_EQ("11", CountAndSay(2));
	EXPECT_EQ("21", CountAndSay(3));
	EXPECT_EQ("1211", CountAndSay(4));
	EXPECT_EQ("111221", CountAndSay(5));
	EXPECT_EQ("312211", CountAndSay(6));
	EXPECT_EQ("13112221", CountAndSay(7));
}

int LengthOfLastWord(const string A);
TEST(IB, LengthOfLastWord) {
	EXPECT_EQ(5, LengthOfLastWord("Hello World"));
	EXPECT_EQ(1, LengthOfLastWord("d"));
}

int MinimumCharactersPalindromic(string A);
TEST(IB, MinimumCharactersPalindromic) {
	EXPECT_EQ(2, MinimumCharactersPalindromic("ABC"));
	EXPECT_EQ(2, MinimumCharactersPalindromic("AACECAAAA"));
}

int StrStr(const string &A, const string &B);
TEST(IB, StrStr) {
	EXPECT_EQ(6, StrStr("Hello World", "World"));
	EXPECT_EQ(2, StrStr("A man, a plan, a canal: Panama", "man"));
}

string LongestPalindrome(string A);
TEST(IB, LongestPalindrome) {
	EXPECT_EQ("a", LongestPalindrome("ac"));
	EXPECT_EQ("caaccaccaac", LongestPalindrome("caccbcbaabacabaccacaaccaccaaccbbcbcbbaacabccbcccbbacbbacbccaccaacaccbbcc"));
	EXPECT_EQ("a", LongestPalindrome("a"));
	EXPECT_EQ("aaabaaa", LongestPalindrome("aaaabaaa"));
	EXPECT_EQ("bbcccbb", LongestPalindrome("abbcccbbbcaaccbababcbcabca"));
}

int CompareVersion(string A, string B);
TEST(IB, CompareVersion) {
	EXPECT_EQ(-1, CompareVersion("444444444444444444444444", "4444444444444444444444444"));
	EXPECT_EQ(1, CompareVersion("4444371174137455", "5.168"));
	EXPECT_EQ(0, CompareVersion("1.0", "1"));
	EXPECT_EQ(0, CompareVersion("01", "1"));
	EXPECT_EQ(-1, CompareVersion("0.1", "1.13"));
	EXPECT_EQ(1, CompareVersion("1.13.4", "1.13"));
	EXPECT_EQ(-1, CompareVersion("1.2", "1.13"));
	EXPECT_EQ(1, CompareVersion("1.1", "0.1"));
}

int Atoi(const string A);
TEST(IB, Atoi) {
	EXPECT_EQ(-2147483648L, Atoi("-54332872018247709407 4 54"));
	EXPECT_EQ(9, Atoi("9 2704"));
}

int ValidNumber(const string A);
TEST(IB, ValidNumber) {
	EXPECT_EQ(1, ValidNumber("0"));
	EXPECT_EQ(1, ValidNumber(" 0.1 "));
	EXPECT_EQ(0, ValidNumber("abc"));
	EXPECT_EQ(0, ValidNumber("1 a"));
	EXPECT_EQ(1, ValidNumber("2e10"));
	EXPECT_EQ(1, ValidNumber("0.1e10"));
	EXPECT_EQ(1, ValidNumber("-01.1e-10"));
	EXPECT_EQ(0, ValidNumber("3e1.1"));
	EXPECT_EQ(0, ValidNumber("3."));
	EXPECT_EQ(0, ValidNumber("3.e"));
	EXPECT_EQ(1, ValidNumber("32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609  "));
}

vector<string> RestoreIpAddresses(string A);
TEST(IB, RestoreIpAddresses) {
	EXPECT_EQ(vector<string>({ "0.10.0.10", "0.100.1.0" }), RestoreIpAddresses("010010"));
	EXPECT_EQ(vector<string>({ "255.255.11.135", "255.255.111.35" }), RestoreIpAddresses("25525511135"));
}

string ReverseWords(string &A);
TEST(IB, ReverseWords) {
	EXPECT_EQ(string("blue is sky the"), ReverseWords(string("the sky is blue")));
}

int RomanToInt(string A);
TEST(IB, RomanToInt) {
	EXPECT_EQ(84, RomanToInt(string("LXXXIV")));
	EXPECT_EQ(64, RomanToInt(string("LXIV")));
	EXPECT_EQ(45, RomanToInt(string("XLV")));
	EXPECT_EQ(74, RomanToInt(string("LXXIV")));
	EXPECT_EQ(689, RomanToInt(string("DCLXXXIX")));
	EXPECT_EQ(999, RomanToInt(string("CMXCIX")));
	EXPECT_EQ(1000, RomanToInt(string("M")));
}

string IntToRoman(int A);
TEST(IB, IntToRoman) {
	EXPECT_EQ(string("LXXXIV"), IntToRoman(84));
	EXPECT_EQ(string("LXIV"), IntToRoman(64));
	EXPECT_EQ(string("XLV"), IntToRoman(45));
	EXPECT_EQ(string("LXXIV"), IntToRoman(74));
	EXPECT_EQ(string("DCLXXXIX"), IntToRoman(689));
	EXPECT_EQ(string("CMXCIX"), IntToRoman(999));
	EXPECT_EQ(string("M"), IntToRoman(1000));
}

string AddBinary(string A, string B);
TEST(IB, AddBinary) {
	EXPECT_EQ(string("100"), AddBinary("11", "1"));
	EXPECT_EQ(string("111"), AddBinary("100", "11"));
	EXPECT_EQ(string("10"), AddBinary("1", "1"));
}

int PowerOf2(string A);
TEST(IB, PowerOf2) {
	EXPECT_EQ(1, PowerOf2("128"));
	EXPECT_EQ(0, PowerOf2("129"));
	EXPECT_EQ(1, PowerOf2("1024"));
}

string MultiplyStrings(string A, string B);
TEST(IB, MultiplyStrings) {
	EXPECT_EQ(string("120"), MultiplyStrings("12", "10"));
	EXPECT_EQ(string("9801"), MultiplyStrings("99", "99"));
	EXPECT_EQ(string("550"), MultiplyStrings("55", "10"));
	EXPECT_EQ(string("0"), MultiplyStrings("31243242535342", "0"));
}

vector<string> FullJustify(vector<string> &A, int B);
TEST(IB, FullJustify) {
	EXPECT_EQ(vector<string>({ "This    is    an", "example  of text", "justification.  " }),
		FullJustify(vector<string>({ "This", "is", "an", "example", "of", "text", "justification." }), 16));
	EXPECT_EQ(vector<string>({ "am    fasgoprn", "lvqsrjylg     ", "rzuslwan xlaui", "tnzegzuzn     ", "kuiwdc        ", "fofjkkkm      ", "ssqjig        ", "tcmejefj      ", "uixgzm        ", "lyuxeaxsg     ", "iqiyip     msv", "uurcazjc      ", "earsrvrq   qlq", "lxrtzkjpg     ", "jkxymjus      ", "mvornwza zty q", "nsecqphjy     " }),
		FullJustify(vector<string>({ "am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy" }), 14));
}

string ZigzagString(string A, int B);
TEST(IB, ZigzagString) {
	EXPECT_EQ(string("AKBJLCIMSDHNREGOQFP"), ZigzagString("ABCDEFGHIJKLMNOPQRS", 6));
	EXPECT_EQ(string("PAHNAPLSIIGYIR"), ZigzagString("PAYPALISHIRING", 3));
	EXPECT_EQ(string("ACBD"), ZigzagString("ABCD", 2));
}

vector<string> PrettyJSON(string A);
TEST(IB, PrettyJSON) {
	EXPECT_EQ(vector<string>({"{", "\tA:\"B\",", "\tC:", "\t{", "\t\tD:\"E\",", "\t\tF:", "\t\t{", "\t\t\tG:\"H\",", "\t\t\tI:\"J\"", "\t\t}", "\t}", "}" }), PrettyJSON("{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}"));
}

int FindMinXor(vector<int> &A);
TEST(IB, FindMinXor) {
	EXPECT_EQ(2, FindMinXor(vector<int>({ 0, 2, 5, 7 })));
	EXPECT_EQ(3, FindMinXor(vector<int>({ 0, 4, 7, 9 })));
}

unsigned int ReverseBits(unsigned int A);
TEST(IB, ReverseBits) {
	EXPECT_EQ(0xFFFFFFFF, ReverseBits(0xFFFFFFFF));
	EXPECT_EQ(3221225472, ReverseBits(3));
}

int DivideIntegers(int A, int B);
TEST(IB, DivideIntegers) {
	EXPECT_EQ(2147483647, DivideIntegers(-2147483648, -1));
	EXPECT_EQ(1, DivideIntegers(5, 3));
	EXPECT_EQ(3, DivideIntegers(16, 5));
}

int DifferentBitsSumPairwise(vector<int> &A);
TEST(IB, DifferentBitsSumPairwise) {
	EXPECT_EQ(8, DifferentBitsSumPairwise(vector<int>({ 1, 3, 5 })));
}

int SingleNumber(const vector<int> &A);
TEST(IB, SingleNumber) {
	EXPECT_EQ(3, SingleNumber(vector<int>({ 1, 2, 2, 3, 1 })));
}

int SingleNumber2(const vector<int> &A);
TEST(IB, SingleNumber2) {
	EXPECT_EQ(247, SingleNumber2(vector<int>({ 890, 992, 172, 479, 973, 901, 417, 215, 901, 283, 788, 102, 726, 609, 379, 587, 630, 283, 10, 707, 203, 417, 382, 601, 713, 290, 489, 374, 203, 680, 108, 463, 290, 290, 382, 886, 584, 406, 809, 601, 176, 11, 554, 801, 166, 303, 308, 319, 172, 619, 400, 885, 203, 463, 303, 303, 885, 308, 460, 283, 406, 64, 584, 973, 572, 194, 383, 630, 395, 901, 992, 973, 938, 609, 938, 382, 169, 707, 680, 965, 726, 726, 890, 383, 172, 102, 10, 308, 10, 102, 587, 809, 460, 379, 713, 890, 463, 108, 108, 811, 176, 169, 313, 886, 400, 319, 22, 885, 572, 64, 120, 619, 313, 3, 460, 713, 811, 965, 479, 3, 247, 886, 120, 707, 120, 176, 374, 609, 395, 811, 406, 809, 801, 554, 3, 194, 11, 587, 169, 215, 313, 319, 554, 379, 788, 194, 630, 601, 965, 417, 788, 479, 64, 22, 22, 489, 166, 938, 66, 801, 374, 66, 619, 489, 215, 584, 383, 66, 680, 395, 400, 166, 572, 11, 992 })));
}

vector<int> MergeTwoSortedLists2(vector<int> &A, vector<int> &B);
TEST(IB, MergeTwoSortedLists2) {
	EXPECT_EQ(vector<int>({ 1, 5, 6, 8, 9 }), MergeTwoSortedLists2(vector<int>({ 1, 5, 8 }), vector<int>({ 6, 9 })));
}

vector<int> Intersect(const vector<int> &A, const vector<int> &B);
TEST(IB, Intersect) {
	EXPECT_EQ(vector<int>({ 35, 38, 53, 67, 69, 94, 98 }), Intersect(vector<int>({ 1, 3, 8, 10, 13, 13, 16, 16, 16, 18, 21, 23, 24, 31, 31, 31, 33, 35, 35, 37, 37, 38, 40, 41, 43, 47, 47, 48, 48, 52, 52, 53, 53, 55, 56, 60, 60, 61, 61, 63, 63, 64, 66, 67, 67, 68, 69, 71, 80, 80, 80, 80, 80, 80, 81, 85, 87, 87, 88, 89, 90, 94, 95, 97, 98, 98, 100, 101 }), vector<int>({ 5, 7, 14, 14, 25, 28, 28, 34, 35, 38, 38, 39, 46, 53, 65, 67, 69, 70, 78, 82, 94, 94, 98 })));
	EXPECT_EQ(vector<int>({ 43, 62, 79, 87 }), Intersect(vector<int>({ 1, 1, 1, 3, 4, 4, 4, 7, 8, 9, 12, 14, 19, 22, 25, 26, 28, 31, 32, 34, 34, 34, 36, 36, 38, 39, 39, 39, 41, 42, 42, 43, 43, 43, 45, 45, 47, 49, 49, 50, 50, 52, 53, 54, 55, 56, 57, 60, 60, 62, 63, 65, 67, 72, 74, 74, 75, 75, 78, 78, 79, 80, 80, 80, 80, 80, 82, 83, 83, 83, 84, 85, 85, 86, 86, 86, 87, 88, 88, 88, 90, 90, 91, 92, 93, 93, 93, 96, 96, 97, 97, 98, 98, 99, 100 }), vector<int>({ 13, 13, 24, 24, 27, 37, 43, 61, 61, 62, 66, 69, 69, 71, 71, 79, 87 })));
	EXPECT_EQ(vector<int>({ 67 }), Intersect(vector<int>({ 12, 30, 41, 51, 56, 58, 63, 67, 82, 90, 93 }), vector<int>({ 7, 9, 17, 17, 19, 21, 26, 34, 65, 65, 67, 68, 71, 75, 92 })));
}

int MinimizeAbsoluteDiff(vector<int> &A, vector<int> &B, vector<int> &C);
TEST(IB, MinimizeAbsoluteDiff) {
	EXPECT_EQ(1, MinimizeAbsoluteDiff(vector<int>({ 1, 4, 5, 8, 10 }), vector<int>({ 6, 9, 15 }), vector<int>({ 2, 3, 6, 6 })));
}

int ThreeSumClosest(vector<int> &A, int B);
TEST(IB, ThreeSumClosest) {
	EXPECT_EQ(5, ThreeSumClosest(vector<int>({ 5, -2, -1, -10, 10 }), 5));
	EXPECT_EQ(2, ThreeSumClosest(vector<int>({ 5, 2, -2, -5, 10, -1, -6, -3, 5, -8, -7, 2, 5, 4, -1, -5, 0, 5, 0, 2, -5, 1, 4, -10, 2, -1, 4, 1, 6, 0, -10, 8, 4, 5, 5, -7, -3, 6, 10, 6, -5, 5, -1, -3, -2, -7, 8, 3, 10, -5, 10, -2, 0, 9, 7, -1, -2, -8, -1, 2, -8, 10, 4, 0, -10, 0, 4, -5, -4, 2, -1, -8, 10, -2, -1, -6, 0, -1, -2, -7, 3, 7, -9, -2, 4, 7, 0, 2, 10, 2 }), 2));
	EXPECT_EQ(0, ThreeSumClosest(vector<int>({ -4, -8, -10, -9, -1, 1, -2, 0, -8, -2 }), 0));
	EXPECT_EQ(-1, ThreeSumClosest(vector<int>({ -5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 }), -1));
}

vector<vector<int> > ThreeSumZero(vector<int> &A);
TEST(IB, ThreeSumZero) {
	EXPECT_EQ(vector<vector<int>>({ { -5, 0, 5 }, {-5, 1, 4}, {-4, -1, 5}, {-4, 0, 4}, {-4, 1, 3}, {-3, -2, 5}, {-3, -1, 4}, {-3, 0, 3}, {-2, -1, 3}, {-2, 1, 1}, {-1, 0, 1}, {0, 0, 0} }), ThreeSumZero(vector<int>({ 1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 })));
}

int CountingTriangles(vector<int> &A);
TEST(IB, CountingTriangles) {
	EXPECT_EQ(4, CountingTriangles(vector<int>({ 1, 1, 1, 2, 2 })));
	EXPECT_EQ(1, CountingTriangles(vector<int>({ 1, 1, 1 })));
	EXPECT_EQ(12, CountingTriangles(vector<int>({ 4, 6, 13, 16, 20, 3, 1, 12 })));
	EXPECT_EQ(341, CountingTriangles(vector<int>({ 11, 18, 13, 1, 19, 14, 8, 15, 16, 20, 12, 6, 10, 5, 17, 2, 4 })));
}

int DiffPossible(vector<int> &A, int B);
TEST(IB, DiffPossible) {
	EXPECT_EQ(0, DiffPossible(vector<int>({ 1, 2, 3 }), 0));
	EXPECT_EQ(1, DiffPossible(vector<int>({ 1, 2, 2, 3, 4 }), 0));
	EXPECT_EQ(1, DiffPossible(vector<int>({ 1, 13, 43, 46, 49, 53, 56, 70, 76, 81, 83, 94, 95 }), 28));
}

int RemoveDuplicates(vector<int> &A);
TEST(IB, RemoveDuplicates) {
	EXPECT_EQ(4, RemoveDuplicates(vector<int>({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 })));
}

vector<int> SortColors(vector<int> &A);
TEST(IB, SortColors) {
	EXPECT_EQ(vector<int>({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }), SortColors(vector<int>({ 2, 0, 0, 1, 0, 0, 2, 2, 1, 1, 0, 0, 1, 0, 2, 1, 1, 0, 1, 0, 1, 2, 2, 2, 0, 0, 1, 0, 2, 1, 1, 2, 1, 2, 2, 1, 0, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 2, 0, 2, 0, 1, 1, 0, 2, 2, 1, 2, 0, 2, 1, 1, 1, 2, 0, 1, 0, 2, 2, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 2, 1, 1, 0, 2, 1, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 2, 1, 2, 2, 2, 1, 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 1, 2, 0, 1, 0, 2, 2, 1, 2, 1, 0, 2, 2, 1, 1, 0, 2, 1, 2 })));
}

vector<int> MaxOne(vector<int> &A, int B);
TEST(IB, MaxOne) {
	EXPECT_EQ(vector<int>({ 23, 24, 25 }), MaxOne(vector<int>({ 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0 }), 0));
	EXPECT_EQ(vector<int>({ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }), MaxOne(vector<int>({ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0 }), 4));
	EXPECT_EQ(vector<int>({ 0,1,2 }), MaxOne(vector<int>({ 1, 1, 0 }), 7));
	EXPECT_EQ(vector<int>({ 0,1,2}), MaxOne(vector<int>({ 1,1,0 }), 2));
	EXPECT_EQ(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98 }), MaxOne(vector<int>({ 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1 }), 46));
}

int Array3Pointers(const vector<int> &A, const vector<int> &B, const vector<int> &C);
TEST(IB, Array3Pointers) {
	EXPECT_EQ(5, Array3Pointers(vector<int>({ 1, 4, 10 }), vector<int>({ 2, 15, 20 }), vector<int>({ 10, 12 })));
}

int ContainerWithMostWater(vector<int> &A);
TEST(IB, ContainerWithMostWater) {
	EXPECT_EQ(9326700, ContainerWithMostWater(vector<int>({ 7495, 3935, 164, 6024, 6141, 5103, 6452, 4927, 5366, 1096, 9836, 6170, 7801, 7637, 556, 8383, 6750, 2757, 2195, 5080, 3715, 1867, 610, 5864, 7725, 5658, 5090, 8830, 6185, 913, 8362, 571, 5940, 645, 3468, 4160, 5806, 9220, 7390, 108, 8786, 9920, 9077, 3341, 7192, 3812, 664, 6913, 1310, 9222, 6796, 5041, 5320, 8330, 529, 4949, 4888, 9537, 8914, 9545, 6611, 8457, 688, 980, 9653, 6837, 1956, 3818, 17, 6311, 2344, 3918, 9023, 6423, 653, 886, 4364, 9461, 477, 8892, 2336, 1639, 1812, 224, 1489, 7860, 4705, 2482, 9454, 560, 7955, 8782, 9289, 3316, 3760, 7112, 5813, 9161, 6982, 871, 8355, 5508, 8025, 3883, 4932, 4637, 2019, 4766, 5143, 7555, 5160, 2418, 2103, 8293, 9184, 6961, 2361, 6480, 5518, 2454, 1332, 8232, 4961, 252, 8885, 7859, 5026, 7783, 4216, 4832, 3041, 6441, 6520, 4208, 1559, 3622, 8607, 1017, 6728, 2753, 5266, 8160, 4941, 4154, 4557, 8922, 9715, 8846, 5117, 1247, 9305, 4483, 7020, 5124, 9762, 9988, 8399, 2512, 7656, 9162, 5839, 4642, 9103, 4217, 8946, 9396, 3109, 5154, 9224, 8986, 1012, 9323, 2097, 2764, 3508, 8801, 3091, 1295, 6799, 5394, 7911, 3628, 1971, 1599, 8541, 7996, 8303, 4088, 6241, 444, 1459, 1317, 2402, 5264, 1664, 591, 1039, 7103, 4466, 9164, 2491, 1108, 7162, 9127, 7527, 945, 8555, 9679, 2258, 723, 1399, 2717, 1949, 3739, 410, 4120, 1892, 9258, 9735, 9665, 9618, 2990, 696, 4758, 5729, 3869, 6880, 9282, 3526, 3861, 7681, 2973, 7476, 7899, 9787, 5288, 427, 8792, 2584, 3117, 626, 5992, 3094, 3004, 9115, 9044, 2812, 9570, 621, 5559, 6808, 7566, 4842, 2868, 4308, 965, 990, 6948, 4563, 4231, 7643, 8276, 525, 7950, 9717, 5089, 9112, 7066, 4180, 6062, 1538, 7866, 1829, 6369, 6653, 5699, 4939, 3048, 9522, 6355, 9802, 8517, 1338, 84, 169, 8274, 6728, 2581, 3254, 6143, 4566, 1185, 9617, 9939, 4272, 2380, 2918, 4199, 7493, 2775, 1464, 229, 752, 3540, 2705, 6039, 8456, 5492, 5014, 6334, 5496, 8772, 4767, 401, 1881, 9016, 3440, 4842, 6833, 9065, 4816, 8138, 968, 6996, 4351, 7560, 1916, 726, 5231, 3930, 6153, 2394, 3846, 9949, 9869, 5977, 2152, 5601, 6732, 1383, 2503, 9713, 8139, 3643, 9928, 7878, 4432, 5338, 3666, 2636, 9312, 1452, 7766, 9679, 6461, 315, 8206, 1369, 9425, 4947, 8090, 6184, 563, 5379, 5768, 4553, 6894, 2861, 6439, 8930, 8766, 4216, 4554, 5443, 1352, 2419, 8630, 7534, 7217, 669, 2173, 1597, 3935, 2786, 6416, 1367, 7429, 1032, 5707, 4923, 960, 2967, 8968, 4797, 6270, 7144, 2531, 977, 1724, 6693, 4355, 6661, 2969, 8636, 9772, 6090, 5738, 9463, 3181, 6187, 8124, 7073, 4440, 8301, 4557, 3886, 5752, 575, 353, 6222, 1190, 9782, 6164, 8563, 9683, 2752, 7511, 2205, 1440, 7627, 2865, 9952, 8657, 4468, 1596, 1545, 6895, 4202, 9506, 4810, 3525, 6991, 4153, 1895, 8471, 193, 8293, 5110, 9237, 8710, 6002, 1027, 3274, 2964, 4026, 4024, 4750, 4027, 2798, 8722, 4270, 3393, 9846, 5132, 8827, 7758, 2309, 5987, 2339, 2408, 275, 840, 2868, 577, 2108, 5911, 9355, 1657, 3196, 5841, 7915, 7005, 3539, 2169, 8001, 1919, 1457, 1778, 3323, 1200, 6565, 9106, 3783, 7511, 9265, 1053, 3556, 4839, 6220, 795, 5760, 1661, 9910, 2746, 3492, 4242, 4043, 7652, 2422, 3608, 6685, 4214, 1823, 8084, 9027, 7547, 5880, 6391, 7952, 6078, 1347, 3408, 71, 7458, 7281, 5363, 5737, 9625, 5217, 1787, 2616, 3818, 9943, 6051, 1984, 9251, 9160, 5396, 7156, 5065, 4381, 5520, 5641, 9052, 4043, 9444, 8566, 3504, 5483, 9221, 4676, 7473, 1712, 2424, 1476, 3825, 1585, 8067, 6867, 6703, 1668, 6522, 5100, 8736, 4298, 9959, 122, 2362, 3476, 2871, 9893, 534, 7175, 5809, 1354, 2168, 5047, 5718, 6804, 5078, 8753, 4780, 7701, 4460, 8782, 9665, 6495, 6338, 8075, 8380, 7976, 5037, 5290, 9105, 3750, 1287, 8163, 424, 876, 5103, 5353, 7295, 6242, 9932, 3406, 5047, 1429, 7874, 3365, 3594, 2076, 8191, 5474, 2836, 8329, 6083, 3318, 8820, 3975, 5832, 8638, 8992, 1077, 4510, 8645, 7617, 1018, 3517, 9453, 9847, 756, 75, 2037, 3076, 643, 2905, 5940, 704, 618, 8490, 4729, 7030, 5634, 3383, 852, 8380, 5865, 6246, 9491, 209, 408, 6823, 5616, 4956, 3279, 4128, 5483, 1640, 9058, 8541, 4962, 1759, 7410, 9357, 9514, 5135, 3282, 624, 7131, 9984, 1773, 6143, 167, 431, 7832, 7563, 9171, 2533, 5585, 5526, 7716, 432, 6543, 8094, 9627, 8339, 4244, 8684, 7545, 1002, 9921, 2497, 2693, 252, 5570, 2784, 4860, 5330, 8589, 5905, 6631, 6867, 4773, 1809, 4035, 9397, 3437, 9250, 6596, 9098, 3844, 4950, 108, 8023, 1033, 4945, 8178, 8540, 5954, 7781, 2049, 9704, 3473, 9331, 1993, 1149, 1545, 3253, 8017, 5932, 2628, 7594, 9789, 9775, 6379, 2384, 4702, 9594, 1152, 6836, 7122, 7108, 1548, 4800, 6387, 2658, 117, 2228, 6191, 6731, 5174, 5476, 2893, 3707, 5375, 5263, 2949, 2064, 3333, 9717, 7271, 3602, 9649, 4360, 3801, 1309, 8383, 8425, 8810, 9143, 9280, 6203, 4766, 7878, 1051, 5117, 5401, 9447, 8264, 2361, 7903, 2284, 3920, 7063, 5852, 7849, 3148, 2389, 2038, 2248, 3772, 3083, 6256, 1584, 160, 5311, 3066, 466, 6766, 2698, 885, 8431, 65, 9494, 7509, 4894, 4158, 7438, 205, 5467, 3198, 7346, 8398, 8445, 1512, 7834, 404, 3281, 6717, 3587, 9259, 4887, 6152, 2635, 3361, 4514, 4552, 1595, 7810, 6059, 1901, 8364, 6535, 8589, 8722, 7422, 7057, 8336, 3377, 7773, 8865, 4899, 5351, 7172, 3960, 9585, 6283, 396, 8377, 1185, 2166, 3307, 4282, 8628, 5716, 3810, 2203, 3513, 5827, 8992, 7576, 9673, 2321, 9427, 5746, 7364, 4322, 7374, 6661, 9284, 1315, 5593, 5316, 2091, 9815, 7851, 7982, 2748, 6317, 9389, 6681, 6676, 7355, 4958, 3671, 2013, 1992, 3622, 2958, 4512, 9486, 3435, 1209, 6220, 3931, 2898, 8917, 2299, 6575, 696, 1920, 3332, 2102, 5347, 8444, 4476, 7917, 1247, 6590, 584, 3179, 2354, 7326, 2954, 2457, 9930, 3524, 5929, 5104, 1064, 7637, 8533, 1685, 1340, 7570, 8915, 7378, 2432, 3032, 99, 7150, 2267, 3526, 6358, 5447, 4093, 2125, 8108, 3990, 8045, 212, 527, 5490, 3042, 8125, 2501, 2436, 3550, 6803, 8482, 6037, 1229, 4448, 113, 6991, 2704, 8847, 3108, 2487, 1222, 6116, 933, 266, 469, 5468, 2033, 4902, 5375, 2530, 300, 5723, 6615, 5949, 1348, 9675, 2239, 6794 })));
}

int Kthsmallest(const vector<int> &A, int B);
TEST(IB, Kthsmallest) {
	EXPECT_EQ(87, Kthsmallest(vector<int>({ 94, 87, 100, 11, 23, 98, 17, 35, 43, 66, 34, 53, 72, 80, 5, 34, 64, 71, 9, 16, 41, 66, 96 }), 19));
	EXPECT_EQ(18, Kthsmallest(vector<int>({ 74, 90, 85, 58, 69, 77, 90, 85, 18, 36 }), 1));
	EXPECT_EQ(17, Kthsmallest(vector<int>({ 8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 }), 9));
}

int NumRange(vector<int> &A, int B, int C);
TEST(IB, NumRange) {
	EXPECT_EQ(58, NumRange(vector<int>({ 80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90 }), 99, 269));
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MakeList(vector<int> A)
{
	int len = (int)A.size();
	if (len == 0) return nullptr;

	ListNode *ret = new ListNode(A[0]);
	ListNode *pCur = ret;
	for (int i = 1; i < len; i++)
	{
		pCur->next = new ListNode(A[i]);
		pCur = pCur->next;
	}

	return ret;
}

void FreeList(ListNode **A)
{
	ListNode *pCur = *A;

	while (pCur)
	{
		ListNode *pNext = pCur->next;
		delete pCur;
		pCur = pNext;
	}
}

vector<int> List2Vec(ListNode *A)
{
	vector<int> ret;
	while (A)
	{
		ret.push_back(A->val);
		A = A->next;
	}

	return ret;
}

ListNode* GetTail(ListNode *A)
{
	ListNode *pPrev = nullptr;
	while (A)
	{
		pPrev = A;
		A = A->next;
	}

	return pPrev;
}

ListNode* GetIntersectionNode(ListNode* A, ListNode* B);
TEST(IB, GetIntersectionNode) {
	ListNode *A = MakeList(vector<int>({ 1 }));
	ListNode *B = MakeList(vector<int>());
	ListNode *C = MakeList(vector<int>({ 5, 2, 3 }));
	GetTail(A)->next = C;
	B = C;
	EXPECT_EQ(C, GetIntersectionNode(A, B));
}

ListNode* KReverseList(ListNode* A, int B);
TEST(IB, KReverseList) {
	ListNode *A = MakeList({ 1,2,3,4,5,6 });
	vector<int> B({ 2,1,4,3,6,5 });
	ListNode *C = KReverseList(A, 2);
	vector<int> D = List2Vec(C);
	EXPECT_EQ(B, D);
	FreeList(&C);
}

int PalindromeList(ListNode* A);
TEST(IB, PalindromeList) {
	ListNode *A = MakeList({ 1,2,3,2,1 });
	EXPECT_EQ(1, PalindromeList(A));
	FreeList(&A);

	ListNode *B = MakeList({ 1,2,3,4,5,7 });
	EXPECT_EQ(0, PalindromeList(B));
	FreeList(&B);
}

ListNode* DeleteDuplicates(ListNode* A);
TEST(IB, DeleteDuplicates) {
	ListNode *A = MakeList({ 1,1,1,2,2,3,3,3,4,4,4,4,4,4,5 });
	A = DeleteDuplicates(A);
	vector<int> B = List2Vec(A);
	vector<int> C({ 1,2,3,4,5 });
	EXPECT_EQ(B, C);
	FreeList(&A);
}

ListNode* DeleteDuplicates2(ListNode* A);
TEST(IB, DeleteDuplicates2) {
	ListNode *A = MakeList({ 1,1,1,2,2,3,3,3,4,4,4,4,4,4,5 });
	A = DeleteDuplicates2(A);
	vector<int> B = List2Vec(A);
	vector<int> C({ 5 });
	EXPECT_EQ(B, C);
	FreeList(&A);
}

ListNode* MergeTwoLists(ListNode* A, ListNode* B);
TEST(IB, MergeTwoLists) {
	ListNode *A = MakeList({ 5, 8, 20 });
	ListNode *B = MakeList({ 4, 11, 15 });
	ListNode *C = MergeTwoLists(A, B);
	vector<int> D = List2Vec(C);
	vector<int> E({ 4, 5, 8, 11, 15, 20 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* RemoveNthFromEnd(ListNode* A, int B);
TEST(IB, RemoveNthFromEnd) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *C = RemoveNthFromEnd(A, 2);
	vector<int> D = List2Vec(C);
	vector<int> E({ 1,2,3,5 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* RotateRight(ListNode* A, int B);
TEST(IB, RotateRight) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *C = RotateRight(A, 2);
	vector<int> D = List2Vec(C);
	vector<int> E({ 4,5,1,2,3 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* ReverseBetween(ListNode* A, int B, int C);
TEST(IB, ReverseBetween) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *C = ReverseBetween(A, 2, 4);
	vector<int> D = List2Vec(C);
	vector<int> E({ 1,4,3,2,5 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* SwapPairs(ListNode* A);
TEST(IB, SwapPairs) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *C = SwapPairs(A);
	vector<int> D = List2Vec(C);
	vector<int> E({ 2,1,4,3,5 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* ReorderList(ListNode* A);
TEST(IB, ReorderList) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *C = ReorderList(A);
	vector<int> D = List2Vec(C);
	vector<int> E({ 1,5,2,4,3 });
	EXPECT_EQ(D, E);
	FreeList(&C);
}

ListNode* AddTwoNumbers(ListNode* A, ListNode* B);
TEST(IB, AddTwoNumbers) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *B = MakeList({ 8,9,4,9,7 });
	ListNode *C = AddTwoNumbers(A, B);
	vector<int> D = List2Vec(C);
	vector<int> E({ 9,1,8,3,3,1 });
	EXPECT_EQ(D, E);
	FreeList(&A);
	FreeList(&B);
	FreeList(&C);
}

ListNode* DetectCycle(ListNode* A);
TEST(IB, DetectCycle) {
	ListNode *A = MakeList({ 1,2,3,4,5 });
	ListNode *B = GetTail(A);
	B->next = A;
	EXPECT_EQ(A, DetectCycle(A));
	B->next = nullptr;
	FreeList(&A);
}

ListNode* PartitionList(ListNode* A, int B);
TEST(IB, PartitionList) {
	ListNode *A = MakeList({ 886, 364, 608, 806, 257, 519, 722, 824, 701, 837, 137, 182, 309, 18, 316, 765 });
	ListNode *B = PartitionList(A, 55);
	vector<int> C = List2Vec(B);
	EXPECT_EQ(vector<int>({ 18, 886, 364, 608, 806, 257, 519, 722, 824, 701, 837, 137, 182, 309, 316, 765 }), C);
	B->next = nullptr;
	FreeList(&A);
}

ListNode* InsertionSortList(ListNode* A);
TEST(IB, InsertionSortList) {
	ListNode *A = MakeList({ 1, 10, 2, 9, 3, 11, 8, 7, 12, 6, 13, 14, 5, 16, 15, 4 });
	ListNode *B = InsertionSortList(A);
	vector<int> C = List2Vec(B);
	EXPECT_EQ(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }), C);
	FreeList(&A);
}

ListNode* SortList(ListNode* A);
TEST(IB, SortList) {
	ListNode *A = MakeList({ 1, 10, 2, 9, 3, 11, 8, 7, 12, 6, 13, 14, 5, 16, 15, 4 });
	ListNode *B = SortList(A);
	vector<int> C = List2Vec(B);
	EXPECT_EQ(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }), C);
	FreeList(&A);
}

int GenerateAllParentheses(string A);
TEST(IB, GenerateAllParentheses)
{
	EXPECT_EQ(1, GenerateAllParentheses("[11(33)]"));
	EXPECT_EQ(0, GenerateAllParentheses("[{"));
}

string ReverseString(string A);
TEST(IB, ReverseString)
{
	EXPECT_EQ(string("gfedcba"), ReverseString("abcdefg"));
}

string SimplifyPath(string A);
TEST(IB, SimplifyPath)
{
	EXPECT_EQ(string("/home/abc/xyz"), SimplifyPath("/home/abc/def/../xyz"));
}

int RedundantBraces(string A);
TEST(IB, RedundantBraces)
{
	EXPECT_EQ(0, RedundantBraces("(a+(a+b))"));
}

vector<int> NearestSmallerElement(vector<int> &A);
TEST(IB, NearestSmallerElement)
{
	EXPECT_EQ(vector<int>({ -1, 4, -1, 2, 2 }), NearestSmallerElement(vector<int>({ 4, 5, 2, 10, 8 })));
}

int LargestRectangleArea(vector<int> &A);
TEST(IB, LargestRectangleArea)
{
	EXPECT_EQ(10, LargestRectangleArea(vector<int>({ 2,1,5,6,2,3 })));
}

vector<int> SlidingWindowMax(const vector<int> &A, int B);
TEST(IB, SlidingWindowMax)
{
	EXPECT_EQ(vector<int>({ 745, 745, 775, 775, 876, 876, 876, 876, 876, 876, 876, 951, 951, 951, 951, 951, 951, 951, 951, 951, 882, 882, 882, 882, 935, 935, 935, 935, 935, 935, 935, 935, 935, 892, 892, 892, 900, 900, 900, 937, 937, 937 }), SlidingWindowMax(vector<int>({ 648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368 }), 9));
}

int EvaluateExpression(vector<string> &A);
TEST(IB, EvaluateExpression)
{
	EXPECT_EQ(9, EvaluateExpression(vector<string>({ "2", "1", "+", "3", "*" })));
}

int RainWaterTrapped(const vector<int> &A);
TEST(IB, RainWaterTrapped)
{
	EXPECT_EQ(6, RainWaterTrapped(vector<int>({ 0,1,0,2,1,0,1,3,2,1,2,1 })));
}

ListNode* Subtract(ListNode* A);
TEST(IB, Subtract)
{
	ListNode *A = MakeList({ 1, 2, 3, 4, 5 });
	vector<int> B = List2Vec(Subtract(A));
	ListNode *C = MakeList({ 4, 2, 3, 4, 5 });
	vector<int> D = List2Vec(C);
	EXPECT_EQ(B, D);
}

vector<int> NextGreater(vector<int> &A);
TEST(IB, NextGreater)
{
	EXPECT_EQ(vector<int>({ 5, 10, 10, -1 }), NextGreater(vector<int>({ 4, 5, 2, 10 })));
}

int Mod(int A, int B, int C);
TEST(IB, Mod)
{
	EXPECT_EQ(2, Mod(2, 3, 3));
}

ListNode* ReverseLinkedList(ListNode* A);
TEST(IB, ReverseLinkedList)
{
	ListNode *A = MakeList({ 1, 2, 3 });
	vector<int> B = List2Vec(ReverseLinkedList(A));
	ListNode *C = MakeList({ 3, 2, 1 });
	vector<int> D = List2Vec(C);
	EXPECT_EQ(B, D);
}

vector<vector<int> > Subset(vector<int> &A);
TEST(IB, Subset)
{
	EXPECT_EQ(vector<vector<int>>({ {}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3} }), Subset(vector<int>({ 1,2,3 })));
}

vector<vector<int> > Combinations(int A, int B);
TEST(IB, Combinations)
{
	EXPECT_EQ(vector<vector<int>>({ {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4} }), Combinations(4, 2));
}

vector<vector<int> > CombinationSum(vector<int> &A, int B);
TEST(IB, CombinationSum)
{
	EXPECT_EQ(vector<vector<int> >({{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 8, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 10, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 16, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 11, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 10, }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 11, }, { 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 8, }, { 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, }, { 1, 1, 1, 1, 1, 1, 1, 10, 11, }, { 1, 1, 1, 1, 1, 1, 6, 6, 10, }, { 1, 1, 1, 1, 1, 1, 6, 8, 8, }, { 1, 1, 1, 1, 1, 1, 6, 16, }, { 1, 1, 1, 1, 1, 1, 11, 11, }, { 1, 1, 1, 1, 1, 6, 6, 11, }, { 1, 1, 1, 1, 6, 6, 6, 6, }, { 1, 1, 1, 1, 6, 8, 10, }, { 1, 1, 1, 1, 8, 8, 8, }, { 1, 1, 1, 1, 8, 16, }, { 1, 1, 1, 6, 8, 11, }, { 1, 1, 6, 6, 6, 8, }, { 1, 1, 6, 10, 10, }, { 1, 1, 8, 8, 10, }, { 1, 1, 10, 16, }, { 1, 6, 10, 11, }, { 1, 8, 8, 11, }, { 1, 11, 16, }, { 6, 6, 6, 10, }, { 6, 6, 8, 8, }, { 6, 6, 16, }, { 6, 11, 11, }, { 8, 10, 10, }}), CombinationSum(vector<int>({ 8, 10, 6, 11, 1, 16, 8 }), 28));
}

vector<vector<int> > CombinationSum2(vector<int> &A, int B);
TEST(IB, CombinationSum2)
{
	EXPECT_EQ(vector<vector<int> >({ { 1, 1, 6 },{ 1, 2, 5 },{ 1, 7 },{ 2, 6 } }), CombinationSum2(vector<int>({ 10, 1, 2, 7, 6, 1, 5 }), 8));
}

vector<vector<int> > SubsetsWithDup(vector<int> &A);
TEST(IB, SubsetsWithDup)
{
	EXPECT_EQ(vector<vector<int> >({ {}, {1}, {1,2}, {1,2,2}, {2}, {2, 2} }), SubsetsWithDup(vector<int>({ 1,2,2 })));
}

vector<string> LetterCombinations(string A);
TEST(IB, LetterCombinations)
{
	EXPECT_EQ(vector<string>({ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }), LetterCombinations("23"));
}

vector<vector<string> > PalindromePartitioning(string A);
TEST(IB, PalindromePartitioning)
{
	EXPECT_EQ(vector<vector<string> >({ {"a", "a", "b"}, { "aa", "b" } }), PalindromePartitioning("aab"));
}

vector<string> GenerateParenthesis(int A);
TEST(IB, GenerateParenthesis)
{
	EXPECT_EQ(vector<string>({ "((()))", "(()())", "(())()", "()(())", "()()()" }), GenerateParenthesis(3));
}

vector<vector<string> > NQueens(int A);
TEST(IB, NQueens)
{
	EXPECT_EQ(vector<vector<string>>({ {".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."} }), NQueens(4));
}

void SolveSudoku(vector<vector<char> > &A);
TEST(IB, SolveSudoku)
{
	vector<vector<char>> A({ { '5','3','.','.','7','.','.','.','.' },{ '6','.','.','1','9','5','.','.','.' },{ '.','9','8','.','.','.','.','6','.' },{ '8','.','.','.','6','.','.','.','3' },{ '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },{ '.','6','.','.','.','.','2','8','.' },{ '.','.','.','4','1','9','.','.','5' },{ '.','.','.','.','8','.','.','7','9' } });
	vector<vector<char>> B({ { '5','3','4','6','7','8','9','1','2' },{ '6','7','2','1','9','5','3','4','8' },{ '1','9','8','3','4','2','5','6','7' },{ '8','5','9','7','6','1','4','2','3' },{ '4','2','6','8','5','3','7','9','1' },{ '7','1','3','9','2','4','8','5','6' },{ '9','6','1','5','3','7','2','8','4' },{ '2','8','7','4','1','9','6','3','5' },{ '3','4','5','2','8','6','1','7','9' } });
	SolveSudoku(A);
	EXPECT_EQ(B, A);
}

vector<vector<int> > GetAllPermute(vector<int> &A);
TEST(IB, GetAllPermute)
{
	vector<vector<int>> A = GetAllPermute(vector<int>({ 1,2,3 }));
	sort(A.begin(), A.end());
	EXPECT_EQ(vector<vector<int>>({ { 1, 2, 3 },{ 1, 3, 2 },{ 2, 1, 3 },{ 2, 3, 1 },{ 3, 1, 2 },{ 3, 2, 1 } }), A);
}

vector<int> GrayCode(int A);
TEST(IB, GrayCode)
{
	EXPECT_EQ(vector<int>({ 0,1,3,2,6,7,5,4 }), GrayCode(3));
}

string GetPermutation(int A, int B);
TEST(IB, GetPermutation)
{
	EXPECT_EQ("23451", GetPermutation(5, 34));
}

int Colorful(int A);
TEST(IB, Colorful)
{
	EXPECT_EQ(1, Colorful(234));
	EXPECT_EQ(1, Colorful(23));
	EXPECT_EQ(0, Colorful(123));
}

vector<int> LargeSequenceZero(vector<int> &A);
TEST(IB, LargeSequenceZero)
{
	EXPECT_EQ(vector<int>({0}), LargeSequenceZero(vector<int>({ 0, 22, 7, 21, -11, -6, -7, -16, -2 })));
	EXPECT_EQ(vector<int>({ }), LargeSequenceZero(vector<int>({ -19, 8, 2, -8, 19, 5, -2, -23 })));
	EXPECT_EQ(vector<int>({ 1,2,-3 }), LargeSequenceZero(vector<int>({ 1, 2, -3, 3 })));
}

vector<int> TwoSum(const vector<int> &A, int B);
TEST(IB, TwoSum)
{
	EXPECT_EQ(vector<int>({ 1, 2 }), TwoSum(vector<int>({ 1, 1, 1 }), 2));
	EXPECT_EQ(vector<int>({ 4, 8 }), TwoSum(vector<int>({ 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 }), -3));
	EXPECT_EQ(vector<int>({ 3, 4 }), TwoSum(vector<int>({ 10, -3, 5, -7, -4, 5, 6, -7, 8, -5, 8, 0, 8, -5, -10, -1, 1, -6, 4, -1, -2, -2, 10, -2, -4, -7, 5, 1, 7, -10, 0, 5, 8, 6, -8, 8, -8, -8, 3, -9, -10, -5, -5, -10, 10, -4, 8, 0, -6, -2, 3, 7, -5, 5, 1, -7, 0, -5, 1, -3, 10, -4, -3, 3, 3, 5, 1, -2, -6, 3, -4, 10, -10, -3, -8, 2, -2, -3, 0, 10, -6, -8, -10, 6, 7, 0, 3, 9, -10, -7, 8, -7, -7 }), -2));
}

vector<vector<int> > FourSum(vector<int> &A, int B);
TEST(IB, FourSum)
{
	EXPECT_EQ(vector<vector<int> >({ { -8, -7, 3, 9, },{ -8, -5, 1, 9, },{ -8, -5, 3, 7, },{ -8, -4, 2, 7, },{ -8, -3, -1, 9, },{ -8, -3, 1, 7, },{ -8, -3, 4, 4, },{ -8, -2, 3, 4, },{ -8, -1, 2, 4, },{ -8, -1, 3, 3, },{ -8, 1, 2, 2, },{ -7, -7, 2, 9, },{ -7, -7, 4, 7, },{ -7, -5, 2, 7, },{ -7, -4, -1, 9, },{ -7, -4, 1, 7, },{ -7, -4, 4, 4, },{ -7, -3, -2, 9, },{ -7, -3, 3, 4, },{ -7, -2, -1, 7, },{ -7, -2, 2, 4, },{ -7, -2, 3, 3, },{ -7, -1, 1, 4, },{ -7, -1, 2, 3, },{ -5, -5, -2, 9, },{ -5, -5, 3, 4, },{ -5, -4, -3, 9, },{ -5, -4, -1, 7, },{ -5, -4, 2, 4, },{ -5, -4, 3, 3, },{ -5, -3, -2, 7, },{ -5, -3, 1, 4, },{ -5, -3, 2, 3, },{ -5, -2, 1, 3, },{ -5, -2, 2, 2, },{ -5, -1, 1, 2, },{ -4, -4, -4, 9, },{ -4, -4, -2, 7, },{ -4, -4, 1, 4, },{ -4, -4, 2, 3, },{ -4, -3, -3, 7, },{ -4, -3, 1, 3, },{ -4, -3, 2, 2, },{ -4, -2, -1, 4, },{ -4, -2, 1, 2, },{ -3, -3, -1, 4, },{ -3, -3, 1, 2, },{ -3, -2, -1, 3, }}), FourSum(vector<int>({ 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 }), -3));
	EXPECT_EQ(vector<vector<int> >({ { -10, -10, 10, 10, },{ -10, -9, 9, 10, },{ -10, -8, 8, 10, },{ -10, -8, 9, 9, },{ -10, -7, 7, 10, },{ -10, -7, 8, 9, },{ -10, -6, 6, 10, },{ -10, -6, 7, 9, },{ -10, -6, 8, 8, },{ -10, -5, 5, 10, },{ -10, -5, 6, 9, },{ -10, -5, 7, 8, },{ -10, -4, 4, 10, },{ -10, -4, 5, 9, },{ -10, -4, 6, 8, },{ -10, -4, 7, 7, },{ -10, -3, 3, 10, },{ -10, -3, 4, 9, },{ -10, -3, 5, 8, },{ -10, -3, 6, 7, },{ -10, -2, 2, 10, },{ -10, -2, 3, 9, },{ -10, -2, 4, 8, },{ -10, -2, 5, 7, },{ -10, -2, 6, 6, },{ -10, -1, 1, 10, },{ -10, -1, 2, 9, },{ -10, -1, 3, 8, },{ -10, -1, 4, 7, },{ -10, -1, 5, 6, },{ -10, 0, 0, 10, },{ -10, 0, 1, 9, },{ -10, 0, 2, 8, },{ -10, 0, 3, 7, },{ -10, 0, 4, 6, },{ -10, 0, 5, 5, },{ -10, 1, 1, 8, },{ -10, 1, 2, 7, },{ -10, 1, 3, 6, },{ -10, 1, 4, 5, },{ -10, 2, 2, 6, },{ -10, 2, 3, 5, },{ -10, 2, 4, 4, },{ -9, -9, 8, 10, },{ -9, -9, 9, 9, },{ -9, -8, 7, 10, },{ -9, -8, 8, 9, },{ -9, -7, 6, 10, },{ -9, -7, 7, 9, },{ -9, -7, 8, 8, },{ -9, -6, 5, 10, },{ -9, -6, 6, 9, },{ -9, -6, 7, 8, },{ -9, -5, 4, 10, },{ -9, -5, 5, 9, },{ -9, -5, 6, 8, },{ -9, -5, 7, 7, },{ -9, -4, 3, 10, },{ -9, -4, 4, 9, },{ -9, -4, 5, 8, },{ -9, -4, 6, 7, },{ -9, -3, 2, 10, },{ -9, -3, 3, 9, },{ -9, -3, 4, 8, },{ -9, -3, 5, 7, },{ -9, -3, 6, 6, },{ -9, -2, 1, 10, },{ -9, -2, 2, 9, },{ -9, -2, 3, 8, },{ -9, -2, 4, 7, },{ -9, -2, 5, 6, },{ -9, -1, 0, 10, },{ -9, -1, 1, 9, },{ -9, -1, 2, 8, },{ -9, -1, 3, 7, },{ -9, -1, 4, 6, },{ -9, -1, 5, 5, },{ -9, 0, 0, 9, },{ -9, 0, 1, 8, },{ -9, 0, 2, 7, },{ -9, 0, 3, 6, },{ -9, 0, 4, 5, },{ -9, 1, 1, 7, },{ -9, 1, 2, 6, },{ -9, 1, 3, 5, },{ -9, 1, 4, 4, },{ -9, 2, 2, 5, },{ -9, 2, 3, 4, },{ -8, -8, 6, 10, },{ -8, -8, 7, 9, },{ -8, -8, 8, 8, },{ -8, -7, 5, 10, },{ -8, -7, 6, 9, },{ -8, -7, 7, 8, },{ -8, -6, 4, 10, },{ -8, -6, 5, 9, },{ -8, -6, 6, 8, },{ -8, -6, 7, 7, },{ -8, -5, 3, 10, },{ -8, -5, 4, 9, },{ -8, -5, 5, 8, },{ -8, -5, 6, 7, },{ -8, -4, 2, 10, },{ -8, -4, 3, 9, },{ -8, -4, 4, 8, },{ -8, -4, 5, 7, },{ -8, -4, 6, 6, },{ -8, -3, 1, 10, },{ -8, -3, 2, 9, },{ -8, -3, 3, 8, },{ -8, -3, 4, 7, },{ -8, -3, 5, 6, },{ -8, -2, 0, 10, },{ -8, -2, 1, 9, },{ -8, -2, 2, 8, },{ -8, -2, 3, 7, },{ -8, -2, 4, 6, },{ -8, -2, 5, 5, },{ -8, -1, -1, 10, },{ -8, -1, 0, 9, },{ -8, -1, 1, 8, },{ -8, -1, 2, 7, },{ -8, -1, 3, 6, },{ -8, -1, 4, 5, },{ -8, 0, 0, 8, },{ -8, 0, 1, 7, },{ -8, 0, 2, 6, },{ -8, 0, 3, 5, },{ -8, 0, 4, 4, },{ -8, 1, 1, 6, },{ -8, 1, 2, 5, },{ -8, 1, 3, 4, },{ -8, 2, 2, 4, },{ -7, -7, 4, 10, },{ -7, -7, 5, 9, },{ -7, -7, 6, 8, },{ -7, -7, 7, 7, },{ -7, -6, 3, 10, },{ -7, -6, 4, 9, },{ -7, -6, 5, 8, },{ -7, -6, 6, 7, },{ -7, -5, 2, 10, },{ -7, -5, 3, 9, },{ -7, -5, 4, 8, },{ -7, -5, 5, 7, },{ -7, -5, 6, 6, },{ -7, -4, 1, 10, },{ -7, -4, 2, 9, },{ -7, -4, 3, 8, },{ -7, -4, 4, 7, },{ -7, -4, 5, 6, },{ -7, -3, 0, 10, },{ -7, -3, 1, 9, },{ -7, -3, 2, 8, },{ -7, -3, 3, 7, },{ -7, -3, 4, 6, },{ -7, -3, 5, 5, },{ -7, -2, -1, 10, },{ -7, -2, 0, 9, },{ -7, -2, 1, 8, },{ -7, -2, 2, 7, },{ -7, -2, 3, 6, },{ -7, -2, 4, 5, },{ -7, -1, -1, 9, },{ -7, -1, 0, 8, },{ -7, -1, 1, 7, },{ -7, -1, 2, 6, },{ -7, -1, 3, 5, },{ -7, -1, 4, 4, },{ -7, 0, 0, 7, },{ -7, 0, 1, 6, },{ -7, 0, 2, 5, },{ -7, 0, 3, 4, },{ -7, 1, 1, 5, },{ -7, 1, 2, 4, },{ -7, 2, 2, 3, },{ -6, -6, 2, 10, },{ -6, -6, 3, 9, },{ -6, -6, 4, 8, },{ -6, -6, 5, 7, },{ -6, -6, 6, 6, },{ -6, -5, 1, 10, },{ -6, -5, 2, 9, },{ -6, -5, 3, 8, },{ -6, -5, 4, 7, },{ -6, -5, 5, 6, },{ -6, -4, 0, 10, },{ -6, -4, 1, 9, },{ -6, -4, 2, 8, },{ -6, -4, 3, 7, },{ -6, -4, 4, 6, },{ -6, -4, 5, 5, },{ -6, -3, -1, 10, },{ -6, -3, 0, 9, },{ -6, -3, 1, 8, },{ -6, -3, 2, 7, },{ -6, -3, 3, 6, },{ -6, -3, 4, 5, },{ -6, -2, -2, 10, },{ -6, -2, -1, 9, },{ -6, -2, 0, 8, },{ -6, -2, 1, 7, },{ -6, -2, 2, 6, },{ -6, -2, 3, 5, },{ -6, -2, 4, 4, },{ -6, -1, -1, 8, },{ -6, -1, 0, 7, },{ -6, -1, 1, 6, },{ -6, -1, 2, 5, },{ -6, -1, 3, 4, },{ -6, 0, 0, 6, },{ -6, 0, 1, 5, },{ -6, 0, 2, 4, },{ -6, 1, 1, 4, },{ -6, 1, 2, 3, },{ -5, -5, 0, 10, },{ -5, -5, 1, 9, },{ -5, -5, 2, 8, },{ -5, -5, 3, 7, },{ -5, -5, 4, 6, },{ -5, -5, 5, 5, },{ -5, -4, -1, 10, },{ -5, -4, 0, 9, },{ -5, -4, 1, 8, },{ -5, -4, 2, 7, },{ -5, -4, 3, 6, },{ -5, -4, 4, 5, },{ -5, -3, -2, 10, },{ -5, -3, -1, 9, },{ -5, -3, 0, 8, },{ -5, -3, 1, 7, },{ -5, -3, 2, 6, },{ -5, -3, 3, 5, },{ -5, -3, 4, 4, },{ -5, -2, -2, 9, },{ -5, -2, -1, 8, },{ -5, -2, 0, 7, },{ -5, -2, 1, 6, },{ -5, -2, 2, 5, },{ -5, -2, 3, 4, },{ -5, -1, -1, 7, },{ -5, -1, 0, 6, },{ -5, -1, 1, 5, },{ -5, -1, 2, 4, },{ -5, 0, 0, 5, },{ -5, 0, 1, 4, },{ -5, 0, 2, 3, },{ -5, 1, 1, 3, },{ -5, 1, 2, 2, },{ -4, -4, -2, 10, },{ -4, -4, -1, 9, },{ -4, -4, 0, 8, },{ -4, -4, 1, 7, },{ -4, -4, 2, 6, },{ -4, -4, 3, 5, },{ -4, -4, 4, 4, },{ -4, -3, -3, 10, },{ -4, -3, -2, 9, },{ -4, -3, -1, 8, },{ -4, -3, 0, 7, },{ -4, -3, 1, 6, },{ -4, -3, 2, 5, },{ -4, -3, 3, 4, },{ -4, -2, -2, 8, },{ -4, -2, -1, 7, },{ -4, -2, 0, 6, },{ -4, -2, 1, 5, },{ -4, -2, 2, 4, },{ -4, -1, -1, 6, },{ -4, -1, 0, 5, },{ -4, -1, 1, 4, },{ -4, -1, 2, 3, },{ -4, 0, 0, 4, },{ -4, 0, 1, 3, },{ -4, 0, 2, 2, },{ -4, 1, 1, 2, },{ -3, -3, -2, 8, },{ -3, -3, -1, 7, },{ -3, -3, 0, 6, },{ -3, -3, 1, 5, },{ -3, -3, 2, 4, },{ -3, -2, -2, 7, },{ -3, -2, -1, 6, },{ -3, -2, 0, 5, },{ -3, -2, 1, 4, },{ -3, -2, 2, 3, },{ -3, -1, -1, 5, },{ -3, -1, 0, 4, },{ -3, -1, 1, 3, },{ -3, -1, 2, 2, },{ -3, 0, 0, 3, },{ -3, 0, 1, 2, },{ -3, 1, 1, 1, },{ -2, -2, -2, 6, },{ -2, -2, -1, 5, },{ -2, -2, 0, 4, },{ -2, -2, 1, 3, },{ -2, -2, 2, 2, },{ -2, -1, -1, 4, },{ -2, -1, 0, 3, },{ -2, -1, 1, 2, },{ -2, 0, 0, 2, },{ -2, 0, 1, 1, },{ -1, -1, 0, 2, },{ -1, -1, 1, 1, },{ -1, 0, 0, 1, },{ 0, 0, 0, 0, } }), FourSum(vector<int>({ 9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2 }), 0));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
