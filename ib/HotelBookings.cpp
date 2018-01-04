/*************************************************************************************************
Hotel Bookings Possible

A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms. Bookings contain an arrival date and a departure date. 
He wants to find out whether there are enough rooms in the hotel to satisfy the demand. 
Write a program that solves this problem in time O(N log N) .

Input:
First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:
A boolean which tells whether its possible to make a booking.
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input :
Arrivals :   [1 3 5]
Departures : [2 6 8]
K : 1

Return : False / 0
At day = 5, there are 2 guests in the hotel. But I have only one room.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

bool HotelBooking(vector<int> &arrive, vector<int> &depart, int K)
{
	assert(arrive.size() == depart.size());

	if (K == 0) return 0;

	size_t len = arrive.size();
	vector<pair<int, int>> it;
	for (size_t i = 0; i < len; i++)
	{
		it.push_back(make_pair(arrive[i], 1));
		it.push_back(make_pair(depart[i], 0));
	}

	sort(it.begin(), it.end());

	len *= 2;
	int cnt = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (it[i].second == 1) cnt++;
		else cnt--;

		if (cnt > K) return 0;
	}

	return 1;
}
