#include "Solution509.h"

int Solution509::fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	vector<int> f(n + 1);
	f[0] = 0;
	f[1] = 1;
	int i = 1;
	while (i++ < n) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}