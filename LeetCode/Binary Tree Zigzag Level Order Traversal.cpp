#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) return vector<vector<int>>();

		vector<vector<int>> result = vector<vector<int>>();

		queue<TreeNode*> q;

		q.push(root);

		int len = 1, level = 0;

		while (!q.empty()) {
			level++;
			vector<int> temp;
			while (len > 0) {
				TreeNode* node = q.front();
				q.pop(); len--;
				temp.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			if (level % 2 == 0) reverse(temp.begin(), temp.end());

			result.push_back(temp);

			len = q.size();
		}

		return result;
	}
};