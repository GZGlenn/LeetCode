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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return NULL;

		ListNode *pre = head, *pos = head;
		int cycleLen = 0;
		while (pos && pos->next) {
			pos = pos->next->next;
			pre = pre->next;
			cycleLen++;
			if (pos == pre) break;
		}

		if (!pos || !pos->next) return NULL;

		pos = head;
		while (cycleLen > 0) {
			pos = pos->next;
			cycleLen--;
		}

		pre = head;
		while (pre != pos) {
			pre = pre->next;
			pos = pos->next;
		}

		return pre;
	}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (fast == NULL || fast->next == NULL)
			return NULL;
		slow = head;
		while (slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};