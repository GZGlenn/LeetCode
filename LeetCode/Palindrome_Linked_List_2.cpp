#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode *lst;
public:
	ListNode* reverseHalf(ListNode* root){
		ListNode *fast = root, *slow = root;
		//slow 指向要反转的部分的后一个节点        
		while (fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode *h = new ListNode(0);
		h->next = root;
		//执行反转
		ListNode *sec = root, *fir = root->next;
		while (fir != slow){
			sec->next = fir->next;
			fir->next = h->next;
			h->next = fir;
			fir = sec->next;
		}
		return h->next;
	}

	bool isPalindrome(ListNode* head) {
		int len = 0;
		ListNode* p = head;
		ListNode *fast, *slow;
		//计算单链表的长度
		while (p != NULL){
			len++;
			p = p->next;
		}
		if (len < 2)
			return true;
		//反转单链表的前半部分            
		ListNode* reversedList = reverseHalf(head);
		//slow 指向单链表的中间位置
		fast = slow = reversedList;
		while (fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		//fast 指向单链表的头部
		fast = reversedList;
		if (len % 2 != 0)
			slow = slow->next;
		//判断是否为回文子串
		while (slow != nullptr){
			if (fast->val != slow->val)
				return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}
};