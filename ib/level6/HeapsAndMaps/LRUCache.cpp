/*************************************************************************************************
LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key 
if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present.

When the cache reaches its capacity, it should invalidate the least recently used item 
before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. 
Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of ¡°least recently used¡± : An access to an item is defined 
as a get or a set operation of the item. 
¡°Least recently used¡± item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.
Example :

Input :
capacity = 2
set(1, 10)
set(5, 12)
get(5)        returns 12
get(1)        returns 10
get(10)       returns -1
set(6, 14)    this pushes out key = 5 as LRU is full.
get(5)        returns -1
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <functional>
#include <iostream>
#include <cassert>

#include "LRUCache.h"

using namespace std;

#define OWN

#ifdef OWN
LRUCache::LRUCache(int capacity) {
	m_nCapacity = capacity;
	M.clear();
}

int LRUCache::get(int key) {
	if (M.find(key) == M.end()) return -1;

	int i = (int)C.size()-1;
	for (; i>=0 ; i--)
	{
		if (i < C.size()-1 && C[i] == key)
		{
			C.push_back(key);
			C.erase(C.begin() + i);
			break;
		}
	}

	return M[key];
}

void LRUCache::set(int key, int value) {
	if (M.count(key) == 0)
	{
		if (m_nCapacity == (int)C.size())
		{
			M.erase(C[0]);
			C.erase(C.begin());
		}
		C.push_back(key);
		M[key] = value;
	}
	else
	{
		int i = (int)C.size() - 1;
		for (; i >= 0; i--)
		{
			if (i < C.size() - 1 && C[i] == key)
			{
				C.push_back(key);
				C.erase(C.begin() + i);
				break;
			}
		}
		M[key] = value;
	}
}
#else

#endif