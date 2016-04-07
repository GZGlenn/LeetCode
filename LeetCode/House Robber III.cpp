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

// pre����ǰ�ڵ㣨���ӣ���͵��ʱ�����ܻ�õ����棻
// ȡ�����ڸýڵ�������ӽڵ㱻͵��ʱ������֮�͡�
// curr����ǰ�ڵ㣨���ӣ�͵��ʱ�����ܻ�õ����棻
// �������ڽڵ㲻��ͬʱ͵��������������죬���������ӽڵ㲻��͵����
// ��ʱ������ڣ����ڵ�->val + ���ӽڵ�->pre + ���ӽڵ�->pre��
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

// ������Կ����Ǽ򵥵�DP���⣬��A[0]��ʾû��rob��ǰhouse�����money��
// A[1]��ʾrob�˵�ǰhouse�����money����ôA[0] ����rob����û��rob��һ��house�����ֵ
// ��A[i + 1][0] = max(A[i][0], A[i][1])..��ôrob��ǰ��house��
// ֻ�ܵ����ϴ�û��rob�� + money[i + 1], ��A[i + 1][1] = A[i][0] + money[i + 1].
// ʵ����ֻ��Ҫ���������������Ϳ����ˣ�����Ҫ�ö�ά����