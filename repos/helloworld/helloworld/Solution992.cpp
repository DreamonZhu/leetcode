#include "Solution992.h"
#include <iostream>
#include <unordered_map>

int Solution992::subarraysWithKDistinct(vector<int>& A, int K) {
    //运行超时
    int lens = A.size();
    int count = 0;
    for (int windows_lens = K; windows_lens <= lens; windows_lens++) {
        int left = 0, right = 0;
        unordered_map<int, int> ele_nums;
        //ele_nums.emplace(A[left], 1);
        while (right < lens) {
            if (right - left + 1 == windows_lens) {
                if (ele_nums.count(A[right])) {
                    ele_nums.at(A[right])++;
                }
                else {
                    ele_nums.emplace(A[right], 1);
                }
                if (ele_nums.size() == K) {
                    count++;
                    cout << windows_lens << ": 第 " << count << " 个" << endl;
                }
                ele_nums.at(A[left])--;
                if (ele_nums.at(A[left]) == 0) {
                    ele_nums.erase(A[left]);
                }
                left++;
                right++;
            }
            else {
                if (ele_nums.count(A[right])) {
                    ele_nums.at(A[right])++;
                }
                else {
                    ele_nums.emplace(A[right], 1);
                }
                right++;
            }
        }
    }
    return count;
}