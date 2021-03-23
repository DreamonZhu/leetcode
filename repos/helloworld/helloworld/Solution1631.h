#pragma once
#include <vector>

using namespace std;

class Solution1631
{
private:
	static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
	int minimumEffortPath(vector<vector<int>>& heights);
};

