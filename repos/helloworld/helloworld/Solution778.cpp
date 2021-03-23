#include "Solution778.h"
#include <queue>

int Solution778::swimInWater(vector<vector<int>>& grid) {
	//define a direction vector
	vector<vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };

	//solution1: binary search
	int N = grid.size();
	int ans = 0;
	int left = 0; 
	int right = N * N - 1;
	while (left <= right) {
		vector<int> seen(N * N, 0);
		int mid = (left + right) / 2;
		queue<tuple<int, int, int>> q;
		q.emplace(0, 0, 0);
		while (!q.empty())
		{
			auto [x, y, id_cur] = q.front();
			if (grid[x][y] > mid) {
				break;
			}
			seen[id_cur] = 1;
			q.pop();
			for (auto& item : directions) {
				int nx = x + item[0];
				int ny = y + item[1];
				int id_next = id_cur + item[0] * N + item[1];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !seen[id_next] && grid[nx][ny] <= mid) {
					q.emplace(x + item[0], y + item[1], id_next);
					seen[id_next] = 1;
				}
			}
		}
		if (seen[N * N - 1]) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}