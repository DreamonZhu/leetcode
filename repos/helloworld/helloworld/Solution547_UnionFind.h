#pragma once
#include <vector>

using namespace std;

class Solution547_UnionFind
{
public:
	class UnionFind {
	public:
		vector<int> parent;
		vector<double> weight;
		UnionFind(int n);
		void Union(int a, int b, double value);
		int find(int x);
	};
	int findCircleNum(vector<vector<int>> isConnected);
};

