#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result = vector<string>();
		if (root == NULL) return result;
		string str = "";
		getPath(root, str, result);
		return result;
	}

	void getPath(TreeNode* root, string str, vector<string> &result) {
		if (root == NULL) return;

		if (str == "") str = int2string(root->val);
		else str += "->" + int2string(root->val);

		if (isLeaf(root)) {
			result.push_back(str);
			return;
		}

		if (root->left) getPath(root->left, str, result);
		if (root->right) getPath(root->right, str, result);
		return;
	}

	string int2string(int data) {
		char* p;
		sprintf(p, "%d", data);
		string s = p;
		return s;
	}

	bool isLeaf(TreeNode* node) {
		return (!node->left) && (!node->right);
	}
};