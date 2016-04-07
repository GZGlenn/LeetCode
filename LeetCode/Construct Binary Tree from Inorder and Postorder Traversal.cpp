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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
			return NULL;

		return makeTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder,
		int in_start, int in_end, int pos_start, int pos_end) {
		if (in_start > in_end) return NULL;
		if (in_start == in_end) return new TreeNode(inorder[in_start]);

		TreeNode* root = new TreeNode(postorder[pos_end]);
		int in_root = in_start;
		while (in_root < in_end && inorder[in_root] != postorder[pos_end]) in_root++;

		if (in_root > in_start) {
			int left_len = in_root - in_start;
			root->left = makeTree(inorder, postorder, in_start, in_root-1, 
				pos_start, pos_start+left_len-1);
		}

		if (in_root < in_end) {
			int right_len = in_end - in_root;
			root->right = makeTree(inorder, postorder, in_root+1, in_end,
				pos_end-right_len, pos_end-1);
		}

		return root;
	}
};