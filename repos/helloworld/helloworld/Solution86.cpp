#include "Solution86.h"

ListNode* Solution86::partition(ListNode* head, int x) {
	//上来判空可以显著提高运行效率
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* less = new ListNode(0);
	ListNode* less_head = less;
	ListNode* more = new ListNode(0);
	ListNode* more_head = more;
	while (head != nullptr) {
		if (head->val < x) {
			less->next = new ListNode(head->val);
			less = less->next;
		}
		else {
			more->next = new ListNode(head->val);
			more = more->next;
		}
		head = head->next;
	}
	less->next = more_head->next;
	return less_head->next;
}