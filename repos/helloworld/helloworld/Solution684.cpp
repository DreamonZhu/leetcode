#include "Solution684.h"

Solution684::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}
}

int Solution684::UnionFind::find(int x) {
	if (parent[x] != x) {
		int parentidx = parent[x];
		parent[x] = find(parentidx);
	}
	return parent[x];
}

void Solution684::UnionFind::Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return;
	}
	parent[rootx] = rooty;
}

vector<int> Solution684::findRedundantConnection(vector<vector<int>>& edges) {
	int lens = edges.size();
	vector<int> visited(lens + 1LL);
	UnionFind unionfind(lens + 1LL);
	for (auto& edge : edges) {
		if (!visited[edge[0]] || !visited[edge[1]]) {
			visited[edge[0]] = 1;
			visited[edge[1]] = 1;
		}
		else
		{
			if (unionfind.find(edge[0]) == unionfind.find(edge[1])) {
				return edge;
			}

		}
		unionfind.Union(edge[0], edge[1]);
	}
	return {};
}