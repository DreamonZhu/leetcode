#include "Solution395.h"
#include <vector>

int Solution395::dfs(string s, int left, int right, int k) {
	vector<int> cnt(26, 0);
	for (int i = left; i <= right; i++) {
		cnt[s[i] - 'a']++;
	}
	char split = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0 && cnt[i] < k) {
			split = i + 'a';
			break;
		}
	}
	if (split == 0) {
		return right - left + 1;
	}
	int i = left;
	int res = 0;
	while (i <= right) {
		while (i <= right && s[i] == split) {
			i++;
		}
		if (i > right) {
			break;
		}
		int start = i;
		while (i <= right && s[i] != split) {
			i++;
		}
		int length = dfs(s, start, i - 1, k);
		res = max(res, length);
	}
	return res;
}

int Solution395::longestSubstring(string s, int k) {
	if (k > s.size()) {
		return 0;
	}
	int lens = s.length();
	int res = dfs(s, 0, lens - 1, k);
	return res;
}