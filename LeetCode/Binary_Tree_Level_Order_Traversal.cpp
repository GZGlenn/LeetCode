#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return vector<vector<int>>();

		vector<vector<int>> result = vector<vector<int>>();
		int oldLen = 0;
		queue<TreeNode*> myQueue = queue<TreeNode*>();
		myQueue.push(root); oldLen = 1;
		while (!myQueue.empty()) {
			oldLen = myQueue.size();
			vector<int> temp = vector<int>();
			while (oldLen > 0) {
				TreeNode* node = myQueue.front();
				myQueue.pop(); oldLen--;

				temp.push_back(node->val);
				if (node->left != NULL) myQueue.push(node->left);
				if (node->right != NULL) myQueue.push(node->right);
			}
			result.push_back(temp);
		}
		return result;
	}
};