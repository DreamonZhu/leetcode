#pragma once
#include <vector>
#include <string>

using namespace std;


class Solution839
{
private:
	vector<int> f;
	
	void init(int n) {
		for (int i = 0; i < n; i++) {
			f.push_back(i);
		}
	}

	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	int isSimilar(string& str1, string& str2) {
		int nums = 0;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i]) {
				nums++;
			}
			if (nums > 2) {
				return 0;
			}
		}
		return 1;
	}

public:
	int numSimilarGroups(vector<string>& strs);
};

