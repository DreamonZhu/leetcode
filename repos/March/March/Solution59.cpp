#include "Solution59.h"

void Solution59::circle(int left, int right, int top, int bottom, vector<vector<int>>& mat, int start) {
    if (left > right || top > bottom) {
        return;
    }
    if (left == right) {
        for (int i = top; i <= bottom; i++) {
            mat[i][left] = start;
            start++;
        }
        return;
    }
    if (top == bottom) {
        for (int i = left; i <= right; i++) {
            mat[top][i] = start;
            start++;
        }
        return;
    }
    for (int i = left; i < right; i++) {
        mat[top][i] = start;
        start++;
    }
    for (int i = top; i < bottom; i++) {
        mat[i][right] = start;
        start++;
    }
    for (int i = right; i > left; i--) {
        mat[bottom][i] = start;
        start++;
    }
    for (int i = bottom; i > top; i--) {
        mat[i][left] = start;
        start++;
    }
    top++;
    left++;
    right--;
    bottom--;
    circle(left, right, top, bottom, mat, start);
}

vector<vector<int>> Solution59::generateMatrix(int n) {
    vector<vector<int>> mat(n, vector<int>(n));
    circle(0, n - 1, 0, n - 1, mat, 1);
    return mat;
}