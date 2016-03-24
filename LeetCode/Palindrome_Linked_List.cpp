#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;

		// get len
		int len = getLen(head);

		// find half list head
		ListNode* backHalfHead = head;
		getBackHalfHead(backHalfHead, len);

		// reverse back half list
		reverseList(backHalfHead);

		// compare
		return isSameList(head, backHalfHead, len / 2);

	}

	int getLen(ListNode* head) {
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}
		return len;
	}

	void getBackHalfHead(ListNode* &backHalfHead, int len) {
		for (int i = 0; i < (len + 1) / 2; ++i) {
			cout << backHalfHead->val;
			backHalfHead = backHalfHead->next;
		}
	}

	void reverseList(ListNode* &backHalfHead) {
		if (backHalfHead->next == NULL) return;
		ListNode* preNode = backHalfHead;
		ListNode* curNode = backHalfHead->next;
		ListNode* nextNode = curNode->next;
		preNode->next = NULL;
		while (nextNode != NULL) {
			curNode->next = preNode;
			preNode = curNode;
			curNode = nextNode;
			nextNode = nextNode->next;
		}

		curNode->next = preNode;
		backHalfHead = curNode;
		return;
	}

	bool isSameList(ListNode* head, ListNode* backHalfHead, int len) {
		while (len > 0) {
			if (head == NULL || backHalfHead == NULL) return true;
			if (head->val != backHalfHead->val) return false;
			head = head->next;
			backHalfHead = backHalfHead->next;
			len--;
		}
		return true;
	}
};