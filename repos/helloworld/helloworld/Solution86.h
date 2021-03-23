#pragma once
#include <iostream>

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution86
{
public:
	ListNode* partition(ListNode* head, int x);
};

