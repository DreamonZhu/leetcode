#include "Solution839.h"

int Solution839::numSimilarGroups(vector<string>& strs) {
	int lens = strs.size();
	init(lens);
	for (int i = 0; i < lens; i++) {
		for (int j = i + 1; j < lens; j++) {
			int fi = find(i);
			int fj = find(j);
			if (fi == fj) {
				continue;
			}
			if (isSimilar(strs[i], strs[j])) {
				f[fi] = fj;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < lens; i++) {
		if (i == f[i]) {
			res++;
		}
	}
	return res;
}