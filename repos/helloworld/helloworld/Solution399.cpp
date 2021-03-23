#include "Solution399.h"
#include <map>

Solution399::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		//parent[i] = i;
		parent.push_back(i);
		//weight[i] = 1.0;
		weight.push_back(1.0);
	}
}

void Solution399::UnionFind::Union(int x, int y, double value) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return;
	}
	parent[rootx] = rooty;
	weight[rootx] = weight[y] * value / weight[x];
}

int Solution399::UnionFind::find(int x) {
	if (x != parent[x]) {
		int parentidx = parent[x];
		parent[x] = find(parentidx);
		weight[x] *= weight[parentidx];
	}

	return parent[x];
}

double Solution399::UnionFind::is_connected(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return weight[x] / weight[y];
	}
	else {
		return -1.0;
	}
}

vector<double> Solution399::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int lens_equas = equations.size();
	Solution399::UnionFind unionfind = Solution399::UnionFind(2 * lens_equas);
	map<string, int> hashmap;
	int id = 0;
	for (int i = 0; i < lens_equas; i++) {
		string var1 = equations[i][0];
		string var2 = equations[i][1];
		if (!hashmap.count(var1)) {
			hashmap.emplace(var1, id);
			id++;
		}

		if (!hashmap.count(var2)) {
			hashmap.emplace(var2, id);
			id++;
		}

		unionfind.Union(hashmap.at(var1), hashmap.at(var2), values[i]);
	}

	int lens_query = queries.size();
	vector<double> res;
	for (int i = 0; i < lens_query; i++) {
		string a = queries[i][0];
		string b = queries[i][1];
		if (!hashmap.count(a) || !hashmap.count(b)) {
			res.push_back(-1.0);
		}
		else {
			int ida = hashmap.at(a);
			int idb = hashmap.at(b);
			res.push_back(unionfind.is_connected(ida, idb));
		}
	}

	return res;
}