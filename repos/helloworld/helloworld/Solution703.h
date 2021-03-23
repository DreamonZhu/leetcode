#pragma once
#include <queue>

using namespace std;

class Solution703
{
public:
	Solution703(int k, int arr[], int length);
	//priority_queue<int, vector<int>, less<int> > q;
	priority_queue<int, vector<int>, greater<int> > q;
	int k;
	int value;
	void add(int v);
};

