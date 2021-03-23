#include "monotonicQueue.h"

void monotonicQueue::push(int n) {
	while (!deq.empty() && deq.back() < n) {
		deq.pop_back();
	}
	deq.push_back(n);
}

int monotonicQueue::max() {
	return deq.front();
}

void monotonicQueue::pop(int n) {
	if (!deq.empty() && deq.front() == n) {
		deq.pop_front();
	}
}
