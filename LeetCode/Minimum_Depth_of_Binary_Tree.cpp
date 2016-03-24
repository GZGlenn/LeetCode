#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int minDepth(TreeNode* root) {
		int min = 0;
		getMinDepth(root, 0, min);
		return min;
	}

	void getMinDepth(TreeNode* node, int curDepth, int &minLen) {
		if (node == NULL) return;
		if (isLeaf(node)) {
			if (minLen == 0) minLen = curDepth + 1;
			else minLen = min(minLen, curDepth + 1);
			return;
		}

		if (node->left) getMinDepth(node->left, curDepth + 1, minLen);
		if (node->right) getMinDepth(node->right, curDepth + 1, minLen);
		return;
	}

	bool isLeaf(TreeNode* node) {
		return (!node->left) && (!node->right);
	}
};