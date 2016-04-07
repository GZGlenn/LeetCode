#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* temp = head;
		int len = 0;
		while (temp != NULL) {
			temp = temp->next;
			len++;
		}

		k = k % len;

		ListNode *pre = head, *pos = head;
		for (int i = 0; i < k; i++) {
			pos = pos->next;
		}

		if (pos == NULL) return head;

		while (pos->next != nullptr) {
			pre = pre->next;
			pos = pos->next;
		}

		pos->next = head;
		ListNode* result = pre->next;
		pre->next = NULL;
		return result;
	}
};