#pragma once
#include <vector>

using namespace std;

class Solution947
{
private:
	class UnionFind {
	public:
		vector<int> parent;
		int count;

		UnionFind(int n);
		int find(int x);
		void Union(int x, int y);
		int getCount();
	};
public:
	int removeStones(vector<vector<int>>& stones);
};

