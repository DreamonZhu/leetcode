#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution1202
{
private:
	class UnionFind {
	public:
		vector<int> parent;

		UnionFind(int n);
		void Union(int a, int b);
		int find(int x);
	};
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs);
};

