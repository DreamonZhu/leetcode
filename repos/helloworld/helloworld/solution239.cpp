#include "solution239.h"
#include <deque>
#include "monotonicQueue.h"

//方式一：通过双端队列实现
//vector<int> solution239::maxSlidingWindow(vector<int>& nums, int k) {
//	int len = nums.size();
//	if (len * k == 0)
//		return {};
//	
//	vector<int> res;
//	//deque<int> *windows = new deque<int>();
//	deque<int> windows;
//	for (int i = 0; i < len; i++) {
//		if (i >= k && windows[0] <= i - k)
//			windows.pop_front();
//		while (!windows.empty() && nums[windows.back()] < nums[i]) {
//			windows.pop_back();
//		}
//		windows.push_back(i);
//		if (i >= k - 1) {
//			res.push_back(nums[windows[0]]);
//		}
//	}
//
//	return res;
//}

//方式二：通过单调队列实现

vector<int> solution239::maxSlidingWindow(vector<int>& nums, int k) {
	int len = nums.size();
	if (len * k == 0)
		return {};

	vector<int> res;
	monotonicQueue windows;
	for (int i = 0; i < k -1; i++) {
		windows.push(nums[i]);
	}
	//res.push_back(windows.max());

	for (int i = k - 1; i < len; i++) {
		windows.push(nums[i]);
		res.push_back(windows.max());
		windows.pop(nums[i - k + 1]);
	}

	return res;

}