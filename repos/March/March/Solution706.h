#pragma once
#include <vector>

using namespace std;

class Solution706
{
private:
	static class Node {
	public:
		int key;
		int val;
		Node* next;
	public:
		Node():next(NULL) {}
		Node(int key, int val):key(key), val(val), next(NULL) {
		}
	};
	static const int base = 40000;
	Node* data;
public:
	Solution706();
	void put(int key, int value);
	int get(int key);
	void remove(int key);

};

