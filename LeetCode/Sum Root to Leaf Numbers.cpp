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
	int sumNumbers(TreeNode* root) {
		if (root == NULL) return NULL;

		int sum = 0;
		dfs(root, root->val, sum);
		return sum;
	}

	void dfs(TreeNode* node, int pathNum, int &sum) {
		if (node->left == NULL && node->right == NULL) sum += pathNum;
		if (node->left) dfs(node->left, 10 * pathNum + node->left->val, sum);
		if (node->right) dfs(node->right, 10 * pathNum + node->right->val, sum);
	}
};

// faster
class Solution1 {
public:

	void dfs(TreeNode* root, int cur, int &res){
		if (root->left == NULL && root->right == NULL){
			cur = cur * 10 + root->val;
			res += cur;
		}
		else{
			cur = cur * 10 + root->val;
			if (root->left){
				dfs(root->left, cur, res);
			}
			if (root->right){
				dfs(root->right, cur, res);
			}
		}
	}
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		int res = 0;
		if (!root){ return res; }
		dfs(root, 0, res);
		return res;
	}
};