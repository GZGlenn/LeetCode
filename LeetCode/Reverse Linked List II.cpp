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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL) return head;
		if (m == n) return head;
		if (m > n) return NULL;

		ListNode *result = head;
		ListNode *pre1 = head, *pre2 = head->next;
		ListNode *pos1 = head, *pos2 = head->next;

		if (m == 1) {
			pre1 = new ListNode(0);
			pre2 = head;
			pre1->next = pre2;
			result = pre1;
		}

		int index = 2;
		while (pos2 && index <= n) {
			if (index < m) {
				if (!pre2) return NULL;
				pre1 = pre2;
				pre2 = pre2->next;
			}

			pos1 = pos2;
			pos2 = pos2->next;
			index++;
		}
		if (!pos1) return NULL;

		// reverseInside
		ListNode *temp1 = pre2, *temp2 = pre2->next;
		ListNode* temp3 = temp2->next;
		while (temp3 != pos1->next) {
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp3->next;
		}
		temp2->next = temp1;

		pre1->next = pos1;
		pre2->next = pos2;

		if (m == 1) {
			temp1 = result;
			result = result->next;

			temp1->next = NULL;
			delete temp1;
		}
		return result;
	}
};


// faster
class Solution1 {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		vector<ListNode*> range(n - m + 1);

		ListNode* iter = head;
		for (int i = 1; i < m; ++i)
			iter = iter->next;

		for (int i = m, j = 0; i <= n; ++i, ++j)
		{
			range[j] = iter;
			iter = iter->next;
		}

		for (size_t i = 0; i < range.size() / 2; ++i)
			swap(range[i]->val, range[range.size() - i - 1]->val);

		return head;
	}
};