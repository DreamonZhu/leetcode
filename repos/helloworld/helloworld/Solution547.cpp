#include "Solution547.h"

void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int lens, int i) {
	for (int j = 0; j < lens; j++) {
		if (isConnected[i][j] == 1 && !visited[j]) {
			visited[j] = true;
			DFS(isConnected, visited, lens, j);
		}
	}
}

int Solution547::findCircleNum(vector<vector<int>> &isConnected) {
	// DFS
	if (isConnected.size() == 0)
		return 0;
	int lens = isConnected.size();
	// c++ �������Ҫȷ������ά��
	//bool visited[] = Bool(lens);
	//bool* visited = new bool(lens);
	//bool visited[lens] = { 0 };
	vector<bool> visited(lens);
	//visited = { 0 };  ����������ʹ�� visited ��� 1ά
	int provinces = 0;
	for (int i = 0; i < lens; i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(isConnected, visited, lens ,i);
			provinces++;
		}
	}
	return provinces;
}