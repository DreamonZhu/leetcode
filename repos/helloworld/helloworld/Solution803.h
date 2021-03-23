#pragma once
#include <vector>

using namespace std;

class Solution803
{
public:
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits);
	int checkNeighbours(vector<vector<int>>& grids, int x, int y, int& count);
};

