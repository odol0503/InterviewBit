#ifndef LRUCACHE
#define LRUCACHE

#include <map>
#include <vector>

using namespace std;

class LRUCache
{
public:
	LRUCache::LRUCache(int capacity);
	int LRUCache::get(int key);
	void LRUCache::set(int key, int value);

	int m_nCapacity;
	map<int, int> M;
	vector<int> C;
};
#endif