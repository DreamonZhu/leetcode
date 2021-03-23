#pragma once
#include <vector>

using namespace std;

class Solution1319
{
private:
	class UnionFind {
	public:
		vector<int> parent;
		vector<int> rank;
		int connected_count;
		int rest;

		UnionFind(int n);
		int Union(int x, int y);
		int find(int x);
	};
public:
	int makeConnected(int n, vector<vector<int>>& connections);
};

