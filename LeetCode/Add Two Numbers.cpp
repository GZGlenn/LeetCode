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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		string sum = "";
		
		ListNode* l1_node = l1, *l2_node = l2;
		bool isCarry = false;
		while (l1_node && l2_node) {
			int temp = l1_node->val + l2_node->val;
			if (isCarry) temp++;
			
			if (temp / 10 != 0) isCarry = true;
			else isCarry = false;

			sum += to_string(temp % 10);

			l1_node = l1_node->next;
			l2_node = l2_node->next;
		}

		ListNode* temp_node = l1_node ? l1_node : l2_node;
		while (temp_node) {
			int temp = temp_node->val;
			if (isCarry) temp++;
			
			if (temp / 10 != 0) isCarry = true;
			else isCarry = false;

			sum += to_string(temp % 10);

			temp_node = temp_node->next;
		}

		if (isCarry) sum += "1";
	
		ListNode* result = new ListNode(sum[0] - '0');
		ListNode* curr = result;
		for (int i = 1; i < sum.length(); i++) {
			ListNode* temp = new ListNode(sum[i] - '0');
			curr->next = temp;
			curr = temp;
		}
		return result;
	}
};

// Ò»ÂÖÑ­»·
class Solution1 {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry = 0;
		ListNode* tail = new ListNode(0);
		ListNode* ptr = tail;

		while (l1 != NULL || l2 != NULL){
			int val1 = 0;
			if (l1 != NULL){
				val1 = l1->val;
				l1 = l1->next;
			}

			int val2 = 0;
			if (l2 != NULL){
				val2 = l2->val;
				l2 = l2->next;
			}

			int tmp = val1 + val2 + carry;
			ptr->next = new ListNode(tmp % 10);
			carry = tmp / 10;
			ptr = ptr->next;
		}

		if (carry == 1){
			ptr->next = new ListNode(1);
		}
		return tail->next;
	}
};