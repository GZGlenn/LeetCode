#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL) return 0;
		
		vector<TreeNode*> data;
		preorderTree(root, data);

		return data[k - 1]->val;
	}

	void preorderTree(TreeNode* root, vector<TreeNode*> &data) {
		if (root == NULL) return;
		if (root->left) preorderTree(root->left, data);
		data.push_back(root);
		if (root->right) preorderTree(root->right,data);
	}
};

class Solution1 {
public:
	int calcTreeSize(TreeNode* root){
		if (root == NULL)
			return 0;
		return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
	}
	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL)
			return 0;
		int leftSize = calcTreeSize(root->left);
		if (k == leftSize + 1){
			return root->val;
		}
		else if (leftSize >= k){
			return kthSmallest(root->left, k);
		}
		else{
			return kthSmallest(root->right, k - leftSize - 1);
		}
	}
};