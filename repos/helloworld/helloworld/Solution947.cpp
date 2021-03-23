#include "Solution947.h"
#include <algorithm>
#include <queue>

Solution947::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}
	count = n;
}

int Solution947::UnionFind::find(int x) {
	if (parent[x] != x) {
		int parentidx = parent[x];
		parent[x] = find(parentidx);
	}
	return parent[x];
}

void Solution947::UnionFind::Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return;
	}
	parent[rootx] = rooty; 
	count--;
}

int Solution947::UnionFind::getCount() {
	return count;
}


int Solution947::removeStones(vector<vector<int>>& stones) {
	if (stones.size() == 0 || stones.size() == 1)
		return 0;
	int lens = stones.size();
	UnionFind unionfind(lens);
	//vector<int> deg(lens, 0);
	for (int i = 0; i < lens; i++) {
		for (int j = lens - 1; j > i; j--) {
			if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
				unionfind.Union(i, j);
				/*deg[i]++;
				deg[j]++;*/
			}
		}
	}
	return lens - unionfind.getCount();
}