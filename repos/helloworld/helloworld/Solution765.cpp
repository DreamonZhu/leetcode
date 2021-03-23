#include "Solution765.h"

int Solution765::minSwapsCouples(vector<int>& row) {
    int left = 0;
    int right = 1;
    int lens = row.size();
    int count = 0;
    while (left < lens - 1) {
        if (row[left] / 2 == row[right] / 2) {
            if (right - left != 1) {
                int tmp = row[left + 1];
                row[left + 1] = row[right];
                row[right] = tmp;
                count++;
            }
            left += 2;
            right = left;
        }
        right++;
    }
    return count;
}