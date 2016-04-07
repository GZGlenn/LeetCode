#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode *temp = dummyHead, *pre = head, *pos = head->next;
		bool isNeedDelPre = false;
		while (pos) {
			if (pre->val == pos->val) {
				isNeedDelPre = true;
				pre->next = pos->next;
				pos = pre->next;
			}
			else if (isNeedDelPre) {
				temp->next = pos;
				pre = pos;
				pos = pos->next;
				isNeedDelPre = false;
			}
			else {
				temp = pre;
				pre = pos;
				pos = pos->next;
			}
		}

		if (isNeedDelPre) {
			temp->next = pre->next;
		}

		return dummyHead->next;
	}
};

// faster
ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode *p = new ListNode(-1);
	p->next = head;
	ListNode *cur = p, *pre = head;
	while (pre != NULL){
		bool isDupli = false;
		while (pre->next != NULL && pre->val == pre->next->val){
			isDupli = true;
			pre = pre->next;
		}
		if (isDupli){
			pre = pre->next;
			continue;

		}
		cur->next = pre;
		cur = cur->next;
		pre = pre->next;

	}
	cur->next = pre;
	return p->next;
}