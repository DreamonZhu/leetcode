#include "Solution1319.h"

Solution1319::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
		rank.push_back(1);
	}
	connected_count = n;
	rest = 0;
}

int Solution1319::UnionFind::find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int Solution1319::UnionFind::Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		rest++;
		return false;
	}
	if (rank[rootx] < rank[rooty]) {
		swap(rootx, rooty);
	}
	parent[rooty] = rootx;
	rank[rootx] += rank[rooty];
	connected_count--;
	return true;
}

int Solution1319::makeConnected(int n, vector<vector<int>>& connections) {
	if (connections.size() < n - 1) {
		return -1;
	}
	int lens = connections.size();
	UnionFind unionfind(n);
	for (auto& item : connections) {
		unionfind.Union(item[0], item[1]);
	}
	int nums = 0;
	for (int i = 0; i < n; i++) {
		if (unionfind.find(i) == i) {
			nums++;
		}
	}
	int res = lens - nums - (unionfind.connected_count - 1);
	if (res >= 0) {
		return unionfind.connected_count - 1;
	}
	else {
		return -1;
	}
}