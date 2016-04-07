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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return NULL;

		vector<TreeNode*> vecTree;
		for (int i = 0; i < nums.size(); i++) {
			vecTree.push_back(new TreeNode(nums[i]));
		}

		return makeTree(vecTree, 0, nums.size() - 1);
	}

	TreeNode* makeTree(vector<TreeNode*> &vecTree, int start, int end) {
		if (start > end) return NULL;
		if (start == end) { return vecTree[start]; }
		if (start == end - 1) { vecTree[start]->right = vecTree[end]; return vecTree[start]; }
		
		int root_ind = start + (end - start) / 2;
		vecTree[root_ind]->left = makeTree(vecTree, start, root_ind - 1);
		vecTree[root_ind]->right = makeTree(vecTree, root_ind + 1, end);
		return vecTree[root_ind];
	}
};