#include "Solution605.h"

bool Solution605::canPlaceFlowers(vector<int>& flowerbed, int n) {
	if (flowerbed.size() == 0) {
		return false;
	}

	if (n > (count(flowerbed.begin(), flowerbed.end(), 0) + 1) / 2) {
		return false;
	}

	int nums = flowerbed.size();
	int odd_zeros = 0;
	int even_zeros = 0;
	int i = 0;
	int flag = 0;
	while (i < nums) {
		if (flowerbed[i] == 1) {
			if (i % 2 == 0) {
				flag = 1;
			}
			else {
				flag = 2;
			}
			i++;
		}
		else {
			if (i % 2 == 0) {
				if (i + 1 < nums) {
					if (flowerbed[i + 1] == 1) {
						i++;
						continue;
					}
				}
				if (i > 0) {
					if (flowerbed[i - 1] == 1) {
						i++;
						continue;
					}
				}
				flowerbed[i] = 1;
				odd_zeros++;
			}
			else {
				if (i + 1 < nums) {
					if (flowerbed[i + 1] == 1) {
						i++;
						continue;
					}
				}
				if (i > 0) {
					if (flowerbed[i - 1] == 1) {
						i++;
						continue;
					}
				}
				flowerbed[i] = 1;
				even_zeros++;
			}
			i++;
		}
	}

	if (odd_zeros + even_zeros >= n) {
		return true;
	}
	return false;
}