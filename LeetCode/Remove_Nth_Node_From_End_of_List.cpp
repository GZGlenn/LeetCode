#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n < 0 || head == NULL) return head;
		ListNode* pre = head;
		ListNode* next = head;

		for (int i = 0; i < n; i++) {
			next = next->next;
			if (next == NULL) break;
		}

		if (next == NULL) {
			head = head->next;
			delete pre;
			return head;
		}

		while (next->next != NULL) {
			pre = pre->next;
			next = next->next;
		}

		delete pre->next;
		pre->next = pre->next->next;
		return head;
	}
};