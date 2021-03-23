#include "Solution228.h"

vector<string> Solution228::summaryRanges(vector<int>& nums) {
	vector<string> res;
	if (nums.size() == 0) {
		res.push_back("");
		return res;
	}

	if (nums.size() == 1) {
		res.push_back(to_string(nums[0]));
		return res;
	}

	int lens = nums.size();
	int count = 0;
	for (int i = 0; i < lens - 1; i++) {
		if (nums[i + 1LL] > 1LL + nums[i]) {
			if (count == 0) {
				res.push_back(to_string(nums[i]) + "");
			}
			else {
				res.push_back(to_string(nums[i] - count) + "->" + to_string(nums[i]));
				count = 0;
			}
		}
		else {
			count++;
		}
		if (i + 2 == lens) {
			if (count == 0) {
				res.push_back(to_string(nums[i + 1LL]) + "");
			}
			else {
				res.push_back(to_string(nums[i + 1LL] - count) + "->" + to_string(nums[i + 1LL]));
			}
		}
	}
	return res;
}