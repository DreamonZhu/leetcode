#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution399
{
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);

private:
	class UnionFind {
	public:
		vector<int> parent;
		vector<double> weight;
		UnionFind(int n);
		double is_connected(int x, int y);
		int find(int x);
		void Union(int x, int y, double value);
	};
};
