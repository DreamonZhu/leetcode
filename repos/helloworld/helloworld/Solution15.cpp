#include "Solution15.h"
#include <algorithm>
#include <set>

vector<vector<int>> Solution15::threeSum(vector<int>& nums) {
	int lens = nums.size();
	vector<vector<int>> res;
	if (lens < 3)
		return {};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < lens - 1; i++) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		set<int> d;
		for (int j = i + 1; j < lens; j++) {
			if (d.count(nums[j]) == 0) {
				d.insert(-nums[i] - nums[j]);
			}
			else {
				res.push_back({ nums[i], nums[j], -nums[i] - nums[j] });
			}
		}
	}
	return res;
}