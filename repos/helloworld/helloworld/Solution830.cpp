#include "Solution830.h"

vector<vector<int>> Solution830::largeGroupPositions(string s) {
	if (s.length() < 3) {
		return {};
	}
	int lens = s.length();
	int cur = 0;
	vector<vector<int>> res;
	for (int i = 1; i < lens; i++) {
		if (i - cur >= 2 && s[i] == s[cur]) {
			if (i == lens - 1) {
				res.push_back({ cur, i });
			}

			if (i + 1 < lens && s[i + 1] != s[cur]) {
				res.push_back({ cur, i });
			}
		}
		if (s[i] != s[cur]) {
			cur = i;
		}
	}
	return res;
}