#include <iostream>
#include "Solution703.h"

using namespace std;

Solution703::Solution703(int k, int arr[], int length) {
	this->k = k;
	//int length = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; i++) {
		add(arr[i]);
	}
}

void Solution703::add(int v) {
	if (q.size() < k) {
		q.push(v);
	}
	else if (q.top() < v) {
		q.pop();
		q.push(v);
	}
	value = q.top();
}
