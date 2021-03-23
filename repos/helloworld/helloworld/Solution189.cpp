#include "Solution189.h"

void Solution189::rotate(vector<int> &nums, int k) {
	for (int i = 0; i < k; i++) {
		int temp = nums.back();
		nums.pop_back();
		nums.insert(nums.begin(), temp);
	}
}