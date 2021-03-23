#include "Solution20.h"
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool Solution20::isValid(string s) {
	if (s.size() % 2 != 0) {
		return false;
	}

	unordered_map<char, char> pairs = {
		{ ')', '(' },
		{ ']', '[' },
		{ '}', '{' }
	};

	stack<char> stk;
	for (char ch : s) {
		if (pairs.count(ch)) {
			if (stk.empty() || stk.top() != pairs[ch]) {
				return false;
			}
			stk.pop();
		}
		else {
			stk.push(ch);
		}
	}
	return stk.empty();
}


Solution20::Solution20()
{
}

Solution20::~Solution20()
{
}