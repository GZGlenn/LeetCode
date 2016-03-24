#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return head;
		if (head->next == NULL && head->val == val) return NULL;
		
		ListNode *preNode = head;
		while (head != NULL && head->val == val) {
			head = head->next;
			delete preNode;
			preNode = head;
		}
		if (head == NULL || head->next == NULL) return head;

		ListNode *nextNode = head->next;
		while (nextNode != NULL) {
			if (nextNode->val == val) {
				preNode->next = nextNode->next;
				delete nextNode;
				nextNode = preNode->next;
			}
			else {
				preNode = nextNode;
				nextNode = nextNode->next;
			}
		}

		return head;
	}
};