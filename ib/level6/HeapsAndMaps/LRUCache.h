#ifndef LRUCACHE
#define LRUCACHE

#include <unordered_map>
#include <deque>

using namespace std;

class LRUCache
{
public:
	LRUCache::LRUCache(int capacity);
	int LRUCache::get(int key);
	void LRUCache::set(int key, int value);

	int m_nCapacity;
	unordered_map<int, int> M;
	deque<int> C;
};
#endif