#pragma once
#include <vector>

using namespace std;

class Solution1579
{
private:
	class UnionFind {
	public:
		vector<int> parent;
		vector<int> rank;
		int connected_nums;

		UnionFind(int n);
		int find(int x);
		int Union(int x, int y);
		int get_connected_nums();
	};
public:
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges);
};

