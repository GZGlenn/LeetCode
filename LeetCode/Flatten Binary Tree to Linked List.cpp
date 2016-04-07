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
	void flatten(TreeNode *root) {
		if (root == NULL) return;
		TreeNode *cur = root, *pre = NULL;
		while (cur != NULL) {
			if (cur->left != NULL) {
				pre = cur->left;
				while (pre->right) pre = pre->right;
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
	}
};