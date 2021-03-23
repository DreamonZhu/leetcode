#include "Solution338.h"

vector<int> Solution338::countBits(int num) {
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i <= num; i++) {
        int count = 1;
        int nums = 0;
        int x = i;
        while (x > 0) {
            count &= x;
            if (count == 1) {
                nums++;
            }
            x >>= 1;
            count = 1;
        }
        res.push_back(nums);
    }
    return res;
}