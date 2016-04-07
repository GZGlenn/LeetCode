#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* smallHead = new ListNode(0);
		ListNode* largeHead = new ListNode(0);

		ListNode* tempSmall = smallHead;
		ListNode* tempLarget = largeHead;
		ListNode* temp = head;
		while (head) {
			if (head->val < x) {
				tempSmall->next = head;
				tempSmall = tempSmall->next;
			}
			else {
				tempLarget->next = head;
				tempLarget = tempLarget->next;
			}
			head = head->next;
			temp->next = nullptr;
			temp = head;
		}

		tempSmall->next = largeHead->next;
		largeHead->next = nullptr;
		delete largeHead;

		ListNode* result = smallHead->next;
		smallHead->next = NULL;
		delete smallHead;

		return result;
	}
};
