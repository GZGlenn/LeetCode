#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL) return vector<int>();
		vector<int> result = vector<int>();

		queue<TreeNode*> myQueue;
		myQueue.push(root);
		int len = 1;
		while (!myQueue.empty()) {
			result.push_back((myQueue.back())->val);
			while (len != 0) {
				TreeNode* temp = myQueue.front();
				myQueue.pop();
				if (temp->left) myQueue.push(temp->left);
				if (temp->right) myQueue.push(temp->right);
				len--;
			}
			len = myQueue.size();
		}

		return result;
	}
};