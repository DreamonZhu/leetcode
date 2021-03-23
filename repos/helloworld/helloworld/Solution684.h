#pragma once
#include <vector>

using namespace std;

class Solution684
{
private:
	class UnionFind {
	public:
		vector<int> parent;

		UnionFind(int n);
		int find(int x);
		void Union(int x, int y);
	};
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges);
};

