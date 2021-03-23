#include "Solution992_double_pionters.h"

int Solution992_double_pionters::subarraysWithKDistinct(vector<int>& A, int K) {
	return maxSubarray(A, K) - maxSubarray(A, K - 1);
}

int Solution992_double_pionters::maxSubarray(vector<int>& A, int K) {
	int left = 0, right = 0;
	int count = 0;
	int res = 0;
	int lens = A.size();
	vector<int> freq(lens + 1, 0);
	while (right < lens) {
		if (freq[A[right]] == 0) {
			count++;
		}
		freq[A[right]]++;
		right++;
		while (count > K) {
			freq[A[left]]--;
			if (freq[A[left]] == 0) {
				count--;
			}
			left++;
		}
		res += right - left;
	}
	return res;
}