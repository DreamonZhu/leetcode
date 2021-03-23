#include "Solution1046.h"
#include <algorithm>

int Solution1046::lastStoneWeight(vector<int> &stones) {
	//sort(stones.begin(), stones.end());
	while (!stones.empty()) {
		if (stones.size() == 1) {
			return stones.back();
		}
		sort(stones.begin(), stones.end());
		int num1 = stones.back();
		stones.pop_back();
		int num2 = stones.back();
		stones.pop_back();
		if (num1 != num2) {
			stones.push_back(num1 - num2);
		}
	}
	return 0;
}