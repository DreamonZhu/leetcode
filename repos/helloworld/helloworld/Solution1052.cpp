#include "Solution1052.h"

int Solution1052::maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int lens = customers.size();
    int left = 0;
    int right = left + X - 1;
    int count = 0;
    for (int i = 0; i < lens; i++) {
        if (i <= right) {
            count += customers[i];
        }
        else if (grumpy[i] == 0) {
            count += customers[i];
        }
    }
    int max_nums = 0;
    while (right < lens - 1) {
        max_nums = max(max_nums, count);
        if (grumpy[++right] == 1) {
            count += customers[right];
        }
        if (grumpy[left++] == 1) {
            count -= customers[left - 1];
        }
    }
    return max(max_nums, count);
}