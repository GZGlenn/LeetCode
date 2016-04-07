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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;

		ListNode *pre = head, *pos = head;
		while (pos && pos->next) {
			pre = pre->next;
			pos = pos->next->next;
			if (pre == pos) return true;
		}

		return false;
	}
};