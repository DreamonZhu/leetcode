#include "Solution547_BFS.h"
#include <queue>

int Solution547_BFS::findCircleNum(vector<vector<int>> isConnected) {
	if (isConnected.size() == 0) {
		return 0;
	}

	int lens = isConnected.size();
	int circle = 0;
	vector<bool> visited(lens);
	queue<int> q;
	for (int i = 0; i < lens; i++) {
		if (!visited[i]) {
			q.push(i);
			while (!q.empty()) {
				int j = q.front();
				visited[j] = true;
				q.pop();
				for (int k = 0; k < lens; k++) {
					if (isConnected[j][k] == 1 && !visited[k]) {
						q.push(k);
					}
				}
			}
			circle++;
		}	
	}
	return circle;
}