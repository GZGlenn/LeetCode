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
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		return mergeSort(head);
	}

	ListNode* mergeSort(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode *pre, *next, *before;
		pre = head; next = head;
		while (next&&next->next) {
			next = next->next->next;
			before = pre;
			pre = pre->next;
		}

		before->next = nullptr;
		ListNode* lhead = mergeSort(head);
		ListNode* rhead = mergeSort(pre);
		return mySort(lhead, rhead);
	}

	ListNode* mySort(ListNode* lhead, ListNode* rhead) {
		ListNode* temp = new ListNode(0);
		ListNode* p = temp;
		while (lhead&&rhead) {
			if (lhead->val > rhead->val) {
				p->next = rhead;
				rhead = rhead->next;
			}

			else {
				p->next = lhead;
				lhead = lhead->next;
			}
			p = p->next;
		}

		if (lhead) p->next = lhead;
		else if (rhead) p->next = rhead;

		p = temp->next;
		temp->next = nullptr;
		delete temp;
		return p;
	}
};
