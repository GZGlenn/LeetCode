#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* resultHead = head->next;

		ListNode* firstNode = head;
		ListNode* secondNode = head->next;
		ListNode* temp;
		while (true) {
			temp = firstNode;
			firstNode->next = secondNode->next;
			secondNode->next = firstNode;
			firstNode = firstNode->next;
			if (firstNode == NULL) break;
			secondNode = firstNode->next;
			if (secondNode == NULL) break;
			temp->next = secondNode;
		}

		return resultHead;
	}
};