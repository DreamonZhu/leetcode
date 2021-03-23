#pragma once
#include <string>

using namespace std;

class Solution395
{
private:
	int dfs(string s, int left, int right, int k);
public:
	int longestSubstring(string s, int k);
};

