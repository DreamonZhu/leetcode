#pragma once
#include <vector>

using namespace std;

class Solution1489
{
private:
	class UnionFind {
	public:
		vector<int> parent;
		vector<int> rank;

		UnionFind(int n);
		int Union(int x, int y);
		int find(int x);
	};

public:
	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges);
};

