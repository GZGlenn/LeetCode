#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (NULL == root) return;
		TreeLinkNode* curLev;
		while (root->left != NULL){
			curLev = root;
			while (curLev != NULL){
				curLev->left->next = curLev->right;
				if (curLev->next != NULL)
					curLev->right->next = curLev->next->left;
				curLev = curLev->next;
			}
			root = root->left;
		}
	}
};