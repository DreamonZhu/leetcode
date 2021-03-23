// helloworld.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>

#include "Solution20.h"
#include "Solution703.h"
#include "solution239.h"
#include "Solution239_1.h"
#include "Solution15.h"
#include "Solution1046.h"
#include "Solution435.h"
#include "Solution605.h"
#include "Solution86.h"
#include "Solution509.h"
#include "Solution830.h"
#include "Solution399.h"
#include "Solution547.h"
#include "Solution547_BFS.h"
#include "Solution547_UnionFind.h"
#include "Solution189.h"
#include "Solution123.h"
#include "Solution228.h"
#include "Solution1202.h"
#include "Solution1203.h"
#include "Solution684.h"
#include "Solution1018.h"
#include "Solution947.h"
#include "Solution721.h"
#include "Solution1489.h"
#include "Solution989.h"
#include "Solution1319.h"
#include "Solution5663.h"
#include "Solution1579.h"
#include "Solution778.h"
#include "Solution992.h"
#include "Solution992_double_pionters.h"
#include "Solution765.h"
#include "Solution566.h"
#include "Solution1004.h"
#include "Solution1052.h"
#include "Solution395.h"
#include "Solution338.h"
#include "Solution354.h"

#include <list>
#include <algorithm>

using namespace std;

int test(int arr[]) {
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	cout << "数组的长度是: " << sizeof(arr) << endl;
	// 此处的arr是指针变量，而测试环境是64位系统，于是sizeof(arr) = 8;
	return sizeof(arr) / sizeof(arr[0]);
}

void test1() {
	priority_queue<int> a;  //大头队列
	priority_queue<int, vector<int>, less<int> > b;  // 大头队列
	priority_queue<int, vector<int>, greater<int> > c;  // 小头队列
	for (int i = 2; i < 7; i++) {
		a.push(i);
		b.push(i);
		c.push(i);
	}
	a.push(1);
	b.push(1);
	c.push(1);
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;
	while (!b.empty()) {
		cout << b.top() << " ";
		b.pop();
	}
	cout << endl;
	while (!c.empty()) {
		cout << c.top() << " ";
		c.pop();
	}
	cout << endl;
}

void test2() {
	// 测试 list 和 vector
	vector<int> v;
	list<int> l;
	for (int i = 1; i < 8; i++) {
		v.push_back(i);
		v.push_back(i - 8);
		l.push_front(i);
	}

	//cout << v.begin() << endl;
	/*cout << *(v.begin()) << endl;
	cout << *(v.end()-1) << endl;
	cout << (v.begin() < v.end()) << endl;*/
	//cout << (l.begin() < l.end()) << endl;

	//sort(l.begin(), l.end());
	sort(v.begin(), v.end());
	for (vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << endl;
	}
}

void test3() {
	char a, b;
	a = 'a';
	b = 'b';
	cout << (a < b) << endl;
}

