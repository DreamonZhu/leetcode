#include "Solution5663.h"
#include <queue>

int Solution5663::kthLargestValue(vector<vector<int>>& matrix, int k) {
	priority_queue<int> pq;
	int rows = matrix.size();
	int cols = matrix[0].size();
	// res �������ÿ�����괦�����������
	vector<vector<int>> res(rows, vector<int>(cols));
	// argu[i][j] ������ǵ�i�е��������ֵ����ֻ��: argu[i][j]=matrix[i][j]^matrix[i][j-1]^...^matrix[i][0];
	// ���ǣ� res[i][j] �Ķ�̬���ӹ�ϵ�ǣ�
	// i = 0, res[i][j] = argu[i][j];
	// i != 0, res[i][j] = res[i-1][j] ^ argu[i][j];
	// ע��߽��������� j = 0 ʱ�� res[i][0] = res[i-1][0]^matrix[i-1][0], res[0][0]=matrix[0][0];
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