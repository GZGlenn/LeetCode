#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>

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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL) return vector<vector<int>>(0);

		vector<vector<int>> result;

		dfs(root, sum, result, vector<int>());

		return result;
	}

	void dfs(TreeNode* node, int sum, vector<vector<int>> &result,
		vector<int> temp) {
		if (node == NULL) {
			if (sum == 0) result.push_back(temp);
			return;
		}

		sum -= node->val;
		if (node->left == NULL && node->right == NULL) {
			if (sum == 0) {
				temp.push_back(node->val);
				result.push_back(temp);
				return;
			}
		}

		temp.push_back(node->val);

		if (node->left) dfs(node->left, sum, result, temp);

		if (node->right) dfs(node->right, sum, result, temp);
	}
};