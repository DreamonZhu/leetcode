#include "Solution435.h"
#include <algorithm>

//int Solution435::eraseOverlapIntervals(vector<vector<int>>& intervals) {
//	//��̬�滮�ⷨ
//	if (intervals.size() == 0) {
//		return 0;
//	}
//
//	sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
//		return a[0] < b[0];
//		});
//
//	int nums = intervals.size();
//	vector<int> f(nums, 1);
//
//	for (int i = 1; i < nums; i++) {
//		for (int j = 0; j < i; j++) {
//			if (intervals[i][0] >= intervals[j][1]) {
//				//f[i]����ǰ�Ե�i������Ϊ��������ʱ������������
//				f[i] = max(f[i], f[j] + 1);
//			}
//		}
//	}
//
//	return nums - *max_element(f.begin(), f.end());
//
//}

int Solution435::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	//̰���㷨
	if (intervals.size() == 0) {
		return 0;
	}

	sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
		return a[1] < b[1];
		});

	int nums = intervals.size();
	vector<int> intervals_init = intervals[0];
	int max_intervals = 1;
	for (int i = 1; i < nums; i++) {
		if (intervals[i][0] >= intervals_init[1]) {
			++max_intervals;
			intervals_init = intervals[i];
		}
	}
	
	return nums - max_intervals;

}

