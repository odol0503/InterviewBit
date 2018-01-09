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

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> MergeIntervals(vector<Interval> &intervals, Interval newInterval);
vector<Interval> MergeOverlappingIntervals(vector<Interval> &A);

enum TEST_CASE
{
	eSPIRAL_ORDER_MATRIX,
	ePASCAL_TRIANGLE,
	eROW_PASCAL_TRIANGLE,
	eANTI_DIAGONALS,
	eNOBLE_INTEGER,
	eTRIPLETS_WITH_SUM,
	eLARGEST_NUMBER,
	eWAVE_ARRAY,
	eHOTEL_BOOKINGS,
	eMAX_DISTANCE,
	eMAXIMUM_UNSORTED_ARRAY,
	eFIND_DUPLICATE,
	eROTATE_MATRIX,
	ePRIME_SUM,
	eMERGE_INTERVALS,
	eNEXT_PERMUTATION,
	eFIND_PERMUTATION,
	eMERGE_OVERLAPPING_INTERVALS,
};

int main()
{
	TEST_CASE test = eMERGE_OVERLAPPING_INTERVALS;

	switch (test)
	{
	case eSPIRAL_ORDER_MATRIX:
	{

	}
	case ePASCAL_TRIANGLE:
	{

	}
	case eROW_PASCAL_TRIANGLE:
	{

	}
	case eANTI_DIAGONALS:
	{

	}
	case eNOBLE_INTEGER:
	{

	}
	case eTRIPLETS_WITH_SUM:
	{

	}
	case eLARGEST_NUMBER:
	{

	}
	case eWAVE_ARRAY:
	{

	}
	case eHOTEL_BOOKINGS:
	{

	}
	case eMAX_DISTANCE:
	{

	}
	case eMAXIMUM_UNSORTED_ARRAY:
	{

	}
	case eFIND_DUPLICATE:
	{
		vector<int> A = { 442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500 };
		int ret = FindDuplicate(A);
	}
	case eROTATE_MATRIX:
	{

	}
	case ePRIME_SUM:
	{

	}
	case eMERGE_INTERVALS:
	{
		vector<Interval> A = {
			Interval(6037774, 6198243), Interval(6726550, 7004541), Interval(8842554, 10866536), Interval(11027721, 11341296), Interval(11972532, 14746848),
			Interval(16374805, 16706396), Interval(17557262, 20518214), Interval(22139780, 22379559), Interval(27212352, 28404611), Interval(28921768, 29621583),
			Interval(29823256, 32060921), Interval(33950165, 36418956), Interval(37225039, 37785557), Interval(40087908, 41184444), Interval(41922814, 45297414),
			Interval(48142402, 48244133), Interval(48622983, 50443163), Interval(50898369, 55612831), Interval(57030757, 58120901), Interval(59772759, 59943999),
			Interval(61141939, 64859907), Interval(65277782, 65296274), Interval(67497842, 68386607), Interval(70414085, 73339545), Interval(73896106, 75605861),
			Interval(79672668, 84539434), Interval(84821550, 86558001), Interval(91116470, 92198054), Interval(96147808, 98979097), Interval(36210193, 61984219) };
		Interval B = { Interval(36210193, 61984219) };

		vector<Interval> ret = MergeIntervals(A, B);
		break;
	}
	case eNEXT_PERMUTATION:
	{
		vector<int> A = { 769, 533 };
		//vector<int> A = { 1,2,3, 4,5 };
		NextPermutation(A);
		break;
	}
	case eFIND_PERMUTATION:
	{
		string A = "IDDID";
		int B = 6;
		vector<int> ret = FindPermutation(A, B);
	}
	case eMERGE_OVERLAPPING_INTERVALS:
	{
		//vector<Interval> A = { Interval(4, 100), Interval(48, 94), Interval(16, 21), Interval(58, 71), Interval(36, 53), Interval(49, 68), Interval(18, 42), Interval(37, 90), Interval(68, 75), Interval(6, 57), Interval(25, 78), Interval(58, 79), Interval(18, 29), Interval(69, 94), Interval(5, 31), Interval(10, 87), Interval(21, 35), Interval(1, 32), Interval(7, 24), Interval(17, 85), Interval(30, 95), Interval(5, 63), Interval(1, 17), Interval(67, 100), Interval(53, 55), Interval(30, 63), Interval(7, 76), Interval(33, 51), Interval(62, 68), Interval(78, 83), Interval(12, 24), Interval(31, 73), Interval(64, 74), Interval(33, 40), Interval(51, 63), Interval(17, 31), Interval(14, 29), Interval(9, 15), Interval(39, 70), Interval(13, 67), Interval(27, 100), Interval(10, 71), Interval(18, 47), Interval(48, 79), Interval(70, 73), Interval(44, 59), Interval(68, 78), Interval(24, 67), Interval(32, 70), Interval(29, 94), Interval(45, 90), Interval(10, 76), Interval(12, 28), Interval(31, 78), Interval(9, 44), Interval(29, 83), Interval(21, 35), Interval(46, 93), Interval(66, 83), Interval(21, 72), Interval(29, 37), Interval(6, 11), Interval(56, 87), Interval(10, 26), Interval(11, 12), Interval(15, 88), Interval(3, 13), Interval(56, 70), Interval(40, 73), Interval(25, 62), Interval(63, 73), Interval(47, 74), Interval(8, 36) };
		vector<Interval> A = { Interval(92, 98), Interval(10, 86), Interval(61, 91), Interval(8, 71), Interval(53, 65), Interval(19, 79), Interval(20, 50) };
		vector<Interval> ret = MergeOverlappingIntervals(A);
	}
	}
	return 0;
}