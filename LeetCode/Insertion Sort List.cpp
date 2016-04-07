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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) return nullptr;

		ListNode* result = new ListNode(head->val);
		ListNode* node = head->next;
		ListNode* old;
		while (node != nullptr) {
			old = node;
			node = node->next;
			insertSort(result, old);
		}
		return result;
	}

	void insertSort(ListNode* &result, ListNode* node) {
		if (result->val > node->val) {
			node->next = result;
			result = node;
			return;
		}

		ListNode* temp = result;
		while (temp->next) {
			if (temp->val <= node->val && temp->next->val > node->val) {
				node->next = temp->next;
				temp->next = node;
				return;
			} 
			temp = temp->next;
		}

		node->next = nullptr;
		temp->next = node;
	}
};