int main()
{
	//std::cout << "Hello World!\n";

	/*Solution20 *sol = new Solution20();
	cout << sol->isValid("[]") << endl;
	cout << sol->isValid("()[]{}") << endl;
	cout << sol->isValid("[]") << endl;
	cout << sol->isValid("[]") << endl;*/

	//test1();

	/*int arr[] = { 3, 4, 5, 20, 1, 6, 7, 8, 9, 10, 11, 12 };
	int length = sizeof(arr) / sizeof(arr[0]);
	cout << length << endl;
	cout << test(arr) << endl;
	Solution703* sol2 = new Solution703(10, arr, length);
	cout << sol2->value << endl; */

	/*vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	solution239 *sol = new solution239();
	vector<int> res = sol->maxSlidingWindow(nums, 3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;*/

	//test2();

	//Solution15 sol;
	////vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	//vector<int> nums = { 0, 0, 0 };
	//vector<vector<int>> res = sol.threeSum(nums);
	//for (int i = 0; i < res.size(); i++) {
	//	for (auto &j : res[i]) {
	//		cout << j << endl;
	//	}

	//}

	/*Solution1046 sol;
	vector<int> nums = { 2,7,4,1,8,1 };
	cout << sol.lastStoneWeight(nums) << endl;*/

	/*Solution435 sol;
	vector<vector<int>> inputs = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
	cout << sol.eraseOverlapIntervals(inputs) << endl;*/

	//Solution605 sol;
	////vector<int> nums = { 1, 0, 0, 0, 1 };
	////vector<int> nums = { 1, 0, 1, 0, 1 };
	////vector<int> nums = { 0, 0, 1, 0, 1 };
	////vector<int> nums = { 1, 0, 0, 0, 0, 1 };
	////vector<int> nums = { 0 };
	//vector<int> nums = { 0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0 };
	////cout << sol.canPlaceFlowers(nums, 0) << endl;
	//cout << sol.canPlaceFlowers(nums, 127) << endl;

	/*vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	Solution239_1 *sol = new Solution239_1();
	vector<int> res = sol->maxSlidingWindow(nums, 3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;*/

	/*ListNode* head = new ListNode(0);
	ListNode* head_1;
	head_1 = head;
	vector<int> arr = { 1, 4, 3, 2, 5, 2 };
	for (int i = 0; i < arr.size(); i++) {
		head->next = new ListNode(arr[i]);
		head = head->next;
	}

	Solution86 sol;
	ListNode *res = sol.partition(head_1->next, 3);
	while (res != nullptr) {
		cout << res->val << "->";
		res = res->next;
	}
	cout << endl;*/

	/*Solution509 sol;
	cout << sol.fib(2) << endl;
	cout << sol.fib(3) << endl;
	cout << sol.fib(4) << endl;*/

	/*Solution830 sol;
	string s = "abbxxxxzzy";
	string s = "abbxxxxzzy";
	string s = "abcdddeeeeaabbbcd";
	string s = "aba";
	string s = "aaa";
	vector<vector<int>> res = sol.largeGroupPositions(s);
	for (int i = 0; i < res.size(); i++) {
		cout << "[" << res[i][0] << ", " << res[i][1] << "]" << endl;
	}*/

	//Solution399 sol;
	/*输入：
		equations = [["a", "b"], ["b", "c"]],
		values = [2.0, 3.0],
		queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
	输出：[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]

	输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
	输出：[3.75000,0.40000,5.00000,0.20000]

	*/
	/*vector<vector<string>> equations = { {"a", "b"}, {"b", "c"} };
	vector<double> values = { 2.0, 3.0 };
	vector<vector<string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
	vector<double> res = sol.calcEquation(equations, values, queries);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}*/

	/*vector<vector<int>> isConnected = { {1,1,0},{1,1,0},{0,0,1} };
	Solution547 sol;
	cout << sol.findCircleNum(isConnected) << endl;
	Solution547_BFS sol_BFS;
	cout << sol_BFS.findCircleNum(isConnected) << endl;
	Solution547_UnionFind sol_unionfind;
	cout << sol_unionfind.findCircleNum(isConnected) << endl;*/

	//Solution189 sol;
	/*
	**	输入: [1,2,3,4,5,6,7] 和 k = 3
		输出: [5,6,7,1,2,3,4]
	*/
	/*vector<int> nums = { 1,2,3,4,5,6,7 };
	sol.rotate(nums, 3);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;*/

	/*Solution123 sol;
	vector<int> prices = { 3,3,5,0,0,3,1,4 };
	cout<< sol.maxProfit(prices) <<endl;*/

	//Solution228 sol;
	////vector<int> nums = { 0,1,2,4,5,7 };
	////vector<int> nums = { 0,2,3,4,6,8,9 };
	////vector<int> nums = {};
	//vector<int> nums = { -1 };
	////vector<int> nums = { 0 };
	//vector<string> res = sol.summaryRanges(nums);
	//for (int i = 0; i < res.size(); i++) {
	//	cout << res[i] << endl;
	//}

	//test3();
	//Solution1202 sol;
	//string s = "dcab";
	////vector<vector<int>> pairs = { {0,3}, {1,2} };
	//vector<vector<int>> pairs = { {0,3}, {1,2}, {0,2} };
	//string res = sol.smallestStringWithSwaps(s, pairs);
	//cout << res << endl;

	//Solution1203 sol;
	/*int m = 2;
	int n = 8;
	vector<int> group = { -1,-1,1,0,0,1,0,-1 };
	vector<vector<int>> beforeItems = { {} ,{6},{5},{6},{3,6},{},{},{} };
	vector <vector<int>> beforeItems = { {} ,{6},{5},{6},{3},{},{4},{} };*/

	/*int m = 5;
	int n = 5;
	vector<int> group = { 2,0,-1,3,0 };
	vector<vector<int>> beforeItems = { {2,1,3},{2,4},{},{},{} };

	vector<int> res = sol.sortItems(n, m, group, beforeItems);
	cout << "[ " ;
	for (auto& item : res) {
		cout << item << " " ;
	}
	cout << "]" << endl;;*/

	//Solution684 sol;
	//vector<vector<int>> edges = { {1,2} ,{1,3},{2,3} };
	//[1, 2] , [2, 3], [3, 4], [1, 4], [1, 5]
	//[[3, 4], [1, 2], [2, 4], [3, 5], [2, 5]]
	//vector<vector<int>> edges = { {1,2} ,{2,3},{3,4},{1,4},{1,5} };
	/*vector<vector<int>> edges = { {3,4},{1,2},{2,4},{3,5},{2,5} };
	vector<int> res = sol.findRedundantConnection(edges);
	cout << "[" << res[0] << ", " << res[1] << "]" << endl;*/

	//Solution1018 sol;
	////vector<int> A = { 0,1,1 };
	////vector<int> A = { 1,1,1 };
	////vector<int> A = { 0,1,1,1,1,1 };
	////vector<int> A = { 1,1,1,0,1 };
	//vector<int> A = { 1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0 };
	//vector<bool> res = sol.prefixesDivBy5(A);
	//cout << "[";
	//for (int i = 0; i < res.size(); i++) {
	//	cout << res[i] << " ";
	//}
	//cout << "]" << endl;

	//Solution947 sol;
	////vector<vector<int>> stones = { {0,0} ,{0,1},{1,0},{1,2},{2,1},{2,2} };
	////vector<vector<int>> stones = { {0,0} ,{0,2},{1,1},{2,0},{2,2} };
	//vector<vector<int>> stones = { {0, 0} };
	//cout << sol.removeStones(stones) << endl;

	/*Solution721 sol;
	vector<vector<string>> accounts = { {"John", "johnsmith@mail.com", "john00@mail.com"} ,{"John", "johnnybravo@mail.com"},{"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"Mary", "mary@mail.com" }
	};
	vector<vector<string>> res = sol.accountsMerge(accounts);
	for (int i = 0; i < res.size(); i++) {
		cout << "[";
		for (auto& item : res[i]) {
			cout << item << ", ";
		}
		cout << "]" << endl;
	}*/

	//Solution1489 sol;
	////vector<vector<int>> edges = { {0, 1, 1}, { 1, 2, 1 }, { 2, 3, 1 }, { 0, 3, 1 } };
	//vector<vector<int>> edges1 = { {0,1,1}, {1,2,1}, {2,3,2}, {0,3,2}, {0,4,3}, {3,4,3}, {1,4,6} };
	////vector<vector<int>> res = sol.findCriticalAndPseudoCriticalEdges(4, edges);
	//vector<vector<int>> res = sol.findCriticalAndPseudoCriticalEdges(5, edges1);
	//for (auto& item : res) {
	//	cout << "[";
	//	for (int i = 0; i < item.size(); i++) {
	//		cout << item[i] << " ";
	//	}
	//	cout << endl;
	//}

	//Solution989 sol;
	////vector<int> A = { 1, 2, 0, 0 };
	////vector<int> A = { 2, 1, 5 };
	//vector<int> A = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	////vector<int> res = sol.addToArrayForm(A, 34);
	////vector<int> res = sol.addToArrayForm(A, 806);
	//vector<int> res = sol.addToArrayForm1(A, 1);
	//cout << "[";
	//for (auto& item : res) {
	//	cout << item << " ";
	//}
	//cout << "]";

	//Solution1319 sol;
	////vector<vector<int>> connections = { {0, 1},{0, 2},{1, 2} };
	//vector<vector<int>> connections = { {0, 1},{0, 2},{0, 3},{1, 2},{1, 3} };

	//cout << sol.makeConnected(6, connections) << endl;

	/*Solution5663 sol;
	vector<vector<int>> matrix = { {5,2},{1,6} };
	cout << sol.kthLargestValue(matrix, 1) << endl;
	cout << sol.kthLargestValue(matrix, 2) << endl;
	cout << sol.kthLargestValue(matrix, 3) << endl;
	cout << sol.kthLargestValue(matrix, 4) << endl;*/

	//Solution1579 sol;
	////vector<vector<int>> edges = { {3, 1, 2},{3, 2, 3},{1, 1, 3},{1, 2, 4},{1, 1, 2},{2, 3, 4} };
	////vector<vector<int>> edges = { {3,1,2} ,{3,2,3},{1,1,4},{2,1,4} };
	//vector<vector<int>> edges = { {1, 1, 2} ,{2, 1, 2},{3, 1, 2}};
	//cout << sol.maxNumEdgesToRemove(4, edges) << endl;
	////cout << sol.maxNumEdgesToRemove(2, edges) << endl;

	/*Solution778 sol;
	vector<vector<int>> grid = { {0, 2},{1, 3} };
	cout << sol.swimInWater(grid) << endl;*/

	//Solution992 sol;
	////vector<int> A = { 1,2,1,2,3 };
	////vector<int> A = { 1,2,1,3,4 };
	////vector<int> A = { 1,2 };
	////vector<int> A = { 2,1,1,1,2 };
	//vector<int> A = { 2,1,2,1,2 };
	////cout << sol.subarraysWithKDistinct(A, 2) << endl;
	////cout << sol.subarraysWithKDistinct(A, 3) << endl;
	////cout << sol.subarraysWithKDistinct(A, 1) << endl;
	////cout << sol.subarraysWithKDistinct(A, 1) << endl;
	//cout << sol.subarraysWithKDistinct(A, 2) << endl;

	/*vector<int> A = { 2,1,2,1,2 };
	Solution992_double_pionters sol1;
	cout << sol1.subarraysWithKDistinct(A, 2) << endl;*/

	/*Solution765 sol;
	vector<int> row = { 0,2,1,3 };
	vector<int> row = { 3, 2, 0, 1 };
	cout << sol.minSwapsCouples(row) << endl;*/

	/*Solution566 sol;
	vector<vector<int>> nums = { {1,2} ,{3,4} };
	vector<vector<int>> res = sol.matrixReshape(nums, 1, 4);
	for (auto& items : res) {
		for (auto& item : items) {
			cout << item << ", ";
		}
		cout << endl;
	}*/

	/*Solution1004 sol;
	vector<int> A = { 1,1,1,0,0,0,1,1,1,1,0 };
	vector<int> A = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
	vector<int> A = { 0,0,0,1 };
	cout << sol.longestOnes(A, 2) << endl;*/

	/*Solution1052 sol;
	vector<int> customers = { 1,0,1,2,1,1,7,5 };
	vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
	cout << sol.maxSatisfied(customers, grumpy, 3) << endl;*/

	/*Solution395 sol;
	string s = "aaabb";
	cout << sol.longestSubstring(s, 3) << endl;
	s = "ababbc";
	cout << sol.longestSubstring(s, 2) << endl;*/

	/*Solution338 sol;
	vector<int> res = sol.countBits(5);
	for (auto& item : res) {
		cout << item << endl;
	}*/

	Solution354 sol;
	vector<vector<int>> nums = { {5, 4} ,{7, 5} ,{6, 7} ,{2, 3} };
	cout << sol.maxEnvelopes(nums) << endl;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
