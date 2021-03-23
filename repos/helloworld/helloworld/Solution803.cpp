#include "Solution803.h"

int Solution803::checkNeighbours(vector<vector<int>>& grids, int x, int y, int& count) {
	if (grids[x][y] == 0) {
		return count;
	}
	if (x == 0) {
		return count;
	}

}

vector<int> Solution803::hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
	if (hits.size() == 0) {
		return {};
	}
	int lens = hits.size();
	for (int i = 0; i < lens; i++) {
		int x = hits[i][0];
		int y = hits[i][1];
		grid[x][y] = 0;
		int count = 0;
		checkNeighbours(grid, x + 1, y, count);
		checkNeighbours(grid, x - 1, y, count);
		checkNeighbours(grid, x, y + 1, count);
		checkNeighbours(grid, x, y - 1, count);
	}
}