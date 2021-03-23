#include "Solution5663.h"
#include <queue>

int Solution5663::kthLargestValue(vector<vector<int>>& matrix, int k) {
	priority_queue<int> pq;
	int rows = matrix.size();
	int cols = matrix[0].size();
	// res 保存的是每个座标处的最终异或结果
	vector<vector<int>> res(rows, vector<int>(cols));
	// argu[i][j] 保存的是第i行的坐标异或值，即只有: argu[i][j]=matrix[i][j]^matrix[i][j-1]^...^matrix[i][0];
	// 于是： res[i][j] 的动态连接关系是：
	// i = 0, res[i][j] = argu[i][j];
	// i != 0, res[i][j] = res[i-1][j] ^ argu[i][j];
	// 注意边界条件，当 j = 0 时， res[i][0] = res[i-1][0]^matrix[i-1][0], res[0][0]=matrix[0][0];
	vector<vector<int>> argu(rows, vector<int>(cols));
	for (int i = 0; i < rows; i++) {
		argu[i][0] = matrix[i][0];
		if (i == 0) {
			res[i][0] = matrix[0][0];
			pq.push(res[i][0]);
		} else {
			res[i][0] = res[i - 1][0] ^ matrix[i][0];
			pq.push(res[i][0]);
		}
		for (int j = 1; j < cols; j++) {
			argu[i][j] = argu[i][j-1] ^ matrix[i][j];
			if (i == 0) {
				res[i][j] = argu[i][j];
				pq.push(res[i][j]);
				continue;
			}
			res[i][j] = res[i - 1][j] ^ argu[i][j];
			pq.push(res[i][j]);
		}
	}
	for (int i = 0; i < k - 1; i++) {
		pq.pop();
	}
	return pq.top();
}