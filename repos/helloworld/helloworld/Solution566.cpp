#include "Solution566.h"
#include <queue>

vector<vector<int>> Solution566::matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int rows = nums.size();
    int cols = nums[0].size();
    if (rows * cols != r * c) {
        return nums;
    }
    queue<int> q;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            q.push(nums[i][j]);
        }
    }
    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = q.front();
            q.pop();
        }
    }
    return res;
}