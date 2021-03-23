#include "Solution1004.h"

int Solution1004::longestOnes(vector<int>& A, int K) {
    int lens = A.size();
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < lens) {
        if (K >= 0) {
            if (A[right++] == 0) {
                K--;
            }
        }
        else {
            count = max(count, right - left - 1);
            if (A[left++] == 0) {
                K++;
            }
        }
    }
    if (K >= 0) {
        count = max(count, right - left);
    }
    else {
        count = max(count, right - left - 1);
    }
    return count;
}