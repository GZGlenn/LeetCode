#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// pre：当前节点（屋子）不偷盗时，所能获得的收益；
// 取决于在该节点的两个子节点被偷盗时的收益之和。
// curr：当前节点（屋子）偷盗时，所能获得的收益；
// 由于相邻节点不能同时偷盗否则会引来警察，所以两个子节点不能偷盗，
// 此时收益等于：父节点->val + 左子节点->pre + 右子节点->pre。
class Solution {
public:
	struct money{
		int pre;
		int curr;
		money() :pre(0), curr(0){ ; }
	};
	int rob(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return root->val;

		money mon = dfs(root);
		return max(mon.curr, mon.pre);
	}

	money dfs(TreeNode* node) {
		if (node == NULL) return money();
		money left = dfs(node->left);
		money right = dfs(node->right);

		money root;
		root.pre = left.curr + right.curr;
		root.curr = max(root.pre, node->val + left.pre + right.pre);
		return root;
	}
};

// 这题可以看做是简单的DP问题，用A[0]表示没有rob当前house的最大money，
// A[1]表示rob了当前house的最大money，那么A[0] 等于rob或者没有rob上一次house的最大值
// 即A[i + 1][0] = max(A[i][0], A[i][1])..那么rob当前的house，
// 只能等于上次没有rob的 + money[i + 1], 则A[i + 1][1] = A[i][0] + money[i + 1].
// 实际上只需要两个变量保存结果就可以了，不需要用二维数组