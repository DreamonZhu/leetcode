#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution131
{
private:
    vector<vector<bool>> f;
    vector<vector<string>> res;
    vector<string> ans;
    void dfs(string s, int i, int n);
public:
	vector<vector<string>> partition(string s);
};

