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
		//slow ָ��Ҫ��ת�Ĳ��ֵĺ�һ���ڵ�        
		while (fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode *h = new ListNode(0);
		h->next = root;
		//ִ�з�ת
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
		//���㵥����ĳ���
		while (p != NULL){
			len++;
			p = p->next;
		}
		if (len < 2)
			return true;
		//��ת�������ǰ�벿��            
		ListNode* reversedList = reverseHalf(head);
		//slow ָ��������м�λ��
		fast = slow = reversedList;
		while (fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		//fast ָ�������ͷ��
		fast = reversedList;
		if (len % 2 != 0)
			slow = slow->next;
		//�ж��Ƿ�Ϊ�����Ӵ�
		while (slow != nullptr){
			if (fast->val != slow->val)
				return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}
};