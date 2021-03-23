#include "Solution547_UnionFind.h"

Solution547_UnionFind::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
		weight.push_back(1.0);
	}
}

void Solution547_UnionFind::UnionFind::Union(int a, int b, double value) {
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) {
		return;
	}
	parent[roota] = rootb;
	weight[roota] = value * weight[b] / weight[a];
}

int Solution547_UnionFind::UnionFind::find(int x) {
	if (parent[x] != x) {
		int parentidx = parent[x];
		parent[x] = find(parentidx);
		weight[x] *= weight[parentidx];
	}
	return parent[x];
}


int Solution547_UnionFind::findCircleNum(vector<vector<int>> isConnected) {
	int lens = isConnected.size();
	Solution547_UnionFind::UnionFind unionfind(lens);
	int circle = lens;
	for (int i = 0; i < lens; i++) {
		for (int j = i + 1; j < lens; j++) {
			if (isConnected[i][j] == 1) {
				unionfind.Union(i, j, 1.0);
			}
		}
	}

	for (int i = 0; i < lens; i++) {
		if (unionfind.parent[i] != i) {
			circle--;
		}
	}
	return circle;
}