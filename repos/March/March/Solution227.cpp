#include "Solution227.h"
#include <stack>

int Solution227::calculate(string s) {
	stack<int> ops;
	ops.push(1);
	stack<int> nums;
	int n = s.length();
	int i = 0;
	while (i < n) {
		if (s[i] == ' ') {
			i++;
		} else if (s[i] == '+') {
			ops.push(1);
			i++;
		}
		else if (s[i] == '-') {
			ops.push(-1);
			i++;
		} else if (s[i] == '*') {
			long num = 0;
			while (!isdigit(s[i])) {
				i++;
			}
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				i++;
			}
			int num1 = nums.top();
			nums.pop();
			nums.push(num1 * num);
		} else if (s[i] == '/') {
			long num = 0;
			while (!isdigit(s[i])) {
				i++;
			}
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				i++;
			}
			int num1 = nums.top();
			nums.pop();
			nums.push(num1 / num);
		} else {
			long num = 0;
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				i++;
			}
			nums.push(num);
		}
	}
	int ret = 0;
	while (!ops.empty()) {
		ret += ops.top() * nums.top();
		ops.pop();
		nums.pop();
	}
	return ret;
}