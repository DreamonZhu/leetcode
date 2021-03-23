#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution132
{
private:
    vector<vector<int>> f;
    int n;
    int nums;
    int dfs(string s, int i, int lens);
public:
	int minCut(string s);
};

