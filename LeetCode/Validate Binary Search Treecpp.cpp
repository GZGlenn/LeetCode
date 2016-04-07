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
	bool isValidBST(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return true;

		vector<int> vecValue;
		InorderTree(root, vecValue);

		for (int i = 1; i < vecValue.size(); i++) {
			if (vecValue[i] <= vecValue[i - 1]) {
				return false;
			}
		}

		return true;
	}

	void InorderTree(TreeNode* node, vector<int> &vec) {
		if (node == NULL) return;
		InorderTree(node->left, vec);
		vec.push_back(node->val);
		InorderTree(node->right, vec);
	}
};


// faster
//public class Solution1 {
//	// Keep the previous value in inorder traversal.  
//	TreeNode pre = null;
//
//	public boolean isValidBST(TreeNode root) {
//		// Traverse the tree in inorder.  
//		if (root != null) {
//			// Inorder traversal: left first.  
//			if (!isValidBST(root.left)) return false;
//
//			// Compare it with the previous value in inorder traversal.  
//			if (pre != null && root.val <= pre.val) return false;
//
//			// Update the previous value.  
//			pre = root;
//
//			// Inorder traversal: right last.  
//			return isValidBST(root.right);
//		}
//		return true;
//	}
//}
