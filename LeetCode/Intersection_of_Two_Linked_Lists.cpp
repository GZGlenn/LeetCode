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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		if (headA == NULL || headB == NULL) return NULL;

		int lenA = getLen(headA);
		int lenB = getLen(headB);

		ListNode *first, *second;
		if (lenA > lenB) {
			first = headA; second = headB;
		}
		else {
			first = headB; second = headA;
		}

		int diff = abs(lenA - lenB);
		for (int i = 0; i < diff; i++) {
			first = first->next;
		}

		while (first != second && first != NULL && second != NULL) {
			first = first->next;
			second = second->next;
		}

		if (first == NULL || second == NULL) return NULL;
		else return first;
	}

	int getLen(ListNode* head) {
		int len = 0;
		while (head != NULL) {
			len++;
			head = head->next;
		}
		return len;
	}
};