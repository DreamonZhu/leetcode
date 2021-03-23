#include "Solution1018.h"

vector<bool> Solution1018::prefixesDivBy5(vector<int>& A) {
	if (A.size() == 0) {
		return {};
	}
	int lens = A.size();
	vector<bool> res;
	long long int num = 0;
	for (int i = 0; i < lens; i++) {
		//num = num * 2 + A[i];
		num = ((num << 1) + A[i]) % 5;
		if (num % 5 == 0) {
			res.push_back(1);
		}
		else
		{
			res.push_back(0);
		}
	}
	return res;
}