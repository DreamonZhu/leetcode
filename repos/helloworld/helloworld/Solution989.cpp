#include "Solution989.h"

vector<int> Solution989::addToArrayForm(vector<int>& A, int k) {
	int count = 0;
	int lens = A.size();
	int item = 1;
	reverse(A.begin(), A.end());
	for (int i = 0; i < lens; i++) {
		count += item * A[i];
		item *= 10;
	}
	item /= 10;
	count += k;
	vector<int> res;
	while (count / item) {
		res.push_back(count / item);
		count = count % item;
		item = item / 10;
		if (item == 0) {
			break;
		}
	}
	vector<int> res1;
	for (auto& item : res) {
		while(item > 9) {
			res1.push_back(item / 10);
			item %= 10;
		}
		res1.push_back(item);
	}
	return res1;
}

vector<int> Solution989::addToArrayForm1(vector<int>& A, int k) {
	int n = A.size();
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {
		int a = A[i] + k % 10;
		k /= 10;
		if (a > 9) {
			res.push_back(a % 10);
			a = a / 10;
			k++;
		}
		else {
			res.push_back(a);
		}
	}
	for (; k > 0; k = k / 10) {
		res.push_back(k % 10);
	}
	reverse(res.begin(), res.end());
	return res;
}