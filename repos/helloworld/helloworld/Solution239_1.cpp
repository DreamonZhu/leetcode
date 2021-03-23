#include "Solution239_1.h"
#include <deque>

vector<int> Solution239_1::maxSlidingWindow(vector<int> nums, int k) {
	if (nums.size() < k) {
		return {};
	}
	int lens = nums.size();
	vector<int> res;
	deque<int> windows;
	for (int i = 0; i < lens; i++) {
		if (i >= k && windows[0] <= i - k) {
			windows.pop_front();
		}
		while (!windows.empty() && nums[windows.back()] <= nums[i]) {
				windows.pop_back();
		}
		windows.push_back(i);
		if (i >= k - 1) {
			res.push_back(nums[windows[0]]);
		}
	}
	return res;
}