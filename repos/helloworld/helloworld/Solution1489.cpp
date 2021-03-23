#include "Solution1489.h"
#include <algorithm>
#include <unordered_map>
#include <set>

Solution1489::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
		rank.push_back(1);
	}
}

int Solution1489::UnionFind::find(int x) {
	return x == parent[x] ? x : parent[x]=find(parent[x]);
}

int Solution1489::UnionFind::Union(int x, int y) {
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
}

vector<vector<int>> Solution1489::findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
	/*sort(edges.begin(), edges.end(), [](vector<vector<int>>& edges1, vector<vector<int>>& edges2) -> int {
		return edges1[3] < edges2[3];
		});*/
	int lens = edges.size();
	if (lens == n) {
		vector<int> pesudo_arc;
		for (int i = 0; i < n; i++) {
			pesudo_arc.push_back(i);
		}
		return { {}, pesudo_arc };
	}
	UnionFind unionfind(lens);
	int nums = 0;
	unordered_map<int, vector<int>> hashmap;
	vector<int> res;
	for (auto& item : edges) {
		if (unionfind.find(item[0]) != unionfind.find(item[1])) {
			unionfind.Union(item[0], item[1]);
			if (hashmap.count(item[0])) {
				hashmap.at(item[0]).push_back(nums);
			}
			else {
				hashmap.emplace(item[0], vector<int>{nums});
			}

			if (hashmap.count(item[1])) {
				hashmap.at(item[1]).push_back(nums);
			}
			else {
				hashmap.emplace(item[1], vector<int>{nums});
			}
		}
		else {
			res.push_back(item[1]);
			hashmap.at(item[0]).push_back(nums);
			hashmap.at(item[1]).push_back(nums);
		}
		nums++;
	}
	vector<int> critical_arc;
	vector<int> pesudo_arc;
	set<int> pesudo_arc1;
	for (auto& item : res) {
		pesudo_arc1.insert(hashmap.at(item).begin(), hashmap.at(item).end());
	}
	for (int i = 0; i < lens; i++) {
		if (pesudo_arc1.count(i)) {
			pesudo_arc.push_back(i);
		}
		else {
			critical_arc.push_back(i);
		}
	}
	return { critical_arc, pesudo_arc };
}