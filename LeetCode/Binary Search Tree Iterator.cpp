#include <vector>
#include <stack>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root != nullptr) {
			this->s.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (this->s.empty()) return false;
		TreeNode* node = s.top();
		s.pop();
		currentMin = node->val;
		if (node->right) {
			node = node->right;
			while (node) {
				s.push(node);
				node = node->left;
			}
		}
		return true;
	}

	/** @return the next smallest number */
	int next() {
		return currentMin;
	}

private:
	stack<TreeNode*> s;
	int currentMin;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/