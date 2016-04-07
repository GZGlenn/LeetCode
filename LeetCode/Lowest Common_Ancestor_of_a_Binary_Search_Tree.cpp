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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (p == root || q == root) return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right) return root;
		return left ? left : right; 
	}
};

class Solution1 {
public:
	void getPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path, 
		vector<TreeNode *> &path1, vector<TreeNode*> &path2) {
		if (root == NULL) return;
		path.push_back(root);
		if (root == p) path1 = path;
		if (root == q) path2 = path;
		//找到两个节点后就可以退出了
		if (!path1.empty() && !path2.empty()) return;
		getPath(root->left, p, q, path, path1, path2);
		getPath(root->right, p, q, path, path1, path2);
		path.pop_back();
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path, path1, path2;
		getPath(root, p, q, path, path1, path2);
		TreeNode *res = root;
		int idx = 0;
		while (idx < path1.size() && idx < path2.size()) {
			if (path1[idx] != path2[idx]) break;
			else res = path1[idx++];
		}
		return res;
	}
};