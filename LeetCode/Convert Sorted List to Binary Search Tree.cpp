#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;

		int len = 0;
		vector<TreeNode*> vecTree;

		ListNode* node = head;
		while (node != NULL) {
			vecTree.push_back(new TreeNode(node->val));
			node = node->next;
			len++;
		}

		return makeTree(vecTree, 0, len - 1);
	}

	TreeNode* makeTree(vector<TreeNode*> &vecTree, int start, int end) {
		if (start > end) return NULL;

		if (start == end) {
			return vecTree[start];
		}
		if (start == end - 1) {
			vecTree[start]->right = vecTree[end];
			return vecTree[start];
		}

		int root_ind = start + (end - start) / 2;
		TreeNode* root = vecTree[root_ind];
		root->left = makeTree(vecTree, start, root_ind-1);
		root->right = makeTree(vecTree, root_ind+1, end);
	}
};