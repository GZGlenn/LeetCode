#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;

		int diff = GetDiff(root);
		if (diff == -1) return false;  /*-1 denotes unbalance*/
		return true;
	}
	int GetDiff(TreeNode* node){
		if (node == NULL) return 0;

		int left = GetDiff(node->left);
		if (left == -1) return -1;
		int right = GetDiff(node->right);
		if (right == -1) return -1;

		if (left - right>1 || right - left>1)  return -1;
		return left>right ? left + 1 : right + 1;
	}
};