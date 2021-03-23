#include "Solution1202.h"
#include <unordered_map>
#include <queue>

Solution1202::UnionFind::UnionFind(int n) {
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}
}

void Solution1202::UnionFind::Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) {
		return;
	}
	parent[rootx] = rooty;
}

int Solution1202::UnionFind::find(int x) {
	if (parent[x] != x) {
		int parentidx = parent[x];
		parent[x] = find(parentidx);
	}
	return parent[x];
}

string Solution1202::smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	if (s.size() == 0) {
		return s;
	}
	
	int lens_vec = pairs.size();
	int lens_s = s.size();
	UnionFind unionfind(lens_s);
	for (int i = 0; i < lens_vec; i++) {
		unionfind.Union(pairs[i][0], pairs[i][1]);
	}
	unordered_map<int, priority_queue<char, vector<char>, greater<int>>> hashmap;

 	for (int i = 0; i < lens_s; i++) {
		int key = unionfind.find(i);
		if (hashmap.count(key)) {
			hashmap.at(key).emplace(s[i]);
		}
		else {
			priority_queue<char, vector<char>, greater<int>> q;
			q.emplace(s[i]);
			hashmap.emplace(unionfind.find(i), q);
		}
	}

	string s1;
	for (int i = 0; i < lens_s; i++) {
		s1.push_back(hashmap.at(unionfind.find(i)).top());
		hashmap.at(unionfind.find(i)).pop();
	}

	return s1;
}