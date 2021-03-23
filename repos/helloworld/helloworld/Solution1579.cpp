#include "Solution1579.h"
#include <set>

Solution1579::UnionFind::UnionFind(int nums) {
	connected_nums = nums;
	for (int i = 0; i < nums + 1; i++) {
		parent.push_back(i);
		rank.push_back(1);
	}
}

int Solution1579::UnionFind::find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int Solution1579::UnionFind::Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return false;
	}
	if (rank[rootx] < rank[rooty]) {
		swap(rootx, rooty);
	}
	parent[rooty] = rootx;
	rank[rootx] += rank[rooty];
	connected_nums--;
	return true;
}

int Solution1579::UnionFind::get_connected_nums() {
	return connected_nums;
}

int Solution1579::maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
	UnionFind unionfind_a(n);
	UnionFind unionfind_b(n);
	int ans = 0;
	for (auto& item : edges) {
		if (item[0] == 3) {
			if (!unionfind_a.Union(item[1], item[2])) {
				ans++;
			}
			else {
				unionfind_b.Union(item[1], item[2]);
			}
		}
	}

	for (auto& item : edges) {
		if (item[0] == 2) {
			if (!unionfind_b.Union(item[1], item[2])) {
				ans++;
			}
		}

		if (item[0] == 1) {
			if (!unionfind_a.Union(item[1], item[2])) {
				ans++;
			}
		}
	}
	
	if (unionfind_a.get_connected_nums() != 1 || unionfind_b.get_connected_nums() != 1) {
		return -1;
	}
	return ans;
}