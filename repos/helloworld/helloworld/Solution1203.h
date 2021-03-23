#pragma once
#include <vector>

using namespace std;

class Solution1203
{
public:
	vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems);
	vector<int> topSort(vector<vector<int>>& graph, vector<int>& deg, vector<int>& items);
};

