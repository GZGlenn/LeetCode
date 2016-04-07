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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return NULL;
		if (preorder.size() != inorder.size()) return NULL;

		return makeTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1);
	}

	TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder,
		int pre_start, int pre_end, int in_start, int in_end) {
		if (pre_end - pre_start != in_end - in_start || pre_end - pre_start < 0) {
			return NULL;
		}

		if (pre_end == pre_start) {
			return new TreeNode(preorder[pre_start]);
		}

		TreeNode* root = new TreeNode(preorder[pre_start]);
		int in_root = 0;
		while (inorder[in_root] != preorder[pre_start] && in_root <= in_end) in_root++;

		if (inorder[in_root] != preorder[pre_start]) return NULL;

		if (in_root > in_start) {
			int left_len = in_root - in_start;
			root->left = makeTree(preorder, inorder, pre_start+1, pre_start+left_len, 
				in_start, in_root-1);
		}

		if (in_root < in_end) {
			int right_len = in_end - in_root;
			root->right = makeTree(preorder, inorder, pre_end-right_len+1, pre_end,
				in_root+1, in_end);
		}

		return root;

	}
};