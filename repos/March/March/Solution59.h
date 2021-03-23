#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Solution59
{
public:
	vector<vector<int>> generateMatrix(int n);
	void circle(int left, int right, int top, int bottom, vector<vector<int>>& mat, int start);
};

