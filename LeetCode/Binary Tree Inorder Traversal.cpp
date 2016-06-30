#include<vector>
#include<stack>

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
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return vector<int>();

		vector<int> result;

		stack<TreeNode*> my_stack;

		TreeNode *p = root;

		do
		{
			while (p != NULL)
			{
				my_stack.push(p);
				p = p->left;
			}

			if (!my_stack.empty())
			{
				p = my_stack.top();
				my_stack.pop();

				result.push_back(p->val);

				p = p->right;
			}
		} while (!my_stack.empty() || p != NULL);

		return result;
	}
};
