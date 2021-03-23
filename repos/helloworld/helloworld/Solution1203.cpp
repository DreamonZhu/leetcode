#include "Solution1203.h"
#include <queue>

vector<int> Solution1203::topSort(vector<vector<int>>& graph, vector<int>& deg, vector<int>& items) {
	queue<int> q;
	for (auto& item : items) {
		if (deg[item] == 0) {
			q.push(item);
		}
	}
	vector<int> res;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		res.emplace_back(top);
		for (auto& item : graph[top]) {
			if (--deg[item] == 0) {
				q.push(item);
			}
		}
	}
	return res.size() == items.size() ? res : vector<int>{};
}

vector<int >Solution1203::sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
	vector<vector<int>> groupGraph(n + m);
	vector<int> groupdeg(n + m);
	vector<vector<int>> itemGraph(n);
	vector<int> itemdeg(n);

	vector<vector<int>> groupitem(n + m);

	vector<int> id;
	for (int i = 0; i < n + m; i++) {
		id.emplace_back(i);
	}

	int leftId = m;
	for (int i = 0; i < n; i++) {
		if (group[i] == -1) {
			group[i] = leftId;
			leftId++;
		}
		groupitem[group[i]].emplace_back(i);
	}

	for (int i = 0; i < n; i++) {
		int curGroupId = group[i];
		for (auto& beforeItem : beforeItems[i]) {
			int beforeGroupId = group[beforeItem];
			if (beforeGroupId == curGroupId) {
				itemGraph[beforeItem].emplace_back(i);
				itemdeg[i]++;
			}
			else
			{
				groupGraph[beforeGroupId].emplace_back(curGroupId);
				groupdeg[curGroupId]++;
			}
		}
	}

	vector<int> grouplists = topSort(groupGraph, groupdeg, id);
	if (grouplists.size() == 0) {
		return {};
	}

	vector<int> ans;
	for (auto& grouplist : grouplists) {
		if (groupitem[grouplist].size() == 0)
			continue;
		vector<int> itemlist = topSort(itemGraph, itemdeg, groupitem[grouplist]);
		if (itemlist.size() == 0) {
			return {};
		}
		for (auto& item : itemlist) {
			ans.emplace_back(item);
		}
	}
	return ans;
}
